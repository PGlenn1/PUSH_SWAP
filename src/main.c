#include "../includes/push_swap.h"

int	push_swap(char **input)
{
	t_root	*root;

	root = init_root(input);
	if (root->stack_a->order == INCREASING)
		ft_free_all(root);
	sort_stacks(root);
	if (final_is_sorted(root))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	if (push_swap(argv))
		return (0);
	return (1);
}