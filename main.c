#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

int	ft_push_swap(int i)
{
	if (!i)
		return (0);
	return (i);
}

/* void	ft_printlsts(t_ps **start, t_ps **start2)
{
	t_ps *tmp;
	t_ps *tmp2;

	tmp = *start;
	tmp2 = *start2;
	ft_printf(" Valeur A - Index A - Valeur B - Index B \n");
	while (tmp || tmp2)
	{
		if (tmp2 && tmp)
		{
			if (tmp->next || tmp2->next)
				ft_printf(" %d | %d | %d | %d \n", tmp->data, tmp->index, tmp2->data, tmp2->index);
			else
				ft_printf(" %d | %d | %d | %d ", tmp->data, tmp->index, tmp2->data, tmp2->index);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		else if (!tmp2)
		{
			if (tmp->next)
				ft_printf(" %d | %d | - | - \n", tmp->data, tmp->index);
			else
				ft_printf(" %d | %d | - | - ", tmp->data, tmp->index);
			tmp = tmp->next;
		}
		else if (!tmp)
		{
			if (tmp2->next)
				ft_printf(" - | - | %d | %d \n", tmp2->data, tmp2->index);
			else
				ft_printf(" - | - | %d | %d ", tmp2->data, tmp2->index);
			tmp2 = tmp2->next;
		}
	}
	ft_printf("\n");
} */

void	ft_printlsts(t_ps **start, t_ps **start2)
{
	t_ps *tmp;
	t_ps *tmp2;

	tmp = *start;
	tmp2 = *start2;
	ft_printf(" VA\t| IA\t| PA\t| TPA\t| CA\t| VB\t| IB\t| PB\t| TPB\t| CA\t| CB\n");
	while (tmp || tmp2)
	{
		if (tmp2 && tmp)
		{
			if (tmp->next || tmp2->next)
				ft_printf(" %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t\n",
				 tmp->data, tmp->index, tmp->pos, tmp->target_pos, tmp->cost_a, tmp2->data, tmp2->index, tmp2->pos, tmp2->target_pos, tmp2->cost_a, tmp2->cost_b);
			else
				ft_printf(" %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t",
				 tmp->data, tmp->index, tmp->pos, tmp->target_pos, tmp->cost_a, tmp2->data, tmp2->index, tmp2->pos, tmp2->target_pos, tmp2->cost_a, tmp2->cost_b);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		else if (!tmp2)
		{
			if (tmp->next)
				ft_printf(" %d\t| %d\t| %d\t| %d\t| %d\t| -\t| -\t| -\t| -\t| -\t\n", tmp->data, tmp->index, tmp->pos, tmp->target_pos, tmp->cost_a);
			else
				ft_printf(" %d\t| %d\t| %d\t| %d\t| %d\t| -\t| -\t| -\t| -\t| -\t", tmp->data, tmp->index, tmp->pos, tmp->target_pos, tmp->cost_a);
			tmp = tmp->next;
		}
		else if (!tmp)
		{
			if (tmp2->next)
				ft_printf(" -\t| -\t| -\t| -\t| -\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t\n", tmp2->data, tmp2->index, tmp2->pos, tmp2->target_pos, tmp2->cost_a, tmp2->cost_b);
			else
				ft_printf(" -\t| -\t| -\t| -\t| -\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t", tmp2->data, tmp2->index, tmp2->pos, tmp2->target_pos, tmp2->cost_a, tmp2->cost_b);
			tmp2 = tmp2->next;
		}
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
	tmp->pos = 0; // TMP
	tmp->target_pos = 0; // TMP
	tmp->cost_a = 0; // TMP
	tmp->cost_b = 0; // TMP
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
		ft_printf("Error\n");
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
		if (ft_checklst(stack, argc - 1) == 0)
		{
			ft_printf("Error\n");
			ft_clean_lst(stack);
			return ;
		}
	}
}

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

void	ft_trio_list(t_ps **stack, int argc)
{
	t_ps *tmp;

	tmp = *stack;
	argc = 0;
	while (tmp)
	{
		if (argc < tmp->index)
			argc = tmp->index;
		tmp = tmp->next;
	}
	if ((*stack)->index == argc)
	{
		ft_ra(stack); //
		ft_printf("ra\n");
	}
	if ((*stack)->next->index == argc)
	{
		ft_rra(stack); //
		ft_printf("rra\n");
	}
	if ((*stack)->index > (*stack)->next->index)
	{
		ft_sa(stack); //
		ft_printf("sa\n");
	}
}

void	ft_pull_rest(t_ps **stack, t_ps **stack2, int count, int argc)
{
	t_ps	*tmp;

	tmp = *stack;
	while (count < argc - 3)
	{
		ft_pb(stack, stack2);
		ft_printf("pb\n");
		tmp = *stack;
		tmp = tmp->next;
		count++;
	}
}

void	ft_pull_lowtob(t_ps **stack, t_ps **stack2, int argc)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	int		count;

	tmp = *stack;
	tmp2 = *stack;
	count = 0;
	while (count != argc / 2 - 1)
	{
		if (tmp->index < argc / 2 && count++ != argc / 2 - 1)
		{
			ft_pb(stack, stack2);
			ft_printf("pb\n");
		}
		else
		{
			ft_ra(stack);
			ft_printf("ra\n");
		}
		tmp = *stack;
		tmp2 = *stack;
		tmp2 = tmp2->next;
	}
	if (tmp->next->next->next)
		ft_pull_rest(stack, stack2, count, argc);
}

