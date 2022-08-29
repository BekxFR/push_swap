#include "push_swap.h"

void	ft_sa(t_ps **lst)
{
	t_ps *tmp;
	t_ps *tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	tmp2->next = tmp;
	*lst = tmp2;
}

void	ft_sb(t_ps **lst)
{
	t_ps *tmp;
	t_ps *tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	tmp2->next = tmp;
	*lst = tmp2;
}

void	ft_ss(t_ps **lst, t_ps **lst2)
{
	ft_sa(lst);
	ft_sb(lst2);
}

void	ft_pa(t_ps **lst, t_ps **lst2)
{
	t_ps *tmp;

	if (!*lst2)
		return;
	tmp = *lst2;
	if (!(*lst2)->next)
		(*lst2) = NULL;
	else
		(*lst2) = (*lst2)->next;
	if (!*lst)
		tmp->next = NULL;
	else
		tmp->next = *lst;
	*lst = tmp;
}

void	ft_pb(t_ps **lst, t_ps **lst2)
{
	t_ps *tmp;

	if (!*lst)
		return;
	tmp = *lst;
	(*lst) = (*lst)->next;
	if (!*lst2)
		tmp->next = NULL;
	else
		tmp->next = *lst2;
	*lst2 = tmp;
}

void	ft_ra(t_ps **lst)
{
	t_ps *tmp;
	t_ps *tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = (*lst)->next;
	*lst = tmp2;
	tmp->next = NULL;
 	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
}

void	ft_rb(t_ps **lst)
{
	t_ps *tmp;
	t_ps *tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = (*lst)->next;
	*lst = tmp2;
	tmp->next = NULL;
 	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
}

void	ft_rr(t_ps **lst, t_ps **lst2)
{
	if (*lst)
		ft_ra(lst);
	if (*lst2)
		ft_rb(lst2);
}

void	ft_rra(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		if (!tmp->next->next)
		{
			tmp2 = tmp->next;
			tmp2->next = *lst;
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	*lst = tmp2;
}

void	ft_rrb(t_ps **lst)
{
	t_ps	*tmp;
	t_ps	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		if (!tmp->next->next)
		{
			tmp2 = tmp->next;
			tmp2->next = *lst;
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	*lst = tmp2;
}

void	ft_rrr(t_ps **lst, t_ps **lst2)
{
	if (*lst)
		ft_rra(lst);
	if (*lst2)
		ft_rrb(lst2);
}

/* void	ft_costa_tob(t_ps **lst, t_ps **lst2)
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
				if (tmp->cost_a < 0 && tmp2->cost_b >= 0)
					tmp2->cost_a = tmp2->cost_b + (tmp->cost_a * -1);
				else if (tmp2->cost_b < 0 && tmp->cost_a >= 0)
					tmp2->cost_a = (tmp2->cost_b * -1) + tmp->cost_a;
				else
					tmp2->cost_a = tmp->cost_a + tmp2->cost_b;
			}
			tmp = tmp->next;
		}
		tmp = *lst;
		tmp2 = tmp2->next;
	}
} */