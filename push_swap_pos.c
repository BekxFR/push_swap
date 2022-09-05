/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:14:57 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 18:12:20 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_targpos_lst(t_ps **lst, t_ps **lst2, int argc)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	int		i;
	int		j;

	tmp = *lst;
	tmp2 = *lst2;
	while (tmp2)
	{
		i = argc;
		j = argc;
		while (tmp)
		{
			if (tmp2->index < tmp->index && i > tmp->index)
			{
				i = ft_index_inf(&tmp, &tmp2);
				j = 0;
			}
			tmp = tmp->next;
		}
		if (j)
			ft_index_supp(lst, &tmp2, argc);
		tmp = *lst;
		tmp2 = tmp2->next;
	}
}

void	ft_pos_lst(t_ps **lst, t_ps **lst2)
{
	int		i;
	t_ps	*tmp;

	i = 0;
	tmp = *lst;
	if (tmp)
	{
		while (tmp)
		{
			tmp->pos = i++;
			tmp = tmp->next;
		}
	}
	i = 0;
	tmp = *lst2;
	if (tmp)
	{
		while (tmp)
		{
			tmp->pos = i++;
			tmp = tmp->next;
		}
	}
}

int	ft_index_inf(t_ps **lst, t_ps **lst2)
{
	int	i;

	(*lst2)->target_pos = (*lst)->pos;
	i = (*lst)->index;
	return (i);
}

void	ft_index_supp(t_ps **lst, t_ps **lst2, int argc)
{
	t_ps	*tmp;
	int		i;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->index < argc)
		{
			argc = tmp->index;
			i = tmp->pos;
		}
		tmp = tmp->next;
	}
	(*lst2)->target_pos = i;
}

void	ft_index_list(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp2->data > tmp->data)
				tmp2->index = tmp2->index + 1;
			tmp = tmp->next;
		}
		tmp = *lst;
		tmp2 = tmp2->next;
	}
}
