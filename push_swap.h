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

#define arr_pop(arr) ({                      \
    Header *header = (Header *)(arr) - 1;    \
    int popped = -1;                         \
    if (header->count <= 0) {                \
        printf("ERROR: Stack Underflow!\n"); \
    } else {                                 \
        popped = (arr)[--header->count];     \
    }                                        \
    popped;                                  \
})

#define arr_len(arr) ((Header*)(arr) - 1)->count

#define arr_free(arr) free((Header*)(arr) - 1)


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
    // printf("%d / %d = %f\n", mistakes, total_pairs, total_pairs ? (float)mistakes / total_pairs : 0.0f);
    return ((float)mistakes / total_pairs);
}

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
