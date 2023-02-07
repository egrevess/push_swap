/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:47:47 by egrevess          #+#    #+#             */
/*   Updated: 2023/02/07 12:47:48 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_pile
{
	int				data;
	int				data_simple;
	struct s_pile	*next;
}					t_pile;

typedef struct s_struct
{
	t_pile	*top;
	int		size;
}			t_struct;

typedef struct s_outils
{
	int		i;
	int		return_value;
	char	**tab;

}			t_outils;

int		check(char *av);
int		check_past(char **av, int index);
void	swap(t_struct *var);
void	printf_pile(t_struct *var);
void	rotate(t_struct *var);
void	reverse_rotate(t_struct *stack);
void	push(t_struct *stack_a, t_struct *stack_b);
void	rra(t_struct *stack);
void	sa(t_struct *stack);
void	pa(t_struct *stack_a, t_struct *stack_b);
void	pb(t_struct *stack_a, t_struct *stack_b);
void	ra(t_struct *stack);
char	**ft_split(char const *s, char c);
void	ft_algo(t_struct *stack_a, t_struct *stack_b);
void	ft_simplify(t_struct *stack_a);
int		ft_len(char **tab);
int		ft_atoi(const char *str, int *check);
int		ft_last(t_struct *stack_a);
int		already_sorted(t_struct *stack_a);
void	ft_free_arr(t_struct *stack_a, t_struct *stack_b);
void	ft_free(char **tab);

#endif