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

void	ft_printlst(t_ps *start)
{
	t_ps *tmp;
	tmp = start;
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

//t_ps ft_insert_lst(void *content)
//{
//	t_ps	*list;
//	list = (t_ps *)malloc(sizeof(t_ps));
//	if (!list)
//		return (NULL);
//	list->content = content;
//	list->next = NULL;
//	return (list);
//}

void	*ft_lst_last(t_ps *lst)
{
	if (lst == NULL)
	{
		return (lst);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lst_back(t_ps **lst, t_ps *new)
{
	t_ps	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		tmp = ft_lst_last(*(lst));
		tmp->next = new;
	}
}

void ft_lstajouttest(t_ps **start, int i)
{
	t_ps *tmp;
	tmp = (t_ps *)malloc(sizeof(t_ps));
	if (!tmp)
		return ;
	tmp->data = i;
	tmp->next = *start;
	*start = tmp;
}

void ft_lstendajouttest(t_ps2 **start2, int i)
{
	t_ps2 *tmp2;
	if (start2 == NULL)
		return ;
	tmp2 = *start2;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = (t_ps2 *)malloc(sizeof(t_ps2));
	if (!tmp2->next)
		return ;
	tmp2->data2 = i;
	tmp2->next = NULL;
}

int	main(int argc, char **argv)
{
	int	i[argc];
	int	j;

//	t_ps	ps_list;
	t_ps	*start = NULL;
	t_ps2	*start2 = NULL;

	j = -1;
	while (++j < argc - 1)
	{
		i[j] = ft_atoi(argv[j + 1]);
		ft_lstajouttest(&start, i[j]);
		if (((ft_strlen(argv[j + 1]) > 11) || (i[j] > INT_MAX) || (i[j] < INT_MIN)))
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	printf("J:%d", j);
	j = -1;
	while (++j < argc - 1)
	{
		ft_lstendajouttest(&start2, i[j]);
	}

	j = 0;
	if (argc <= 4)
	{
		while (i[j] && j < argc - 1)
		{
			if (j == argc - 2)
			{
				ft_printf("PS:%d", ft_push_swap(i[1]));
				ft_printlst(start);
//				ft_printlst2(start2);
			}
			else
			{
				ft_printf("PS:%d\n", ft_push_swap(i[j]));
				ft_printlst(start);
				ft_printf("\n");
//				ft_printlst2(start2);
				ft_printf("\n");
			}
			j++;
		}
	}
	return 0;
}
