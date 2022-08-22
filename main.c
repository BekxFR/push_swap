#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

//#define NB 3

typedef struct	ps_list
{
	int 			data;
	struct ps_list	*next;
}	t_ps;

typedef struct	ps_list2
{
	int 			data2;
	struct ps_list2	*next;
}	t_ps2;

int	ft_push_swap(int i)
{
	if (!i)
		return (0);
	return (i);
}

void	ft_printlst(t_ps **start)
{
	t_ps *tmp;
	tmp = *start;
	ft_printf("\n");
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

void	ft_printlst2(t_ps2 *start2)
{
	t_ps2 *tmp;
	tmp = start2;
	ft_printf("\n");
	while (tmp)
	{
		ft_printf("%d ", tmp->data2);
		tmp = tmp->next;
	}
}

void ft_lst_addfirst(t_ps **start, int i)
{
	t_ps *tmp;
	tmp = (t_ps *)malloc(sizeof(t_ps));
	if (!tmp)
		return ;
	tmp->data = i;
	tmp->next = *start;
	*start = tmp;
}

void ft_lst_addlast(t_ps2 **start2, int i)
{
	t_ps2 *tmp;
	t_ps2 *tmp2;

	tmp = (t_ps2 *)malloc(sizeof(t_ps2));
	if (!tmp)
		return ;
	tmp->data2 = i;
	tmp->next = NULL;
	tmp2 = *start2;
	if (*start2 == NULL)
	{
		*start2 = tmp;
		return ;
	}
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return ;
}

/* void *ft_lstlast2(t_ps2 *lst)
{
	while(lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void ft_lstendajouttest(t_ps2 **start2, int i)
{
	t_ps2 *tmp;
	t_ps2 *tmp2;

	tmp = (t_ps2 *)malloc(sizeof(t_ps2));
	if (!tmp)
		return ;
	tmp->data2 = i;
	tmp->next = NULL;
	printf("END ADD I =:%d\n", i);
	if (*start2 == NULL)
		*start2 = tmp;
	else
	{
		tmp2 = ft_lstlast2(*(start2));
		tmp2->next = tmp;
	}
} */

void ft_clean_lst(t_ps **start)
{
	t_ps *tmp;

	while (*start != NULL)
	{
		tmp = *start;
		*start = tmp->next;
		free(tmp);
	}
}

void ft_clean_lst2(t_ps2 **start)
{
	t_ps2 *tmp;

	while (*start != NULL)
	{
		tmp = *start;
		*start = tmp->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	int	i[argc];
	int	j;

	t_ps	*start = NULL;
	t_ps2	*start2 = NULL;

	j = -1;
	while (++j < argc - 1)
	{
		i[j] = ft_atoi(argv[j + 1]);
		if (((ft_strlen(argv[j + 1]) > 11) || (i[j] > INT_MAX) || (i[j] < INT_MIN)))
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_lst_addfirst(&start, i[j]);
		ft_lst_addlast(&start2, i[j]);
		
	}
	j = 0;
	if (argc <= 4)
	{
		while (i[j] && j < argc - 1)
		{
			if (j == argc - 2)
			{
				ft_printf("PS1:%d", ft_push_swap(i[j]));
				ft_printlst(&start);
				ft_printlst2(start2);
				ft_printf("\n");
			}
			else
			{
				ft_printf("PS2:%d", ft_push_swap(i[j]));
				ft_printlst(&start);
				ft_printlst2(start2);
				ft_printf("\n");
			}
			j++;
		}
	}
	if (j == argc - 1)
	{
		ft_clean_lst(&start);
		ft_clean_lst2(&start2);
	}
	return 0;
}
