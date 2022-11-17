/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:30:05 by chillion          #+#    #+#             */
/*   Updated: 2022/11/17 17:25:18 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_join_args_arg(char *args, char *arg)
{
	args = ft_strjoin_free(args, arg);
	ft_free(&arg);
	arg = ft_init_str(arg);
}
