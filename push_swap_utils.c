#include "push_swap.h"

t_stack	*ps_lstprev(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*ps_lstnew(int value)
{
	struct s_stack	*ptr;

	ptr = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!ptr)
		return (NULL);
	ptr->prev = NULL;
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	printf("LAST\n");
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		// printf("lst:%p\n", lst);
		lst = lst->next;
	}
	// printf("lst:%p\n", lst);
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	struct s_stack *last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

void	print_stack(t_stack *stack, bool ab)
{
	t_stack	*probe;

	printf("\nPRINT STACK %s\n", (ab ? "A" : "B"));
	if (!stack)
		printf("\nSTACK B EMPTY\n");
	probe = stack;
	while (probe)
	{
		printf("\n");
		// printf("probe->prev:%p\n", probe->prev);
        printf("probe:%p\n", probe);
		printf("value:%d\n", probe->value);
		// printf("probe->next:%p\n", probe->next);
		probe = probe->next;
	}
	printf("\nEND PRINT STACK\n");
}