/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:30:05 by chillion          #+#    #+#             */
/*   Updated: 2022/09/05 12:12:36 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "push_swap.h"

int		ft_init_args(int argc, t_ps **lst, t_ps **lst2);
void	ft_do_shortarg_r(char *arg, t_ps **lst, t_ps **lst2);
void	ft_do_shortarg_s(char *arg, t_ps **lst, t_ps **lst2);
void	ft_do_shortarg(char *arg, t_ps **lst, t_ps **lst2);
void	ft_do_longarg(char *arg, t_ps **lst, t_ps **lst2);
char	*ft_init_str(char *str);
char	*ft_charjoin(char *arg, char buf);
int		ft_check_arg(char *arg);
int		ft_checker_args_end(char *args);
int		ft_parse_args(int j, char *tmp, t_ps **lst, t_ps **lst2);
int		ft_do_args(char *args, t_ps **lst, t_ps **lst2);
void	ft_checker(int argc, t_ps **lst, t_ps **lst2);
int		ft_init_args(int argc, t_ps **lst, t_ps **lst2);
int		ft_check_args(char *arg, char *args, t_ps **lst, t_ps **lst2);
void	ft_arg_error(char *arg, char *args, t_ps **lst, t_ps **lst2);
void	ft_join_args_arg(char *args, char *arg);

#endif