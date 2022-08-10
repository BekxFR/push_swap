/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:58:29 by chillion          #+#    #+#             */
/*   Updated: 2022/05/03 16:58:34 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
	{
		return (8);
	}
	return (0);
}
/*
int	main(void)
{
//	signed char	c;
//
//	c = ' ';
//	printf("%d\n", isalnum(c));
//	printf("%d\n", ft_isalnum(c));

    int c;

    c = 0;
    while (c <= 500)
    {
	printf("%d  &&  ", isalnum(c));
	printf("%d\n", ft_isalnum(c));
    c++;
    }

}
*/
