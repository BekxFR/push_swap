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

void	ft_printlst(t_ps **start, t_ps2 **start2)
{
	t_ps *tmp;
	t_ps2 *tmp2;

	tmp = *start;
	tmp2 = *start2;
	ft_printf(" Valeur A - Index A - Valeur B - Index B \n");
	while (tmp)
	{
		if (tmp2)
		{
			if (tmp->next)
				ft_printf(" %d | %d | %d | %d \n", tmp->data, tmp->index, tmp2->data, tmp2->index);
			else
				ft_printf(" %d | %d | %d | %d ", tmp->data, tmp->index, tmp2->data, tmp2->index);
			tmp2 = tmp2->next;
		}
		else
		{
			if (tmp->next)
				ft_printf(" %d | %d | - | - \n", tmp->data, tmp->index);
			else
				ft_printf(" %d | %d | - | - ", tmp->data, tmp->index);
		}
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_printlsttried(t_ps *start)
{
	t_ps *tmp;

	tmp = start;
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

void	ft_lst_addlast(t_ps **lst, int i)
{
	t_ps *tmp;
	t_ps *tmp2;

	tmp = (t_ps *)malloc(sizeof (t_ps));
	if (!tmp)
		return ;
	tmp->data = i;
	tmp->index = 1;
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

void ft_push_list(t_ps **lst, const char *nptr)
{
	long int	i;

	i = ft_long_atoi(nptr);
	if (i == 999999999999)
	{
		ft_printf("\033[0;31mError\033[0m\n");
		ft_clean_lst(lst);
		return ;
	}
	ft_lst_addlast(lst, i);
}

int ft_tried_list(t_ps **lst)
{
	t_ps	*tmp;

	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void ft_control_list(t_ps **stack, const char *nptr, int argc)
{
	ft_push_list(stack, nptr);
	if (*stack)
	{
		ft_printf("\033[0;31mTEST\033[0m\n");
//		if (ft_checklst(stack, argc - 1) == 0 || ft_tried_list(stack) == 0) OK A REMETTRE AVNT PUSH
		if (ft_checklst(stack, argc - 1) == 0)
		{
			ft_printf("\033[0;31mDoublon dans la liste!!\033[0m\n");
			ft_clean_lst(stack);
			return ;
		}
	}
}

/* void	ft_index_list(t_ps **lst, int argc)
{
	t_ps *tmp;
	t_ps *tmp2;
	int i;

	i = -1;
	tmp = *lst;
	tmp2 = *lst;
	while (argc > ++i)
	{
		if (i == 0)
			tmp->index = 1;
		while (tmp->next)
		{
			while (tmp2->next){
				if (tmp->data > tmp2->data && tmp->index < tmp2->index)
				{
					tmp2->next->index = tmp->index;
					tmp->index = tmp->index + 1;
				}
				if (tmp2->next->index == 0)
					tmp2->next->index = tmp2->index + 1;
				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
			tmp2 = tmp;
		}
		tmp = *lst;
	}
} */

void	ft_index_list(t_ps **lst)
{
	t_ps *tmp;
	t_ps *tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp2->data > tmp->data)
				tmp2->index = tmp2->index + 1;
			tmp = tmp->next;
		}
		tmp = *lst;
		tmp2 = tmp2->next;
	}
}

void ft_tri_list(t_ps **stack, t_ps2 **stack2, int argc)
{
	ft_printf("\033[0;32mLa Liste AVANT modif :\033[0m\n");
	ft_printlst(stack, stack2);
	if (argc == 3 && (*stack)->data > (*stack)->next->data)
	{
		ft_printf("\033[0;36msa\033[0m\n");
		ft_sa(stack);
	}
	if (argc >= 5)
	{
		ft_index_list(stack);
		ft_pb(stack, stack2);
//		ft_sa(stack);
/* 		ft_pb(stack, stack2);
		ft_pa(stack, stack2);
		ft_pb(stack, stack2);
		ft_pb(stack, stack2);
		ft_pb(stack, stack2);
		ft_ss(stack, stack2);
		ft_rr(stack, stack2);
		ft_rrr(stack, stack2);
		ft_rrr(stack, stack2);
		ft_rrr(stack, stack2); */
	}
	ft_printf("\033[0;32mLa Liste APRES modif :\033[0m\n");
	ft_printlst(stack, stack2);
	ft_clean_lst(stack);
	ft_clean_lst2(stack2);
}

int	main(int argc, char **argv)
{
	int	j;
	t_ps	*stack = NULL;
	t_ps2	*stack2 = NULL;

	j = -1;
	ft_printf("\033[0;32mINT_MAX :%d , INT_MIN :%d\033[0m\n", INT_MAX, INT_MIN);
	if (argc > 2)
	{
		while (++j < argc - 1)
		{
			ft_control_list(&stack, argv[j + 1], argc - 1);
			if (!stack)
				return (0);
		}
		if (ft_tried_list(&stack) == 0 && stack) // Temporaire
		{ // Temporaire
			ft_printf("\033[0;31mListe triee!!\033[0m\n"); // Temporaire
			ft_printlsttried(stack); // Temporaire
			ft_clean_lst(&stack); // Temporaire
		} // Temporaire
		if (stack)
			ft_tri_list(&stack, &stack2, argc);
	}	
	return 0;
}
