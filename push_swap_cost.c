/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:14:51 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 18:12:16 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_top_costa(t_ps **lst)
{
	int		i;
	int		j;
	t_ps	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	j = 0;
	while (tmp && ++j)
		tmp = tmp->next;
	tmp = *lst;
	while (tmp)
	{
		i = tmp->pos;
		if (i < (j / 2))
			tmp->cost_a = i;
		if (i >= (j / 2))
		{
			if ((j % 2 != 0) && (j / 2 == i))
				tmp->cost_a = (i);
			else
				tmp->cost_a = (-j + i);
		}
		tmp = tmp->next;
	}
}

void	ft_costa_tob(t_ps **lst, t_ps **lst2)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	tmp = *lst;
	tmp2 = *lst2;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp2->target_pos == tmp->pos)
			{
				tmp2->cost_a = tmp->cost_a;
			}
			tmp = tmp->next;
		}
		tmp = *lst;
		tmp2 = tmp2->next;
	}
}

void	ft_top_costb(t_ps **lst)
{
	int		i;
	int		j;
	t_ps	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	j = 0;
	while (tmp && ++j)
		tmp = tmp->next;
	tmp = *lst;
	while (tmp)
	{
		i = tmp->pos;
		if (i < (j / 2))
			tmp->cost_b = i;
		if (i >= (j / 2))
		{
			if ((j % 2 != 0) && (j / 2 == i))
				tmp->cost_b = (i);
			else
				tmp->cost_b = (-j + i);
		}
		tmp = tmp->next;
	}
}
