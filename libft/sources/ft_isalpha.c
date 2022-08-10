/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:58:10 by chillion          #+#    #+#             */
/*   Updated: 2022/05/03 16:58:14 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1024);
	}
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	c;

	c = 'w';
	printf("%d\n", isalpha(c));
	printf("%d\n", ft_isalpha(c));
}
*/