/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:01:25 by chillion          #+#    #+#             */
/*   Updated: 2022/08/30 17:16:47 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	str = ft_zalloc(i + 1, sizeof * str);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[j + i] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	ft_free (&s1);
	return (str);
}

void	*ft_zalloc(size_t nmemb, size_t size)
{
	void			*dest;
	unsigned char	*pdest;
	size_t			total;
	size_t			i;

	if (nmemb != 0 && (nmemb * size / nmemb) != size)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	i = 0;
	total = nmemb * size;
	pdest = (unsigned char *)dest;
	while (i < total)
	{
		pdest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_schr(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
