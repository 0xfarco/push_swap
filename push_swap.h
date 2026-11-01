#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

// declarations
float compute_disorder(int *arr);
int ft_atoi(const char *nptr);
size_t ft_strlen(const char *s);
void ft_putstr_fd(char *s, int fd);
int arr_pop(int *arr);
int	ft_handle_format(char specifier, va_list *args);
int	ft_print_char(char c);
int	ft_print_string(char *s);
int	ft_print_unsigned(unsigned int n);
int	ft_print_signed(int n);
int	ft_print_hex(unsigned long n, int uppercase);
int	ft_print_pointer(void *ptr);
int	ft_printf(const char *format, ...);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
// int sorted3(int *arr);
void ft_simple(int *arr1, int *arr2);
// double ft_sqrt(double x);
// void insertion_sort(int *arr);
// void medium(int *arr1, int *arr2);

typedef struct {
    size_t count;
    size_t capacity;
} Header;

#define ARR_INIT_CAPACITY 2

#define arr_push(arr, x)                                                                \
    do {                                                                                \
        if (arr == NULL) {                                                              \
            Header *header = malloc(sizeof(*arr) * ARR_INIT_CAPACITY + sizeof(Header)); \
            header->count = 0;                                                          \
            header->capacity = ARR_INIT_CAPACITY;                                       \
            arr = (void*)(header + 1);                                                  \
        }                                                                               \
        Header *header = (Header*)(arr) - 1;                                            \
        if (header->count >= header->capacity) {                                        \
            header->capacity *= 2;                                                      \
            header = realloc(header, sizeof(*arr) * header->capacity + sizeof(Header)); \
            arr = (void*)(header + 1);                                                  \
        }                                                                               \
        (arr)[header->count++] = (x);                                                   \
    } while (0)

#define arr_pop(arr) ({                         \
    Header *header = (Header *)(arr) - 1;       \
    int popped = -1;                            \
    if (header->count <= 0) {                   \
        ft_printf("ERROR: Stack Underflow!\n"); \
    } else {                                    \
        popped = (arr)[--header->count];        \
    }                                           \
    popped;                                     \
})

#define arr_len(arr) ((Header*)(arr) - 1)->count

#define arr_free(arr) free((Header*)(arr) - 1)

#define sorted3(arr)                                                                                                           \
    ({                                                                                                                         \
        Header *header = (Header *)(arr) - 1;                                                                                  \
        int t = header->count;                                                                                                 \
        int result = 0;                                                                                                        \
        if (*((arr) + t - 1) < *((arr) + t - 2) && *((arr) + t - 1) < *((arr) + t - 3) && *((arr) + t - 1) < *((arr) + t - 3)) \
            result = 1;                                                                                                        \
        result;                                                                                                                \
    })

#define print_arr(arr)                  \
    {                                   \
    int i = arr_len(arr);               \
        ft_printf("[ ");                \
        while (i-- > 0)                 \
            ft_printf("%d ", (arr)[i]); \
        ft_printf("]");                 \
    }

#define swap(arr)                              \
    do {                                       \
        Header *header = (Header *)arr - 1;    \
        int n = header->count;                 \
        if (n >= 2) {                          \
            typeof(*(arr)) tmp = (arr)[n - 1]; \
            (arr)[n - 1] = (arr)[n - 2];       \
            (arr)[n - 2] = tmp;                \
        }                                      \
    } while (0)

#define ss(arr1, arr2) \
    do {               \
        swap(arr1);    \
        swap(arr2);    \
    } while (0)

#define rotate(arr)                       \
{                                         \
    Header *header = (Header *)(arr) - 1; \
    int first = (arr)[header->count - 1]; \
    size_t i = header->count;             \
    while (i-- > 0) {                     \
        (arr)[i] = (arr)[i - 1];          \
    }                                     \
    (arr)[0] = first;                     \
}

#define rr(arr1, arr2) \
    {                  \
        rotate(arr1);  \
        rotate(arr2);  \
    }

#define rrotate(arr)                      \
{                                         \
    Header *header = (Header *)(arr) - 1; \
    int last = (arr)[0];                  \
    size_t i = 0;                         \
    while (i < header->count) {           \
        (arr)[i] = (arr)[i + 1];          \
        i++;                              \
    }                                     \
    (arr)[header->count - 1] = last;      \
}

#define rrr(arr1, arr2) \
    {                   \
        rrotate(arr1);  \
        rrotate(arr2);  \
    }

#ifdef PUSH_SWAP_IMPLEMENTATION

// implementations

float compute_disorder(int *arr) {
    int mistakes;
    int total_pairs;
    size_t i;
    size_t j;
    size_t sz;

    mistakes = 0;
    total_pairs = 0;
    i = 0;
    sz = arr_len(arr);
    while (i < sz) {
        j = i + 1;
        while (j < sz) {
            total_pairs++;
            if (arr[i] < arr[j]) mistakes++;
            j++;
        }
        i++;
    }
    return ((float)mistakes / total_pairs);
}

