/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:47:56 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/07 12:49:40 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_past(char **av, int index)
{
	int	i;
	int	result;
	int	check;

	i = 1;
	result = 0;
	check = 0;
	while (i < index)
	{
		if (ft_atoi(av[i], &check) == ft_atoi(av[index], &check))
			result = 1;
		i++;
	}
	return (result);
}

int	check(char *av)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (av[i] == '-')
	{
		i++;
		if (av[i] == '\0')
			result = 1;
	}
	if (av[0] == '\0')
		result = 1;
	while (av[i])
	{
		if ((av[i] > '9' || av[i] < '0'))
			result = 1;
		i++;
	}
	return (result);
}

int	ft_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
	{
		len++;
	}
	return (len);
}

void	ft_simplify(t_struct *stack_a)
{
	int		i;
	t_pile	*temp;
	t_pile	*tempbis;

	temp = stack_a->top;
	while (temp)
	{
		tempbis = stack_a->top;
		i = 0;
		while (tempbis)
		{
			if (temp->data < tempbis->data && temp->data != tempbis->data)
				i++;
			tempbis = tempbis->next;
		}
		temp->data_simple = stack_a->size - i;
		temp = temp->next;
	}
	temp = stack_a->top;
	while (temp)
	{
		temp->data = temp->data_simple;
		temp = temp->next;
	}
}
