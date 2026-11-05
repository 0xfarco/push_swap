#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdarg.h>
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
int *arr_dup(int *arr);
double ft_sqrt(double x);
float compute_disorder(int *arr);
static int rank_of(int *sorted, int n, int v);
static int count_below(int *a, int limit);
void countsort(int arr[], int n);
void insertionSort(int arr[], int left, int right);
int search_elem(int *a, int elem);


typedef struct {
    size_t count;
    size_t capacity;
} Header;

typedef struct s_state {
    size_t ra_count;
    size_t rra_count;
    size_t rb_count;
    size_t rrb_count;
    size_t rr_count;
    size_t rrr_count;
    size_t pa_count;
    size_t pb_count;
    size_t sa_count;
    size_t sb_count;
    size_t ss_count;
    size_t total_count;
} t_state;

static void op_ra(int *a, t_state *st);
static void op_rra(int *a, t_state *st);
static void op_rb(int *b, t_state *st);
static void op_rrb(int *b, t_state *st);
static void op_pb(int **a, int **b, t_state *st);
static void op_pa(int **a, int **b, t_state *st);

void selection_sort(int *a, int **b, t_state *st);
void insertion_sort(int *a, int **b, t_state *st);
static void push_chunk(int **a, int **b, int limit, int chunk, t_state *st);
static void pull_back(int **a, int **b, t_state *st);
void chunk_based_sort(int *a, int **b, t_state *st);
static void radix_pass(int **a, int **b, int bit, t_state *st);
void ls_radix_sort(int *a, int **b, t_state *st);

#define ARR_INIT_CAPACITY 2

#ifndef CHUNK_MUL
# define CHUNK_MUL 25   /* chunk size = sqrt(n) * CHUNK_MUL / 10 (2.5 * sqrt(n)) */
#endif

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

#define rotate(arr)                           \
{                                             \
    Header *header = (Header *)(arr) - 1;     \
    if (header->count > 1) {                  \
        int first = (arr)[header->count - 1]; \
        size_t i = header->count - 1;         \
        while (i > 0) {                       \
            (arr)[i] = (arr)[i - 1];          \
            i--;                              \
        }                                     \
        (arr)[0] = first;                     \
    }                                         \
}

#define rr(arr1, arr2) \
    {                  \
        rotate(arr1);  \
        rotate(arr2);  \
    }

#define rrotate(arr)                          \
{                                             \
    Header *header = (Header *)(arr) - 1;     \
    if (header->count > 1) {                  \
        int last = (arr)[0];                  \
        size_t i = 0;                         \
        while (i + 1 < header->count) {       \
            (arr)[i] = (arr)[i + 1];          \
            i++;                              \
        }                                     \
        (arr)[header->count - 1] = last;      \
    }                                         \
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

int search_elem(int *a, int elem) {
    size_t i;
    Header *header;
    size_t sz;

    i = 0;
    header = (Header*)a - 1;
    sz = header->count;
    while (i < sz) {
        if (a[i] == elem) {
            ft_printf("Error\n");
            return 1;
        }
    }

    return 0;
}

static void op_ra(int *a, t_state *st)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
    st->ra_count++;
}

static void op_rra(int *a, t_state *st)
{
    rrotate(a);
    ft_putstr_fd("rra\n", 1);
    st->rra_count++;
}

static void op_rb(int *b, t_state *st)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1);
    st->rb_count++;
}

static void op_rrb(int *b, t_state *st)
{
    rrotate(b);
    ft_putstr_fd("rrb\n", 1);
    st->rrb_count++;
}

static void op_pb(int **a, int **b, t_state *st)
{
    int v;

    v = arr_pop(*a);
    arr_push(*b, v);
    ft_putstr_fd("pb\n", 1);
    st->pb_count++;
}

static void op_pa(int **a, int **b, t_state *st)
{
    int v;

    v = arr_pop(*b);
    arr_push(*a, v);
    ft_putstr_fd("pa\n", 1);
    st->pa_count++;
}

// simple strategy
void selection_sort(int *a, int **b, t_state *st)
{
    int n;
    int i;
    int min_i;
    int up;
    int down;

    if (arr_len(a) < 2)
        return ;
    while (arr_len(a) > 0)
    {
        n = (int)arr_len(a);
        min_i = 0;
        i = 1;
        while (i < n)
        {
            if (a[i] < a[min_i])
                min_i = i;
            i++;
        }
        up = n - 1 - min_i;
        down = min_i + 1;
        if (up <= down)
            while (up-- > 0) {
                op_ra(a, st);
            }
        else
            while (down-- > 0) {
                op_rra(a, st);
            }
        op_pb(&a, b, st);
    }
    while (*b && arr_len(*b) > 0) {
        op_pa(&a, b, st);
    }
}

