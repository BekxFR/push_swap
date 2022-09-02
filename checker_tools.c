/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:00:53 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 16:57:50 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

char	*ft_charjoin(char *arg, char buf)
{
	int i;
	char *line;

	i = ft_strlen(arg) + 1;
//	line = ft_zalloc(i + 2, sizeof * line);
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (arg[i] != '\0')
	{
		line[i] = arg[i];
		i++;
	}
	line[i] = buf;
	line[i + 1] = '\0';
	ft_free(&arg);
	return (line);
}

int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == 'p' || arg[0] == 'r'|| arg[0] == 's')
	{
		if ((arg[1] == 'a' || arg[1] == 'b') && (arg[2] == '\n'))
			i = 1;
	}
	if ((arg[0] == 'r' && arg[1] == 'r' && arg[2] == '\n') || (arg[0] == 's' && arg[1] == 's' && arg[2] == '\n'))
		i = 1;
	if (arg[0] == 'r' && arg[1] == 'r')
	{
		if ((arg[2] == 'a' || arg[2] == 'b' || arg[2] == 'r') && (arg[3] == '\n'))
			i = 1;
	}
	return (i);
}

char	*ft_init_str(char *str)
{
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	if (!str)
		return (NULL);
	return (str);
}

void	ft_do_shortarg(char *arg, t_ps **lst, t_ps **lst2)
{
	if (arg[0] == 'r' && arg[1] == 'r')
	{
		ft_printf("rr\n");
		ft_rr(lst, lst2);
	}
	if (arg[0] == 'r' && arg[1] == 'a')
	{
		ft_printf("ra\n");
		ft_ra(lst);
	}
	if (arg[0] == 'r' && arg[1] == 'b')
	{
		ft_printf("rb\n");
		ft_rb(lst2);
	}
	if (arg[0] == 's' && arg[1] == 's')
	{
		ft_printf("ss\n");
		ft_ss(lst, lst2);
	}
	if (arg[0] == 's' && arg[1] == 'a')
	{
		ft_printf("sa\n");
		ft_sa(lst);
	}
	if (arg[0] == 's' && arg[1] == 'b')
	{
		ft_printf("sb\n");
		ft_sb(lst2);
	}
	if (arg[0] == 'p' && arg[1] == 'a')
	{
		ft_printf("pa\n");
		ft_pa(lst, lst2);
	}
	if (arg[0] == 'p' && arg[1] == 'b')
	{
		ft_printf("pb\n");
		ft_pb(lst, lst2);
	}
}

void	ft_do_longarg(char *arg, t_ps **lst, t_ps **lst2)
{
	if (arg[0] == 'r' && arg[1] == 'r' && arg[2] == 'r')
	{
		ft_printf("rrr\n");
		ft_rrr(lst, lst2);
	}
	if (arg[0] == 'r' && arg[1] == 'r' && arg[2] == 'a')
	{
		ft_printf("rra\n");
		ft_rra(lst);
	}
	if (arg[0] == 'r' && arg[1] == 'r' && arg[2] == 'b')
	{
		ft_printf("rrb\n");
		ft_rrb(lst2);
	}
}

int		ft_do_args(char *args, t_ps **lst, t_ps **lst2)
{
	int	i;
	int	j;
	char *tmp;

	i = 0;
	while (args[i] != '\0')
		i++;
	if (args[i - 1] != '\n')
		return (0);
	i = 0;
	tmp = args;
	while (i != 1)
	{
		j = 0;
		if (tmp[j + 3] == '\n')
		{
			ft_do_longarg(tmp, lst, lst2);
			j = 4;
		}
		else if (tmp[j + 2] == '\n')
		{
			ft_do_shortarg(tmp, lst, lst2);
			j = 3;
		}
		if (tmp[j] == '\0')
			i = 1;
		else
		{
			i = i + j;
			tmp = &args[i];
		}
	}
	return (i);
}

int	ft_check_args(char *arg, char *args, t_ps **lst, t_ps **lst2)
{
	int		i;
	char	buf;

	i = 0;
	while (read(0, &buf, 1) > 0)
	{
		arg = ft_charjoin(arg, buf);
		if (buf == '\n')
		{
			if ((i = ft_check_arg(arg)) != 1)
			{
				break ;
			}
			args = ft_strjoin_free(args, arg);
			ft_free(&arg);
			arg = ft_init_str(arg);
			if (!arg)
				return (0);
		}
	}
	if (i == 0)
	{
		ft_printf("Error\n");
		ft_trio_free(&arg, &args, NULL);
		return (2);
	}
	else
		i = ft_do_args(args, lst, lst2);
	ft_trio_free(&arg, &args, NULL);
	return (i);
}

int	ft_tester_makefile(int argc, t_ps **lst, t_ps **lst2)
{
	char	*arg;
	char	*args;

	arg = NULL;
	arg = ft_init_str(arg);
	args = NULL;
	args = ft_init_str(args);
	argc = 0;
	argc = ft_check_args(arg, args, lst, lst2);
	if (argc == 2)
		return (2);
	else if (argc != 0)
	{
		argc = ft_tried_list(lst);
		ft_printf("TEST23 ARGC :%d", argc);
	}
	if (argc != 0 || *lst2)
	{
		ft_printf("KO\n");
		argc = 1;
	}
	return (argc);
}
