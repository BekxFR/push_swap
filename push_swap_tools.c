/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:15:34 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 18:13:23 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_ps **start)
{
	t_ps	*tmp;

	tmp = *start;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_lst_addfirst(t_ps **start, int i)
{
	t_ps	*tmp;

	tmp = (t_ps *)malloc(sizeof(t_ps));
	if (!tmp)
		return ;
	tmp->data = i;
	tmp->next = *start;
	*start = tmp;
}

void	ft_lst_addlast(t_ps **lst, int i)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	tmp = (t_ps *)malloc(sizeof (t_ps));
	if (!tmp)
		return ;
	tmp->data = i;
	tmp->index = 1;
	tmp->pos = 0;
	tmp->target_pos = 0;
	tmp->cost_a = 0;
	tmp->cost_b = 0;
	tmp->next = NULL;
	tmp2 = *lst;
	if (!*lst)
	{
		*lst = tmp;
		return ;
	}
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return ;
}

void	ft_clean_lst(t_ps **start)
{
	t_ps	*tmp;

	while (*start != NULL)
	{
		tmp = *start;
		*start = tmp->next;
		free(tmp);
	}
}

int	ft_find_index(t_ps **lst)
{
	int		i;
	t_ps	*tmp;

	i = 999999;
	tmp = *lst;
	while (tmp)
	{
		if (i > tmp->index)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}
