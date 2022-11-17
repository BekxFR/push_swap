/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:29:33 by chillion          #+#    #+#             */
/*   Updated: 2022/10/03 16:34:45 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_arg_error(char *arg, char *args, t_ps **lst, t_ps **lst2)
{
	ft_trio_free(&arg, &args, NULL);
	ft_clean_lst(lst);
	ft_clean_lst(lst2);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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
			i = ft_check_arg(arg);
			if (i != 1)
				break ;
			ft_join_args_arg(args, arg);
			if (!arg)
				return (0);
		}
	}
	if (!buf)
		return (ft_trio_free(&arg, &args, NULL), -1);
	if (i == 0)
		ft_arg_error(arg, args, lst, lst2);
	else
		i = ft_do_args(args, lst, lst2);
	return (ft_trio_free(&arg, &args, NULL), i);
}

int	ft_init_args(int argc, t_ps **lst, t_ps **lst2)
{
	char	*arg;
	char	*args;

	arg = NULL;
	arg = ft_init_str(arg);
	args = NULL;
	args = ft_init_str(args);
	argc = 0;
	argc = ft_check_args(arg, args, lst, lst2);
	if (argc == -1)
	{
		return (write(1, "KO\n", 3), ft_clean_lst(lst), \
		ft_clean_lst(lst2), exit(EXIT_SUCCESS), 0);
	}
	if (argc != 0)
		argc = ft_tried_list(lst);
	if (argc != 0 || *lst2)
	{
		return (write(1, "KO\n", 3), ft_clean_lst(lst), \
		ft_clean_lst(lst2), exit(EXIT_SUCCESS), 0);
	}
	return (argc);
}

void	ft_checker(int argc, t_ps **lst, t_ps **lst2)
{
	if (ft_init_args(argc, lst, lst2) == 0)
	{
		write(1, "OK\n", 3);
		ft_clean_lst(lst);
		ft_clean_lst(lst2);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int		j;
	t_ps	*stack;
	t_ps	*stack2;

	stack = NULL;
	stack2 = NULL;
	j = -1;
	if (argc >= 2)
	{
		while (++j < argc - 1)
		{
			ft_control_list(&stack, argv[j + 1], argc - 1);
			if (!stack)
				exit(EXIT_SUCCESS);
		}
		if (ft_tried_list(&stack) == 0 && stack)
		{
			write(1, "OK\n", 3);
			ft_clean_lst(&stack);
		}
		if (stack)
			ft_checker(argc, &stack, &stack2);
	}	
	exit(EXIT_SUCCESS);
}
