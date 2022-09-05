/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:15:18 by chillion          #+#    #+#             */
/*   Updated: 2022/08/31 16:15:19 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = (*lst)->next;
	*lst = tmp2;
	tmp->next = NULL;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
}

void	ft_rb(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = (*lst)->next;
	*lst = tmp2;
	tmp->next = NULL;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
}

void	ft_rr(t_ps **lst, t_ps **lst2)
{
	if (*lst)
		ft_ra(lst);
	if (*lst2)
		ft_rb(lst2);
}

void	ft_switch_rr(t_ps **lst, t_ps **lst2)
{
	ft_printf("rr\n");
	ft_rr(lst, lst2);
}

int	ft_switch_ra(t_ps **lst, int j)
{
	ft_printf("ra\n");
	ft_ra(lst);
	j = j - 1;
	return (j);
}
