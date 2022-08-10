/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:03:06 by chillion          #+#    #+#             */
/*   Updated: 2022/05/03 17:03:15 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexchar(char c)
{
	char			*base;
	unsigned char	hex;

	base = "0123456789abcdef";
	hex = (unsigned char)c;
	ft_putchar('\\');
	ft_putchar(base[hex / 16]);
	ft_putchar(base[hex % 16]);
}

#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	unsigned char	ch;
    char str[] = "z义가";
    int i;


    i = 0;
    while (i < 4)
    {
        ch = str[i];
        ft_hexchar(ch);
        printf("  %#04x  &&  ", ch);
	    printf("%d  &&  ", isascii(ch));
	    printf("%d\n", ft_isascii(ch));
        i++;
    }

    int c;

    c = 0x00;
    while (c <= 0x82)
    {
        printf("%#04x  &&  ", c);
	    printf("%d  &&  ", isascii(c));
	    printf("%d\n", ft_isascii(c));
        c++;
    }
}
*/