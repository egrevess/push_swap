/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:50:12 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/07 11:50:13 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_little(t_struct *stack_a)
{
	while (already_sorted(stack_a) != 0)
	{
		if (stack_a->top->data > stack_a->top->next->data)
		{
			sa(stack_a);
		}
		if (stack_a->size > 2
			&& stack_a->top->next->data > stack_a->top->next->next->data)
		{
			rra(stack_a);
		}
	}
}

void	ft_sort_big(t_struct *stack_a, t_struct *stack_b)
{
	int	last;

	if (already_sorted(stack_a) == 0)
		return ;
	last = ft_last(stack_a);
	while (stack_a->top->data != 1)
	{
		if (last == 1)
			ra(stack_a);
		else if (last == 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	while (stack_a->top->data != 2)
	{
		if (last == 1)
			ra(stack_a);
		else if (last == 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	ft_sort_little(stack_a);
	while (stack_b->top != NULL)
		pa(stack_a, stack_b);
}

static int	get_iteration(t_struct *stack_a)
{
	t_pile	*temp;
	int		max_ite;
	int		max;

	temp = stack_a->top;
	max = temp->data;
	max_ite = 0;
	while (temp)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	while ((max >> max_ite) != 0)
		max_ite++;
	return (max_ite);
}

static void	radix(t_struct *stack_a, t_struct *stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	value;

	size = stack_a->size;
	max_bits = get_iteration(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			value = stack_a->top->data;
			if (((value >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_b->top != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}

void	ft_algo(t_struct *stack_a, t_struct *stack_b)
{
	ft_simplify(stack_a);
	if (already_sorted(stack_a) == 0)
		return ;
	if (stack_a->size <= 3)
		ft_sort_little(stack_a);
	else if (stack_a->size <= 5)
		ft_sort_big(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
