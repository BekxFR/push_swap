/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:14:44 by chillion          #+#    #+#             */
/*   Updated: 2022/09/05 14:59:05 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tried_list(t_ps **lst)
{
	t_ps	*tmp;

	if (!*lst)
		return (0);
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_control_list(t_ps **stack, const char *nptr, int argc)
{
	ft_push_list(stack, nptr);
	if (*stack)
	{
		if (ft_checklst(stack, argc - 1) == 0)
		{
			ft_clean_lst(stack);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
}

int	ft_checklst(t_ps **lst, int count)
{
	int		j;
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst)
		return (0);
	tmp = *lst;
	while (count > 0)
	{
		while (tmp->next)
		{
			j = tmp->data;
			tmp2 = tmp;
			while (tmp2->next)
			{
				tmp2 = tmp2->next;
				if (j == tmp2->data)
					return (0);
			}
			tmp = tmp->next;
		}
		count--;
	}
	return (1);
}

void	ft_push_list(t_ps **lst, const char *nptr)
{
	long int	i;

	i = ft_long_strict_atoi(nptr);
	if (i == 999999999999)
	{
		ft_clean_lst(lst);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	ft_lst_addlast(lst, i);
}
