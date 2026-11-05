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
    int bench = 0;

    for (i = argc - 1; i > 0; --i) {
        if (ft_strncmp(argv[i], "--simple", ft_strlen("--simple")) == 0) simple = 1;
        if (ft_strncmp(argv[i], "--medium", ft_strlen("--medium")) == 0) medium = 1;
        if (ft_strncmp(argv[i], "--complex", ft_strlen("--complex")) == 0) complex = 1;
        if (ft_strncmp(argv[i], "--adaptive", ft_strlen("--adaptive")) == 0) adaptive = 1;
        if (ft_strncmp(argv[i], "--bench", ft_strlen("--bench")) == 0) bench = 1;
        if (ft_strncmp(argv[i], "--", 2) != 0) {
            if (!ft_atoi(argv[i])) {
                ft_printf("Error\n");
                return 1;
            }
            arr_push(stack_a, ft_atoi(argv[i]));
        }
    }

    if (!simple && !medium && !complex) adaptive = 1;

    float disorder = compute_disorder(stack_a);
    if (!disorder)
        return 0;

    char *strategy_string;
    if (simple) strategy_string = "Simple / O(n)";
    if (medium) strategy_string = "Medium / O(n√n)";
    if (complex) strategy_string = "Complex / O(nlogn)";
    if (adaptive) {
        if (disorder < 0.2) strategy_string = "Adaptive / O(n)";
        if (disorder <= 0.2 && disorder < 0.5) strategy_string = "Adaptive / O(n√n)";
        if (disorder >= 0.5) strategy_string = "Adaptive / O(nlogn)";
    }

    printf("\nstack A :\n");
    print_arr(stack_a);
    printf("\n\n");

    // printf("\nDisorder : %f\n", disorder);
    // printf("\n\nDisorder : %d%%\n", (int)(disorder * 100));

    if (simple) selection_sort(stack_a, &stack_b);
    if (medium) chunk_based_sort(stack_a, &stack_b);
    if (complex) lsd_radix_sort(stack_a, &stack_b);
    if (adaptive) {
        if (disorder < 0.2) insertion_sort(stack_a, &stack_b);
        // else if (disorder >= 0.2 && disorder < 0.5) chunk_based_sort(stack_a, &stack_b);
        else if (disorder >= 0.2 && disorder < 0.5) return 1;
        // else lsd_radix_sort(stack_a, &stack_b);
        else return 1;
    }
    if (bench) {
        ft_printf("[bench] disorder: %d%%\n", disorder);
        ft_printf("[bench] strategy: %s", strategy_string);
        // ft_printf("[bench] total_ops: %d", total_ops);
        // ft_printf("[bench] sa: %d sb: %d ss: %d pa : %d pb : %d\n", sa_count, sb_count, ss_count, pa_count, pb_count);
        // ft_printf("[bench] ra: %d rb : %d rr : %d rra : %d rrb : %d rrr : %d\n". ra_count, rb_count, rr_count, rra_count, rrb_count, rrr_count);
    }

    printf("\nstack A : \n");
    print_arr(stack_a);

    arr_free(stack_a);
    if (stack_b)
        arr_free(stack_b);
    return 0;
}
