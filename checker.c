/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:29:33 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 18:29:36 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_checker(int argc, t_ps **lst, t_ps **lst2)
{
	if (ft_tester_makefile(argc, lst, lst2) == 0)
		ft_printf("OK\n");
	ft_clean_lst(lst);
	ft_clean_lst(lst2);
}

int	main(int argc, char **argv)
{
	int		j;
	t_ps	*stack;
	t_ps	*stack2;

	stack = NULL;
	stack2 = NULL;
	j = -1;
	if (argc > 2)
	{
		while (++j < argc - 1)
		{
			ft_control_list(&stack, argv[j + 1], argc - 1);
			if (!stack)
				return (0);
		}
		if (ft_tried_list(&stack) == 0 && stack)
			ft_clean_lst(&stack);
		if (stack)
			ft_checker(argc, &stack, &stack2);
	}	
	return (0);
}
