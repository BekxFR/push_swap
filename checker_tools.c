/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:00:53 by chillion          #+#    #+#             */
/*   Updated: 2022/09/05 11:04:38 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_charjoin(char *arg, char buf)
{
	int		i;
	char	*line;

	i = ft_strlen(arg) + 1;
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
	if (arg[0] == 'p' || arg[0] == 'r' || arg[0] == 's')
	{
		if ((arg[1] == 'a' || arg[1] == 'b') && (arg[2] == '\n'))
			i = 1;
	}
	if ((arg[0] == 'r' && arg[1] == 'r' && arg[2] == '\n')
		|| (arg[0] == 's' && arg[1] == 's' && arg[2] == '\n'))
		i = 1;
	if (arg[0] == 'r' && arg[1] == 'r')
	{
		if ((arg[2] == 'a' || arg[2] == 'b' || arg[2] == 'r')
			&& (arg[3] == '\n'))
			i = 1;
	}
	return (i);
}

int	ft_checker_args_end(char *args)
{
	int	i;

	i = 0;
	while (args[i] != '\0')
		i++;
	if (args[i - 1] != '\n')
		return (0);
	return (i);
}

int	ft_parse_args(int j, char *tmp, t_ps **lst, t_ps **lst2)
{
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
	return (j);
}

int	ft_do_args(char *args, t_ps **lst, t_ps **lst2)
{
	int		i;
	int		j;
	char	*tmp;

	if (ft_checker_args_end(args) == 0)
		return (0);
	i = 0;
	tmp = args;
	while (i != 1)
	{
		j = 0;
		j = ft_parse_args(j, tmp, lst, lst2);
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
