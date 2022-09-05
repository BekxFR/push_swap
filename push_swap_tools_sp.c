/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools_sp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:15:29 by chillion          #+#    #+#             */
/*   Updated: 2022/09/05 11:08:45 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_ps **lst, t_ps **lst2)
{
	t_ps	*tmp;

	if (!*lst2)
		return ;
	tmp = *lst2;
	if (!(*lst2)->next)
		(*lst2) = NULL;
	else
		(*lst2) = (*lst2)->next;
	if (!*lst)
		tmp->next = NULL;
	else
		tmp->next = *lst;
	*lst = tmp;
}

void	ft_pb(t_ps **lst, t_ps **lst2)
{
	t_ps	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	if (!(*lst)->next)
		(*lst) = NULL;
	else
		(*lst) = (*lst)->next;
	if (!*lst2)
		tmp->next = NULL;
	else
		tmp->next = *lst2;
	*lst2 = tmp;
}

void	ft_sa(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	tmp2->next = tmp;
	*lst = tmp2;
}

void	ft_sb(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	tmp2->next = tmp;
	*lst = tmp2;
}

void	ft_ss(t_ps **lst, t_ps **lst2)
{
	ft_sa(lst);
	ft_sb(lst2);
}
