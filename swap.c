/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:47:35 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/07 12:47:36 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_struct *var)
{
	int	temp;

	temp = var->top->data;
	var->top->data = var->top->next->data;
	var->top->next->data = temp;
}

void	rotate(t_struct *var)
{
	t_pile	*current;
	t_pile	*temp;

	temp = var->top;
	var->top = var->top->next;
	current = var->top;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->next = 0;
}

void	push(t_struct *stack_a, t_struct *stack_b)
{
	t_pile	*temp;

	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_b->top;
	stack_b->top = temp;
}

void	reverse_rotate(t_struct *stack)
{
	t_pile	*current;
	t_pile	*temp;

	current = stack->top;
	while (current->next->next)
	{
		current = current->next;
	}
	temp = current->next;
	current->next = 0;
	temp->next = stack->top;
	stack->top = temp;
}
