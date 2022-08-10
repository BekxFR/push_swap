#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

//#define NB 3

int	ft_push_swap(int i)
{
	if (!i)
		return (0);
	return (i);
}

void	ft_sa(int *a)
{
	int	tmp;

	if (!a || !a[0] || !a[1])
		return;
	tmp = a[1];
	a[1] = a[0];
	a[0] = tmp;
}

void	ft_sb(int *b)
{
	int	tmp;

	if (!b || !b[0] || !b[1])
		return;
	tmp = b[1];
	b[1] = b[0];
	b[0] = tmp;
}

void	ft_ss(int *a, int *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(int *a, int *b)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (!b[0] || !b)
		return;
	tmp = a[0];
	a[0] = b[0];
	i = 0;
	while (a[++i])
	{
		tmp2 = a[i];
		a[i] = tmp;
		tmp = tmp2;
	}
	/*
	 j = 0;
	 while (!a[j])
	 	j++;
	while (i < j + 1)
	 */
}

void	ft_pb(int *a, int *b)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (!a[0] || !a)
		return;
	tmp = b[0];
	b[0] = a[0];
	i = 0;
	while (b[++i])
	{
		tmp2 = b[i];
		b[i] = tmp;
		tmp = tmp2;
	}
	/*
	 j = 0;
	 while (!b[j])
	 	j++;
	while (i < j + 1)
	 */
}

void ft_ra(int *a)
{
	int	i;
	int	j;
	int	tmp;

	if (!a)
		return ;
	i = 0;
	while (a[i])
		i++;
	if (i < 2)
		return ;
	j = -1;
	tmp = a[0];
	while (++j < i)
	{
		a[j] = a[j + 1];
	}
	a[j] = tmp;
}

void ft_rb(int *b)
{
	int	i;
	int	j;
	int	tmp;

	if (!b)
		return ;
	i = 0;
	while (b[i])
		i++;
	if (i < 2)
		return ;
	j = -1;
	tmp = b[0];
	while (++j < i)
	{
		b[j] = b[j + 1];
	}
	b[j] = tmp;
}

void	ft_rr(int *a, int *b)
{
	if (!a || !b)
		return ;
	ft_ra(a);
	ft_rb(b);
}

void ft_rra(int *a)
{
	int	i;
	int	j;
	int	tmp;

	if (!a)
		return ;
	i = 0;
	while (!a[i])
		i++;
	if (i < 2)
		return ;
	tmp = a[i];
	j = -1;
	while (a[++j])
	{
		a[j  + 1] = a[j];
	}
	a[0] = tmp;
}

void ft_rrb(int *b)
{
	int	i;
	int	j;
	int	tmp;

	if (!b)
		return ;
	i = 0;
	while (!b[i])
		i++;
	if (i < 2)
		return ;
	tmp = b[i];
	j = -1;
	while (b[++j])
	{
		b[j  + 1] = b[j];
	}
	b[0] = tmp;
}

void ft_rrr(int *a, int *b)
{
	if (!a || !b)
		return ;
	ft_rra(a);
	ft_rrb(b);
}

int	main(int argc, char **argv)
{
	int	i[argc];
	int	j;

	j = -1;
	while (++j < argc - 1)
	{
		i[j] = atoi(argv[j + 1]);
		if (((ft_strlen(argv[j + 1]) > 11) || (i[j] > INT_MAX) || (i[j] < INT_MIN)))
		{
			ft_printf("Error");
			return (0);
		}
	}
	j = 0;
	if (argc <= 4)

		while (i[j] && j < argc - 1)
		{
			if (j == argc - 2)
				ft_printf("PS:%d", ft_push_swap(i[j]));
			else
				ft_printf("PS:%d\n", ft_push_swap(i[j]));
			j++;
		}
	return 0;
}
