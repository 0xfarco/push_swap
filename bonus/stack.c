/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcholakk <fcholakk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:42:37 by fcholakk          #+#    #+#             */
/*   Updated: 2026/11/11 13:34:27 by fcholakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	stack_init(t_stack *s, int cap)
{
	s->size = 0;
	s->data = malloc(sizeof(int) * cap);
	return (s->data != NULL);
}

void	stack_push(t_stack *s, int v)
{
	s->data[s->size] = v;
	s->size++;
}

int	stack_pop(t_stack *s)
{
	s->size--;
	return (s->data[s->size]);
}

int	stack_top(t_stack *s)
{
	return (s->data[s->size - 1]);
}

void stack_print(t_stack s)        
{                            
	int i = s.size;
    ft_putstr_fd("[ ", 1);   
    while (i-- > 0) {        
        ft_putnbr_fd(s.data[i], 1); 
        ft_putstr_fd(" ", 1);
    }                        
    ft_putstr_fd("]", 1);    
}