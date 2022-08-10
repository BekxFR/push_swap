/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:32:50 by chillion          #+#    #+#             */
/*   Updated: 2022/05/10 14:08:46 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	i = 0;
	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	while (n != 0)
	{
		if (ns1[i] != ns2[i])
		{
			return (ns1[i] - ns2[i]);
		}
		n--;
		i++;
	}
	return (0);
}
