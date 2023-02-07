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

/*
void	sb(t_struct *stack)
{
	swap(stack);
	printf("sb\n");
}
*/

/*
void	ss(t_struct *stack_a, t_struct *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n");
}
*/

/*
void	rrb(t_struct *stack)
{
	reverse_rotate(stack);
	printf("rrb\n");
}
*/

void	pa(t_struct *stack_a, t_struct *stack_b)
{
	push(stack_b, stack_a);
	stack_a->size++;
	ft_printf("pa\n");
}
/*
void	rr(t_struct *stack_a, t_struct *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}

void	rrr(t_struct *stack_a, t_struct *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	printf("rrr\n");
}
*/

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

/*
void	rb(t_struct *stack)
{
	rotate(stack);
	printf("rb\n");
}
*/
