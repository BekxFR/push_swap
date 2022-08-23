#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

//#define NB 3



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
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_printlst2(t_ps2 *start2)
{
	t_ps2 *tmp;

	tmp = start2;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void ft_lst_addfirst(t_ps **start, const char *nptr)
{
	t_ps *tmp;
	int i;

	i = ft_atoi(nptr);
	if (((ft_strlen(nptr) > 11) || (i > INT_MAX) || (i < INT_MIN)))
	{
		ft_printf("Error\n");
		return ;
	}
	tmp = (t_ps *)malloc(sizeof(t_ps));
	if (!tmp)
		return ;
	tmp->data = i;
	tmp->next = *start;
	*start = tmp;
}

void	ft_lst_addlast(t_ps **lst, const char *nptr)
{
	t_ps *tmp;
	t_ps *tmp2;
	int i;
	int j;

	j = INT_MIN;
	ft_printf("ERRRRRRRROOORRR%d\n", j);
	i = ft_atoi(nptr);
	ft_printf("ERRRRRRRROOORRR%d\n", i);
	if (ft_strlen(nptr) > 11 || (i > INT_MAX || i < INT_MIN))
	{
		ft_printf("Error\n");
		return ;
	}
	tmp = (t_ps *)malloc(sizeof (t_ps));
	if (!tmp)
		return ;
	tmp->data = i;
	tmp->next = NULL;
	tmp2 = *lst;
	if (!*lst)
	{
		*lst = tmp;
		return ;
	}
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return ;
}

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

/* void ft_indexlst(t_ps **lst, int count)
{
	int		i;
	t_ps	tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	i = 0;
	while (i < index)
	{
		if (tmp->data < tmp->next->data)
			tmp->index = i + 1;
	}
} */

/* int ft_checklst(t_ps **lst, int count)
{
	int		j;
	int		k;
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst)
		return (0);
	tmp = *lst;
	k = 0;
	ft_printf("\033[0;32mCOUNT : %d\033[0m\n", count);
	while (count > 0)
	{
		while (tmp->next)
		{
			j = tmp->data;
			tmp2 = tmp;
			while (tmp2->next)
			{
				tmp2 = tmp2->next;
				if (j != tmp2->data)
					k++;
			}
			tmp = tmp->next;
		}
		count--;
	}
	return (k);
} */

int ft_checklst(t_ps **lst, int count)
{
	int		j;
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst)
		return (0);
	tmp = *lst;
	while (count > 0)
	{
		while (tmp->next)
		{
			j = tmp->data;
			tmp2 = tmp;
			while (tmp2->next)
			{
				tmp2 = tmp2->next;
				if (j == tmp2->data)
					return (0);
			}
			tmp = tmp->next;
		}
		count--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	j;
	t_ps	*stack = NULL;
	t_ps2	*stack2 = NULL;

	j = -1;
	if (argc == 3)
	{
		while (++j < argc - 1)
		{
			ft_lst_addlast(&stack, argv[j + 1]);
		}
		ft_printf("\033[0;32mLa Liste AVANT modif :\033[0m\n");
		ft_printlst(&stack);
		if (ft_checklst(&stack, argc - 1) == 0)
		{
			ft_printf("\033[0;32mDoublon dans la liste!!\033[0m\n");
			ft_clean_lst(&stack);
			return (0);
		}
		if (stack->data > stack->next->data)
			ft_sa(&stack);
		ft_printf("\033[0;32mLa Liste APRES modif :\033[0m\n");
		ft_printlst(&stack);
		ft_clean_lst(&stack);
	}
	j = -1;
	if (argc == 4)
	{
		while (++j < argc - 1)
		{
			ft_lst_addlast(&stack, argv[j + 1]);
		}
		ft_printf("\033[0;32mLa Liste AVANT modif :\033[0m\n");
		ft_printlst(&stack);
		if (ft_checklst(&stack, argc - 1) != argc - 1)
		{
			ft_printf("\033[0;32mDoublon dans la liste :\033[0m\n");
			ft_clean_lst(&stack);
			return (0);
		}
//		ft_rra(&stack);
		ft_rrr(&stack,&stack2);
		ft_printf("\033[0;32mLa Liste APRES modif :\033[0m\n");
		ft_printlst(&stack);
		ft_clean_lst(&stack);
	}
	j = -1;
	if (argc > 4)
	{
		while (++j < argc - 1)
		{
			ft_lst_addlast(&stack, argv[j + 1]);
		}
		ft_printf("\033[0;32mLa Liste AVANT modif :\033[0m\n");
		ft_printlst(&stack);
//		ft_rra(&stack);
		ft_rrr(&stack,&stack2);
		ft_printf("\033[0;32mLa Liste APRES modif :\033[0m\n");
		ft_printlst(&stack);
		ft_clean_lst(&stack);
	}
/* 	if (argc > 1)
	{
		while (++j < argc - 1)
		{
			ft_lst_addfirst(&start, argv[j + 1]);
			ft_lst_addlast(&start2, argv[j + 1]);
		}
		ft_printf("\033[0;32mLa Liste dans les 2 sens AVANT modif :\033[0m\n");
		ft_printlst(&start);
		ft_printlst2(start2);
//		ft_rra(&start);
		ft_rrr(&start,&start2);
		ft_printf("\033[0;32mLa Liste dans les 2 sens APRES modif :\033[0m\n");
		ft_printlst(&start);
		ft_printlst2(start2);
		ft_clean_lst(&start);
		ft_clean_lst2(&start2);
	} */
	return 0;
}
