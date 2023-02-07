/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:47:43 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/07 12:47:44 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	rra(t_struct *stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	sa(t_struct *stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	pa(t_struct *stack_a, t_struct *stack_b)
{
	push(stack_b, stack_a);
	stack_a->size++;
	ft_printf("pa\n");
}

void	pb(t_struct *stack_a, t_struct *stack_b)
{
	push(stack_a, stack_b);
	stack_a->size--;
	ft_printf("pb\n");
}

void	ra(t_struct *stack)
{
	rotate(stack);
	ft_printf("ra\n");
}
