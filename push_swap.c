#include <stdio.h>

#define PUSH_SWAP_IMPLEMENTATION
#include "push_swap.h"

int main(int argc, char *argv[]) {
    int i;
    int *numbers = NULL;

    int simple = 0;      // n^2
    int medium = 0;      // n√n
    int complex = 0;     // n log n
    int adaptive = 0;

    for (i = argc - 1; i > 0; --i) {
        if (ft_strncmp(argv[i], "--simple", ft_strlen("--simple")) == 0) simple = 1;
        if (ft_strncmp(argv[i], "--medium", ft_strlen("--medium")) == 0) medium = 1;
        if (ft_strncmp(argv[i], "--complex", ft_strlen("--complex")) == 0) complex = 1;
        if (ft_strncmp(argv[i], "--adaptive", ft_strlen("--adaptive")) == 0) adaptive = 1;
        arr_push(numbers, ft_atoi(argv[i]));
    }

    if (!simple && !medium && !complex) adaptive = 1;

    printf("\n");
    // for(size_t j = arr_len(numbers); j-- > 0; ) ft_printf("%d\n", numbers[j]);
    i = arr_len(numbers);
    while (i-- > 0) ft_printf("%d\n", numbers[i]);

    float disorder = compute_disorder(numbers);
    printf("\nDisorder : %f\n", disorder);


    ft_printf("\nFlags\n Simple : %d\n Medium : %d\n Complex : %d\n Adaptive : %d\n", simple, medium, complex, adaptive);

    arr_free(numbers);
    return 0;
}