// int sorted3(int *arr) {
//     int t = arr_len(arr);
//     // ft_printf("\n\n%d - %d - %d\n\n", *(arr + t - 1), *(arr + t - 2), *(arr + t - 3));
//     return (*(arr + t - 1) < *(arr + t - 2) && *(arr + t - 1) < *(arr + t - 3) && *(arr + t - 1) < *(arr + t - 3));
// }

// void selection_sort(int a[], int N) {
//     int i, j, min, t;
//     for (i = 0; i < N - 1; i++) {
//         min = i;
//         for (j = i + 1; j < N; j++) {
//             if (a[j] < a[min])
//                 min = j;
//         }
//         t = a[min];
//         a[min] = a[i];
//         a[i] = t;
//     }
// }

// simple - selection sort
void ft_simple(int *arr1, int *arr2) {
    int i;
    int N;
    size_t min_idx;
    Header *header = (Header *)arr1 - 1;

    while (header->count > 0) {
        N = header->count;
        min_idx = 0;
        i = 1;

        while (i < N) {
    	    if (arr1[i] < arr1[min_idx]) min_idx = i;
            i++;
    	}

        size_t t = min_idx;
        if (t <= (size_t)N / 2)
        {
            while (arr1[t] != arr1[header->count - 1])
            {
                rrotate(arr1);
                ft_printf("RRA\n");
                t = (t - 1 + header->count) % header->count;
                // printf("\nstack A : \n");
                // print_arr(arr1);
            }
        }
        else
        {
            while (arr1[t] != arr1[header->count - 1])
            {
                rotate(arr1);
                ft_printf("RA\n");
                t = (t + 1) % header->count;
                // printf("\nstack A : \n");
                // print_arr(arr1);
            }
        }


        int value = arr1[header->count - 1];

    	arr_push(arr2, value);
        printf("PB\n");
        // printf("\nstack B : \n");
        // print_arr(arr2);
    	arr_pop(arr1);
        // printf("\nstack A : \n");
        // print_arr(arr1);
        // printf("--------------------\n");
    }

    while (arr_len(arr2) > 0)
    {
        arr_push(arr1, arr2[arr_len(arr2) - 1]);
        arr_pop(arr2);
    }
}

int *arr_dup(int *arr) {
    Header *header = (Header*)arr - 1;
    size_t count = header->count;
    int *dup = NULL;
    size_t i = 0;
    while (i < count) {
        arr_push(dup, arr[i]);
        i++;
    }

    return dup;
}

// double ft_sqrt(double x)
// {
//     double y;
//     int p,square,c;
//
//     /* find the surrounding perfect squares */
//     p = 0;
//     do
//     {
//         p++;
//         square = (p+1) * (p+1);
//     }
//     while( x > square );
//
//     /* process the root */
//     y = (double)p;
//     c = 0;
//     while(c<10)
//     {
//         /* divide and average */
//         y = (x/y + y)/2;
//         /* test for success */
//         if( y*y == x)
//             return(y);
//         c++;
//     }
//     return(y);
// }

// insertion sort
// void insertion_sort(int *arr)
// {
//     int i;
//     int j;
//     int key;
//
//     Header *header = (Header*)arr - 1;
//
//     int size = header->count;
//
//     i = 1;
//     while (i < size)
//     {
//         key = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//         i++;
//     }
// }

// medium - chunked merge sort
// void medium(int *arr1, int *arr2) {
//     int *dup = arr_dup(arr1);
//     insertion_sort(dup);
//     print_arr(dup);
//     (void) arr2;
//     // int chunk_size = N % 2 == 0 ? ft_sqrt(N) : ft_sqrt(N + 1);
//
// }

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(result * sign));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_hex(unsigned long n, int uppercase)
{
	const char	*hex;
	int			count;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, uppercase);
	count += ft_print_char(hex[n % 16]);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_print_string("(nil)"));
	count = ft_print_string("0x");
	count += ft_print_hex((unsigned long)ptr, 0);
	return (count);
}

int	ft_print_signed(int n)
{
	unsigned int	num;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		num = -(unsigned int)n;
	}
	else
		num = (unsigned int)n;
	return (count + ft_print_unsigned(num));
}

int	ft_print_string(char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count])
	{
		ft_print_char(s[count]);
		count++;
	}
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += ft_print_char('0' + n % 10);
	return (count);
}

int	ft_handle_format(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_print_char((char)va_arg(*args, int)));
	if (specifier == 's')
		return (ft_print_string(va_arg(*args, char *)));
	if (specifier == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_signed(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), specifier == 'X'));
	if (specifier == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			count += ft_handle_format(*format, &args);
		}
		else if (*format != '%')
			count += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

#endif // PUSH_SWAP_IMPLEMENTATION
#endif // PUSH_SWAP_H
