/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:15:04 by chillion          #+#    #+#             */
/*   Updated: 2022/05/10 14:15:50 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb > 2147483647 / size || size > 2147483647 / nmemb)
	{
		return (NULL);
	}
	dest = malloc(nmemb * size);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_bzero(dest, nmemb * size);
	return (dest);
}
