#include <stdio.h>

#define PUSH_SWAP_IMPLEMENTATION
#include "push_swap.h"

/*
    functions / definitions :
    arr_push(stack_a, 6);
    int popped = arr_pop(stack_a);
    arr_len(arr);
    arr_free(arr);
    print_arr(stack_a);
    swap(arr);
    ss(arr1, arr2);
    rotate(stack_a);
    rr(arr1, arr2);
    rrotate(stack_a);
    rrr(arr1, arr2);
*/

int main(int argc, char *argv[]) {
    int i;
    int *stack_a = NULL;
    int *stack_b = NULL;

    int simple = 0;      // n^2
    int medium = 0;      // n√n
    int complex = 0;     // n log n
    int adaptive = 0;

    for (i = argc - 1; i > 0; --i) {
        if (ft_strncmp(argv[i], "--simple", ft_strlen("--simple")) == 0) simple = 1;
        if (ft_strncmp(argv[i], "--medium", ft_strlen("--medium")) == 0) medium = 1;
        if (ft_strncmp(argv[i], "--complex", ft_strlen("--complex")) == 0) complex = 1;
        if (ft_strncmp(argv[i], "--adaptive", ft_strlen("--adaptive")) == 0) adaptive = 1;
        arr_push(stack_a, ft_atoi(argv[i]));
    }

    if (!simple && !medium && !complex) adaptive = 1;

    // print stack
    // printf("\nstack :\n");
    // print_arr(stack_a);
    // printf("\n\n");



    // print disorder
    float disorder = compute_disorder(stack_a);
    if (!disorder)
        return 0;

    // printf("\nDisorder : %f\n", disorder);
    // printf("\n\nDisorder : %d%%\n", (int)(disorder * 100));

    ft_simple(stack_a, stack_b);
    // printf("\n stack a : \n");
    // print_arr(stack_a);

    // ft_printf("\n\nStrategy:\n- Simple : %d\n- Medium : %d\n- Complex : %d\n- Adaptive : %d\n", simple, medium, complex, adaptive);

    arr_free(stack_a);
    return 0;
}
