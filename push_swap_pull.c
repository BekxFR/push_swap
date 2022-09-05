/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:15:03 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 18:12:27 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pull_rest(t_ps **stack, t_ps **stack2, int count, int argc)
{
	t_ps	*tmp;

	tmp = *stack;
	while (count < argc - 3)
	{
		ft_pb(stack, stack2);
		ft_printf("pb\n");
		tmp = *stack;
		tmp = tmp->next;
		count++;
	}
}

void	ft_pull_lowtob(t_ps **stack, t_ps **stack2, int argc)
{
	t_ps	*tmp;
	int		count;

	tmp = *stack;
	count = 0;
	while (count != argc / 2 - 1)
	{
		if (tmp->index <= argc / 2 && count++ != argc / 2)
		{
			ft_pb(stack, stack2);
			ft_printf("pb\n");
		}
		else
		{
			ft_ra(stack);
			ft_printf("ra\n");
		}
		tmp = *stack;
	}
	if (tmp->next->next->next)
		ft_pull_rest(stack, stack2, count, argc);
}
