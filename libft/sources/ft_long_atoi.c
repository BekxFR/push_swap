/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:59 by chillion          #+#    #+#             */
/*   Updated: 2022/08/30 13:13:11 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_long_atoi(const char *nptr)
{
	int			x;
	int			y;
	long int	nb;

	x = 0;
	y = 1;
	nb = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == ' ')
		x++;
	if (nptr[x] == '+' || nptr[x] == '-')
	{
		if (nptr[x] == '-')
			y *= -1;
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		nb = nb * 10 + (nptr[x] - 48);
		x++;
	}
	nb *= y;
	if ((nb > INT_MAX || nb < INT_MIN) || nptr[x++] || !nptr[0])
		return (999999999999);
	return (nb);
}