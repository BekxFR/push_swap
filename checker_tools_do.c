/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:47:01 by chillion          #+#    #+#             */
/*   Updated: 2022/09/05 12:13:42 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_do_shortarg_r(char *arg, t_ps **lst, t_ps **lst2)
{
	if (arg[0] == 'r' && arg[1] == 'r')
	{
		ft_rr(lst, lst2);
	}
	if (arg[0] == 'r' && arg[1] == 'a')
	{
		ft_ra(lst);
	}
	if (arg[0] == 'r' && arg[1] == 'b')
	{
		ft_rb(lst2);
	}
}

void	ft_do_shortarg_s(char *arg, t_ps **lst, t_ps **lst2)
{
	if (arg[0] == 's' && arg[1] == 's')
	{
		ft_ss(lst, lst2);
	}
	if (arg[0] == 's' && arg[1] == 'a')
	{
		ft_sa(lst);
	}
	if (arg[0] == 's' && arg[1] == 'b')
	{
		ft_sb(lst2);
	}
}

void	ft_do_shortarg(char *arg, t_ps **lst, t_ps **lst2)
{
	ft_do_shortarg_r(arg, lst, lst2);
	ft_do_shortarg_s(arg, lst, lst2);
	if (arg[0] == 'p' && arg[1] == 'a')
	{
		ft_pa(lst, lst2);
	}
	if (arg[0] == 'p' && arg[1] == 'b')
	{
		ft_pb(lst, lst2);
	}
}

void	ft_do_longarg(char *arg, t_ps **lst, t_ps **lst2)
{
	if (arg[0] == 'r' && arg[1] == 'r' && arg[2] == 'r')
	{
		ft_rrr(lst, lst2);
	}
	if (arg[0] == 'r' && arg[1] == 'r' && arg[2] == 'a')
	{
		ft_rra(lst);
	}
	if (arg[0] == 'r' && arg[1] == 'r' && arg[2] == 'b')
	{
		ft_rrb(lst2);
	}
}

char	*ft_init_str(char *str)
{
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	if (!str)
		return (NULL);
	return (str);
}
