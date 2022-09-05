/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:15:39 by chillion          #+#    #+#             */
/*   Updated: 2022/09/05 13:02:45 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_trio_list(t_ps **stack, int argc)
{
	t_ps	*tmp;

	tmp = *stack;
	argc = 0;
	while (tmp)
	{
		if (argc < tmp->index)
			argc = tmp->index;
		tmp = tmp->next;
	}
	if ((*stack)->index == argc)
	{
		ft_ra(stack);
		ft_printf("ra\n");
	}
	if ((*stack)->next->index == argc)
	{
		ft_rra(stack);
		ft_printf("rra\n");
	}
	if ((*stack)->index > (*stack)->next->index)
	{
		ft_sa(stack);
		ft_printf("sa\n");
	}
}

void	ft_order_rest(t_ps **lst)
{
	int		i;
	t_ps	*tmp;

	tmp = *lst;
	i = ft_find_index(lst);
	while (tmp && tmp->index != i)
		tmp = tmp->next;
	i = tmp->cost_a;
	tmp = *lst;
	while (i != 0)
	{
		if (i < 0)
		{
			ft_printf("rra\n");
			ft_rra(lst);
			i = i + 1;
		}
		if (i > 0)
		{
			ft_printf("ra\n");
			ft_ra(lst);
			i = i - 1;
		}
	}
}

void	tri_for_more3(t_ps **stack, t_ps **stack2, int argc)
{
	ft_index_list(stack);
	ft_pull_lowtob(stack, stack2, argc - 1);
	ft_trio_list(stack, argc);
	ft_pos_lst(stack, stack2);
	ft_targpos_lst(stack, stack2, argc);
	while (*stack2)
	{
		ft_top_costa(stack);
		ft_top_costb(stack2);
		ft_costa_tob(stack, stack2);
		ft_choice_elem(stack, stack2);
		ft_pos_lst(stack, stack2);
		ft_targpos_lst(stack, stack2, argc);
	}
	ft_pos_lst(stack, stack2);
	ft_top_costa(stack);
	ft_order_rest(stack);
}

void	ft_tri_list(t_ps **stack, t_ps **stack2, int argc)
{
	if (argc == 3 && (*stack)->data > (*stack)->next->data)
	{
		ft_printf("sa\n");
		ft_sa(stack);
	}
	if (argc == 4)
	{
		ft_index_list(stack);
		ft_trio_list(stack, argc);
	}
	if (argc > 4)
	{
		tri_for_more3(stack, stack2, argc);
	}
	ft_clean_lst(stack);
	ft_clean_lst(stack2);
}

int	main(int argc, char **argv)
{
	int		j;
	t_ps	*stack;
	t_ps	*stack2;

	stack = NULL;
	stack2 = NULL;
	j = -1;
	if (argc >= 2)
	{
		while (++j < argc - 1)
		{
			ft_control_list(&stack, argv[j + 1], argc - 1);
			if (!stack)
				return (0);
		}
		if (ft_tried_list(&stack) == 0 && stack)
		{
			ft_clean_lst(&stack);
		}
		if (stack)
			ft_tri_list(&stack, &stack2, argc);
	}	
	return (0);
}