void	ft_pos_lst(t_ps **lst, t_ps **lst2)
{
	int		i;
	t_ps	*tmp;

	i = 0;
	tmp = *lst;
	if (tmp)
	{
		while (tmp)
		{
			tmp->pos = i++;
			tmp = tmp->next;
		}
	}
	i = 0;
	tmp = *lst2;
	if (tmp)
	{
		while (tmp)
		{
			tmp->pos = i++;
			tmp = tmp->next;
		}
	}
}

int	ft_index_inf(t_ps **lst, t_ps **lst2)
{
	int i;

	(*lst2)->target_pos = (*lst)->pos;
	i = (*lst)->index;
	return (i);
}

void	ft_index_supp(t_ps **lst, t_ps **lst2, int argc)
{
	t_ps *tmp;
	int i;

//	ft_printf("TEST TEST\n");
	tmp = *lst;
	while (tmp)
	{
		if (tmp->index < argc)
		{
			argc = tmp->index;
			i = tmp->pos;
		}
		tmp = tmp->next;
	}
	(*lst2)->target_pos = i;
}

void	ft_targpos_lst(t_ps **lst, t_ps **lst2, int argc)
{
	t_ps	*tmp;
	t_ps	*tmp2;
	int		i;
	int		j;

	tmp = *lst2;
	tmp2 = *lst;
	while (tmp)
	{
		i = argc;
		j = argc;
		while (tmp2)
		{
			if (tmp->index < tmp2->index && i > tmp2->index)
			{
				i = ft_index_inf(&tmp2, &tmp);
				j = 0;
			}
			tmp2 = tmp2->next;
		}
		if (j)
			ft_index_supp(lst, &tmp, argc);
		tmp2 = *lst;
		tmp = tmp->next;
	}
}

void	ft_top_costa(t_ps **lst)
{
	int	i;
	int	j;
	t_ps	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	j = 0;
	while (tmp && ++j)
		tmp = tmp->next;
	tmp = *lst;
	while (tmp)
	{
		i = tmp->pos;
		if (i < (j / 2))
			tmp->cost_a = i;
		if (i >= (j / 2))
		{
			if ((j % 2 != 0) && (j / 2 == i))
				tmp->cost_a = (i);
			else
				tmp->cost_a = (-j + i);
		}
		tmp = tmp->next;
	}
}

void	ft_costa_tob(t_ps **lst, t_ps **lst2)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	tmp = *lst;
	tmp2 = *lst2;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp2->target_pos == tmp->pos)
			{
				tmp2->cost_a = tmp->cost_a;
			}
			tmp = tmp->next;
		}
		tmp = *lst;
		tmp2 = tmp2->next;
	}
}

void	ft_top_costb(t_ps **lst)
{
	int	i;
	int	j;
	t_ps	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	j = 0;
	while (tmp && ++j)
		tmp = tmp->next;
	tmp = *lst;
	while (tmp)
	{
		i = tmp->pos;
		if (i < (j / 2))
			tmp->cost_b = i;
		if (i >= (j / 2))
		{
			if ((j % 2 != 0) && (j / 2 == i))
				tmp->cost_b = (i);
			else
				tmp->cost_b = (-j + i);
		}
		tmp = tmp->next;
	}
}

int	ft_low_count(t_ps **lst2)
{
	int		i;
	t_ps	*tmp2;

	tmp2 = *lst2;
	i = 0;
	while (tmp2)
	{
		if (tmp2->cost_a < 0 && tmp2->cost_b >= 0)
			i = tmp2->cost_b + (tmp2->cost_a * -1);
		else if (tmp2->cost_b < 0 && tmp2->cost_a >= 0)
			i = (tmp2->cost_b * -1) + tmp2->cost_a;
		else
			i = tmp2->cost_a + tmp2->cost_b;
		tmp2 = tmp2->next;
	}
	return (i);
}

