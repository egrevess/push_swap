#include "push_swap.h"

int	ft_last(t_struct *stack_a)
{
	t_pile	*current;
	int		i;

	current = stack_a->top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	if (current->data == 1 || current->data == 2)
		i = 0;
	else
		i = 1;
	return (i);
}

int	already_sorted(t_struct *stack_a)
{
	int		result;
	t_pile	*temp;
	int		i;

	result = 0;
	temp = stack_a->top;
	i = 0;
	while (temp)
	{
		if (temp->data <= i)
		{
			result = 1;
			break ;
		}
		i = temp->data ;
		temp = temp->next;
	}
	return (result);
}
