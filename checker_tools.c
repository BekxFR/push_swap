/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:00:53 by chillion          #+#    #+#             */
/*   Updated: 2022/09/01 18:18:03 by chillion         ###   ########.fr       */
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

int ft_do_args(char *tmp, t_ps **lst, t_ps **lst2)
{
	int	i;

	i = 0;
	while (tmp[i + 1] != '\0')
	{
		if (tmp[i] != '\n')
			return (0);
	}
	ft_split(tmp, '\n')
	
}

int	ft_check_args(char *arg, char *tmp, t_ps **lst, t_ps **lst2)
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
				ft_trio_free(&arg, &tmp, NULL);
				return (0);
			}
			tmp = ft_strjoin_free(tmp, arg);
			ft_free(&arg);
			arg = ft_init_str(arg);
			if (!arg)
				return (0);
		}
	}
	ft_do_args(tmp, lst, lst2);
	ft_trio_free(&arg, &tmp, NULL);
	return (i);
}



int	ft_tester_makefile(int argc, t_ps **lst, t_ps **lst2)
{
	char	*arg;
	char	*tmp;

	arg = NULL;
	arg = ft_init_str(arg);
	tmp = NULL;
	tmp = ft_init_str(tmp);
	argc = 0;
	argc = ft_check_args(arg, tmp, argc);
/* 	if (argc == 1)
		ft_do_args(tmp, lst, lst2) */
	return (argc);
}

/* int	ft_tester_makefile(int argc) //, t_ps **lst, t_ps **lst2)
{
	char	buf;
	char	*arg;
	char	*tmp;

	arg = NULL;
	arg = ft_init_str(arg);
	tmp = NULL;
	tmp = ft_init_str(tmp);
	argc = 0;
	while (read(0, &buf, 1) > 0)
	{
		arg = ft_charjoin(arg, buf);
		if (buf == '\n')
		{
			if ((argc = ft_check_arg(arg)) != 1)
				return (0);
			tmp = ft_strjoin_free(tmp, arg);
			ft_free(&arg);
			arg = ft_init_str(arg);
			if (!arg)
				return (0);
		}
	}
	ft_trio_free(&arg, &tmp, NULL);
	return (argc);
} */