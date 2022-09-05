/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_switch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:15:13 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 18:12:33 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_switch_costa(t_ps **lst, t_ps **lst2, int j, int k)
{
	while (j != 0)
	{
		if (j < 0 && k < 0)
		{
			ft_switch_rrr(lst, lst2);
			j = j + 1;
			k = k + 1;
		}
		else if (j > 0 && k > 0)
		{
			ft_switch_rr(lst, lst2);
			j = j - 1;
			k = k - 1;
		}
		else if (j < 0)
			j = ft_switch_rra(lst, j);
		else if (j > 0)
			j = ft_switch_ra(lst, j);
	}
	return (k);
}

void	ft_switch_costb(t_ps **lst2, int k)
{
	while (k != 0)
	{
		if (k < 0)
		{
			ft_printf("rrb\n");
			ft_rrb(lst2);
			k = k + 1;
		}
		else if (k > 0)
		{
			ft_printf("rb\n");
			ft_rb(lst2);
			k = k - 1;
		}
	}
}

void	ft_choice_elem(t_ps **lst, t_ps **lst2)
{
	int		i;
	int		j;
	int		k;
	t_ps	*tmp2;

	i = ft_low_count(lst2);
	tmp2 = *lst2;
	j = 0;
	k = 0;
	tmp2 = *lst2;
	while (tmp2)
	{
		if (i == ft_low_counter(&tmp2))
		{
			j = tmp2->cost_a;
			k = tmp2->cost_b;
			k = ft_switch_costa(lst, lst2, j, k);
			ft_switch_costb(lst2, k);
			ft_printf("pa\n");
			ft_pa(lst, lst2);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

int	ft_low_count(t_ps **lst2)
{
	int		i;
	int		j;
	t_ps	*tmp2;

	tmp2 = *lst2;
	j = 9999;
	i = 0;
	while (tmp2)
	{
		if (tmp2->cost_a < 0 && tmp2->cost_b < 0)
			i = (tmp2->cost_a * -1) + (tmp2->cost_b * -1);
		else if (tmp2->cost_a < 0 && tmp2->cost_b >= 0)
			i = (tmp2->cost_a * -1) + tmp2->cost_b;
		else if (tmp2->cost_b < 0 && tmp2->cost_a >= 0)
			i = (tmp2->cost_b * -1) + tmp2->cost_a;
		else
			i = tmp2->cost_a + tmp2->cost_b;
		if (i < j)
			j = i;
		tmp2 = tmp2->next;
	}
	return (j);
}

int	ft_low_counter(t_ps **lst2)
{
	int		i;
	int		j;
	t_ps	*tmp2;

	tmp2 = *lst2;
	j = 9999;
	i = 0;
	if (tmp2->cost_a < 0 && tmp2->cost_b < 0)
		i = (tmp2->cost_a * -1) + (tmp2->cost_b * -1);
	else if (tmp2->cost_a < 0 && tmp2->cost_b >= 0)
		i = (tmp2->cost_a * -1) + tmp2->cost_b;
	else if (tmp2->cost_b < 0 && tmp2->cost_a >= 0)
		i = (tmp2->cost_b * -1) + tmp2->cost_a;
	else
		i = tmp2->cost_a + tmp2->cost_b;
	if (i < j)
		j = i;
	return (j);
}
