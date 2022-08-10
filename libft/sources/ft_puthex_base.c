/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:44:53 by chillion          #+#    #+#             */
/*   Updated: 2022/07/13 10:44:56 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_puthex_base(unsigned long int nbr, char *base)
{
	unsigned int	i;

	i = ft_basecheck(base);
	if (ft_basecheck(base) > 0 && ft_strdouble(base) == 1)
	{
		while (i <= nbr)
		{
			ft_puthex_base(nbr / i, base);
			nbr = nbr % i;
		}
		ft_putchar(base[nbr]);
	}
}
/*
int	main(void)
{
    ft_putnbr_base(-1u);
	ft_putchar('\n');
}
*/