// simple strategy - adaptive
void insertion_sort(int *a, int **b, t_state *st)
{
    int n;
    int b_sz;
    int value;

    op_pb(&a, b, st);
    n = arr_len(a);

    while (n > 0)
    {
        op_pb(&a, b, st);
        b_sz = arr_len(*b);

        if (b_sz > 1)
        {
            value = (*b)[0];

            while (b_sz > 1 && (*b)[1] > value)
            {
                op_rb(*b, st);
                b_sz = arr_len(*b);
            }

            op_rrb(*b, st);
        }
        n--;
    }

    while (*b && arr_len(*b) > 0) {
        op_pa(&a, b, st);
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

double ft_sqrt(double x)
{
    double y;
    int p,square,c;

    p = 0;
    do
    {
        p++;
        square = (p+1) * (p+1);
    }
    while( x > square );

    y = (double)p;
    c = 0;
    while(c<10)
    {
        y = (x/y + y)/2;
        if( y*y == x)
            return(y);
        c++;
    }
    return(y);
}

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static int rank_of(int *sorted, int n, int v)
{
    int lo;
    int hi;
    int mid;

    lo = 0;
    hi = n - 1;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (sorted[mid] < v)
            lo = mid + 1;
        else
            hi = mid;
    }
    return (lo);
}

static int count_below(int *a, int limit)
{
    int i;
    int n;
    int c;

    i = 0;
    c = 0;
    n = (int)arr_len(a);
    while (i < n)
    {
        if (a[i] < limit)
            c++;
        i++;
    }
    return (c);
}

static void push_chunk(int **a, int **b, int limit, int chunk, t_state *st)
{
    int left;
    int n;
    int up;
    int down;
    int v;

    left = count_below(*a, limit);
    while (left-- > 0)
    {
        n = (int)arr_len(*a);
        up = 0;
        while ((*a)[n - 1 - up] >= limit)
            up++;
        down = 0;
        while ((*a)[down] >= limit)
            down++;
        down++;
        if (up <= down)
            while (up-- > 0) {
                op_ra(*a, st);
            }
        else
            while (down-- > 0) {
                op_rra(*a, st);
            }
        v = (*a)[(int)arr_len(*a) - 1];
        op_pb(a, b, st);
        if (v < limit - chunk / 2 && arr_len(*b) > 1) {
            op_rb(*b, st);
        }
    }
}

static void pull_back(int **a, int **b, t_state *st)
{
    int n;
    int i;
    int max_i;
    int up;
    int down;

    while (arr_len(*b) > 0)
    {
        n = (int)arr_len(*b);
        i = 1;
        max_i = 0;
        while (i < n)
        {
            if ((*b)[i] > (*b)[max_i])
                max_i = i;
            i++;
        }
        up = n - 1 - max_i;
        down = max_i + 1;
        if (up <= down)
            while (up-- > 0) {
                op_rb(*b, st);
            }
        else
            while (down-- > 0) {
                op_rrb(*b, st);
            }
        op_pa(a, b, st);
    }
}

// medium strategy
// void chunk_based_sort(int *a, int **b)
// {
//     int n;
//     int *sorted;
//     int chunk;
//     int limit;
//     int i;
//
//     n = (int)arr_len(a);
//     if (n < 2)
//         return ;
//     sorted = arr_dup(a);
//     insertionSort(sorted, 0, n - 1);
//     i = 0;
//     while (i < n)
//     {
//         a[i] = rank_of(sorted, n, a[i]);
//         i++;
//     }
//     chunk = (int)ft_sqrt(n) * CHUNK_MUL / 10;
//     if (chunk < 1)
//         chunk = 1;
//     limit = chunk;
//     while (arr_len(a) > 0)
//     {
//         push_chunk(&a, b, limit, chunk);
//         limit += chunk;
//     }
//     pull_back(&a, b);
//     i = 0;
//     while (i < n)
//     {
//         a[i] = sorted[a[i]];
//         i++;
//     }
//     arr_free(sorted);
// }

void chunk_based_sort(int *a, int **b, t_state *st)
{
    int n;
    int *sorted;
    int chunk;
    int limit;
    int i;

    n = (int)arr_len(a);
    if (n < 2)
        return ;
    sorted = arr_dup(a);
    insertionSort(sorted, 0, n - 1);
    i = 0;
    while (i < n)
    {
        a[i] = rank_of(sorted, n, a[i]);
        i++;
    }
    chunk = (int)ft_sqrt(n) * CHUNK_MUL / 10;
    if (chunk < 1)
        chunk = 1;
    limit = chunk;
    while (arr_len(a) > 0)
    {
        push_chunk(&a, b, limit, chunk, st);
        limit += chunk;
    }
    pull_back(&a, b, st);
    i = 0;
    while (i < n)
    {
        a[i] = sorted[a[i]];
        i++;
    }
    arr_free(sorted);
}

void countsort(int arr[], int n) {
    int maxval = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxval) {
            maxval = arr[i];
        }
    }

    int* cntArr = (int*)calloc(maxval + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        cntArr[arr[i]]++;
    }

    for (int i = 1; i <= maxval; i++) {
        cntArr[i] += cntArr[i - 1];
    }

    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        ans[cntArr[arr[i]] - 1] = arr[i];
        cntArr[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }

    free(cntArr);
    free(ans);
}

static void radix_pass(int **a, int **b, int bit, t_state *st)
{
    int n;
    int i;

    n = (int)arr_len(*a);
    i = 0;
    while (i < n)
    {
        if (((*a)[(int)arr_len(*a) - 1] >> bit) & 1)
            op_ra(*a, st);
        else
            op_pb(a, b, st);
        i++;
    }
    while (arr_len(*b) > 0)
        op_pa(a, b, st);
}

// complex strategy
void lsd_radix_sort(int *a, int **b, t_state *st)
{
    int n;
    int *sorted;
    int bits;
    int i;

    n = (int)arr_len(a);
    if (n < 2)
        return ;
    sorted = arr_dup(a);
    countsort(sorted, n);
    i = 0;
    while (i < n)
    {
        a[i] = rank_of(sorted, n, a[i]);
        i++;
    }
    bits = 0;
    while (((n - 1) >> bits) != 0)
        bits++;
    i = 0;
    while (i < bits)
    {
        radix_pass(&a, b, i, st);
        i++;
    }
    i = 0;
    while (i < n)
    {
        a[i] = sorted[a[i]];
        i++;
    }
    arr_free(sorted);
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
