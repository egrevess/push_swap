/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:48:17 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/07 12:57:19 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_arr(t_struct *stack_a, t_struct *stack_b)
{
	t_pile	*data;
	t_pile	*temp;

	data = stack_a->top;
	while (data)
	{
		temp = data;
		data = data->next;
		free(temp);
	}
	free(stack_a);
	free(stack_b);
}
