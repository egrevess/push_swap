/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:47:52 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/07 13:02:35 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*push_stack(int number, t_struct *var)
{
	t_pile	*new_pile;

	new_pile = malloc(sizeof(*new_pile));
	new_pile->data = number;
	new_pile->next = var->top;
	var->top = new_pile;
	var->size++;
	return (new_pile);
}

void	printf_pile(t_struct *var)
{
	t_pile	*current;

	current = var->top;
	printf("pile : ");
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
}

t_struct	*stack_init(void)
{
	t_struct	*new;

	new = malloc(sizeof(*new));
	if (!new)
		exit(EXIT_FAILURE);
	new->top = NULL;
	new->size = 0;
	return (new);
}

int	ft_check_stack(char **tab, int i, t_struct *stack_a, int ac)
{
	int	check_;

	check_ = 0;
	while (i >= ac)
	{
		if (check(tab[i]) == 0 && check_past(tab, i) == 0)
		{
			ft_atoi(tab[i], &check_);
			if (check_)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			push_stack(ft_atoi(tab[i], &check_), stack_a);
		}
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i--;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_struct	*stack_b;
	t_struct	*stack_a;
	t_outils	s;		

	stack_a = stack_init();
	stack_b = stack_init();
	stack_a->size = 0;
	if (ac >= 2)
	{
		if (ac == 2)
		{
			s.tab = ft_split(av[1], ' ');
			s.i = ft_len(s.tab) - 1;
			s.return_value = ft_check_stack(s.tab, s.i, stack_a, 0);
			ft_free(s.tab);
		}
		if (ac > 2)
			s.return_value = ft_check_stack(av, ac - 1, stack_a, 1);
		if (s.return_value == 0)
			return (0);
		ft_algo(stack_a, stack_b);
	}
	return (0);
}
