/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:48:08 by chillion          #+#    #+#             */
/*   Updated: 2022/05/17 11:48:24 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
	{
		return (ft_calloc(1, 1));
	}
	s = s + start;
	if (ft_strlen(s) > len)
		str = ft_calloc(1, (len + 1));
	else
	{
		len = ft_strlen(s);
		str = ft_calloc(1, (len + 1));
	}
	if (!str)
		return (NULL);
	return (ft_memcpy(str, s, len));
}
