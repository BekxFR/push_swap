/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools_rr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:15:24 by chillion          #+#    #+#             */
/*   Updated: 2022/08/31 16:15:26 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		if (!tmp->next->next)
		{
			tmp2 = tmp->next;
			tmp2->next = *lst;
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	*lst = tmp2;
}

void	ft_rrb(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		if (!tmp->next->next)
		{
			tmp2 = tmp->next;
			tmp2->next = *lst;
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	*lst = tmp2;
}

void	ft_rrr(t_ps **lst, t_ps **lst2)
{
	if (*lst)
		ft_rra(lst);
	if (*lst2)
		ft_rrb(lst2);
}

void	ft_switch_rrr(t_ps **lst, t_ps **lst2)
{
	ft_printf("rrr\n");
	ft_rrr(lst, lst2);
}

int	ft_switch_rra(t_ps **lst, int j)
{
	ft_printf("rra\n");
	ft_rra(lst);
	j = j + 1;
	return (j);
}