void	ft_choice_elem(t_ps **lst, t_ps **lst2)
{
	int		i;
	int		j;
	int		k;
	t_ps	*tmp2;
	
	i = ft_low_count(lst2);

	tmp2 = *lst2;
	while (tmp2)
	{
		if (i == ft_low_count(&tmp2))
		{
			j = tmp2->cost_a;
			k = tmp2->cost_b;
			while (j != 0)
			{
				if (j < 0 && k < 0)
				{
					ft_printf("rrr\n");
					ft_rrr(lst, lst2);
					j = j + 1;
					k = k + 1;
				}
				else if (j > 0 && k > 0)
				{
					ft_printf("rr\n");
					ft_rr(lst, lst2);
					j = j - 1;
					k = k - 1;
				}
				else if (j < 0)
				{
					ft_printf("rra\n");
					ft_rra(lst);
					j = j + 1;
				}
				else if (j > 0)
				{
					ft_printf("ra\n");
					ft_ra(lst);
					j = j - 1;
				}
			}
			while (k != 0)
			{
				if (k < 0)
				{
					ft_printf("rb\n");
					ft_rb(lst2);
					k = k + 1;
				}
				else if (k > 0)
				{
					ft_printf("rrb\n");
					ft_rrb(lst2);
					k = k - 1;
				}
			}
			ft_printf("pa\n");
			ft_pa(lst, lst2);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void	ft_order_rest(t_ps **lst)
{
	int		i;
	t_ps *tmp;

	tmp = *lst;
	while (tmp && tmp->index != 1)
		tmp = tmp->next;
	i = tmp->cost_a;
//	ft_printf("VALEUR DE COST_A (I): %d\n", i);
	tmp = *lst;
	if (i < 0)
	{
		while (i)
		{
			ft_printf("rra\n");
			ft_rra(lst);
			i = i + 1;
		}
		while (i)
		{
			ft_printf("ra\n");
			ft_ra(lst);
			i = i - 1;
		}
	}
}

void	ft_tri_list(t_ps **stack, t_ps **stack2, int argc)
{
//	ft_printf("\033[0;32mLa Liste AVANT modif :\033[0m\n");
//	ft_printlsts(stack, stack2);
	if (argc == 3 && (*stack)->data > (*stack)->next->data)
	{
		ft_printf("sa\n");
		ft_sa(stack);
	}
	if (argc == 4)
	{
		ft_index_list(stack);
//		ft_printlsts(stack, stack2);
		ft_trio_list(stack, argc);
	}
	if (argc > 4)
	{
		ft_index_list(stack);
		ft_pull_lowtob(stack, stack2, argc - 1);
		ft_trio_list(stack, argc);
//		ft_printlsts(stack, stack2);
		ft_pos_lst(stack, stack2);
		ft_targpos_lst(stack, stack2, argc - 1);
//		ft_printlsts(stack, stack2); // 
		while (*stack2)
		{
			ft_top_costa(stack);
			ft_top_costb(stack2);
//			ft_printlsts(stack, stack2); // 
			ft_costa_tob(stack, stack2);
//			ft_printlsts(stack, stack2); // 
			ft_choice_elem(stack, stack2);
			ft_pos_lst(stack, stack2);
			ft_targpos_lst(stack, stack2, argc);
		}
//		ft_printf("\033[0;32m1TEST 1TEST\033[0m\n");
//		ft_printlsts(stack, stack2); // 
		ft_pos_lst(stack, stack2);
		ft_top_costa(stack);
//		ft_printf("\033[0;32m3TEST 3TEST\033[0m\n");
//		ft_printlsts(stack, stack2); // 
		ft_order_rest(stack);
	}  
//	ft_printf("\033[0;32mLa Liste APRES modif :\033[0m\n");
//	ft_printlsts(stack, stack2);
	ft_clean_lst(stack);
	ft_clean_lst(stack2);
}

int	main(int argc, char **argv)
{
	int	j;
	t_ps	*stack = NULL;
	t_ps	*stack2 = NULL;

	j = -1;
//	ft_printf("\033[0;32mINT_MAX :%d , INT_MIN :%d\033[0m\n", INT_MAX, INT_MIN);
	if (argc > 2)
	{
		while (++j < argc - 1)
		{
			ft_control_list(&stack, argv[j + 1], argc - 1);
			if (!stack)
				return (0);
		}
		if (ft_tried_list(&stack) == 0 && stack)
		{
			ft_clean_lst(&stack);
		}
		if (stack)
			ft_tri_list(&stack, &stack2, argc);
	}	
	return 0;
}
