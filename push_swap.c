#include <stdio.h>

#define PUSH_SWAP_IMPLEMENTATION
#include "push_swap.h"

int main(int argc, char *argv[]) {
    int i;
    int *stack_a = NULL;
    int *stack_b = NULL;
    static t_state st;

    int simple;      // n^2
    int medium;      // n√n
    int complex;     // n log n
    int adaptive;
    int bench;

    st.ra_count = 0;
    st.rra_count = 0;
    st.rb_count = 0;
    st.rrb_count = 0;
    st.rr_count = 0;
    st.rrr_count = 0;
    st.pa_count = 0;
    st.pb_count = 0;
    st.sa_count = 0;
    st.sb_count = 0;
    st.ss_count = 0;
    st.total_count = 0;

    simple = 0;
    medium = 0;
    complex = 0;
    adaptive = 0;
    bench = 0;

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

    // printf("\nstack A :\n");
    // print_arr(stack_a);
    // printf("\n\n");

    // printf("\nDisorder : %f\n", disorder);
    // printf("\n\nDisorder : %d%%\n", (int)(disorder * 100));

    if (simple) selection_sort(stack_a, &stack_b, &st);
    if (medium) chunk_based_sort(stack_a, &stack_b, &st);
    if (complex) lsd_radix_sort(stack_a, &stack_b, &st);
    if (adaptive) {
        if (disorder < 0.2) insertion_sort(stack_a, &stack_b, &st);
        // else if (disorder >= 0.2 && disorder < 0.5) chunk_based_sort(stack_a, &stack_b);
        else if (disorder >= 0.2 && disorder < 0.5) return 1;
        // else lsd_radix_sort(stack_a, &stack_b);
        else return 1;
    }

    st.total_count = st.ra_count + st.rra_count + st.rb_count + st.rrb_count + st.pa_count + st.pb_count;

    if (bench) {
        ft_printf("[bench] disorder: %d%%\n", (int)(disorder * 100));
        ft_printf("[bench] strategy: %s\n", strategy_string);
        ft_printf("[bench] total_ops: %d\n", st.total_count);
        ft_printf("[bench] sa: %d sb: %d ss: %d pa : %d pb : %d\n", st.sa_count, st.sb_count, st.ss_count, st.pa_count, st.pb_count);
        ft_printf("[bench] ra: %d rb : %d rr : %d rra : %d rrb : %d rrr : %d\n", st.ra_count, st.rb_count, st.rr_count, st.rra_count, st.rrb_count, st.rrr_count);
    }

    // printf("\nstack A : \n");
    // print_arr(stack_a);

    arr_free(stack_a);
    if (stack_b)
        arr_free(stack_b);
    return 0;
}
