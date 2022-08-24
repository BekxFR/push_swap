#include "push_swap.h"

void	ft_sa(t_ps **lst)
{
	t_ps *tmp;
	t_ps *tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = tmp->next;
	tmp2->next = tmp;
	tmp->next = tmp->next->next;
	*lst = tmp2;
}

void	ft_sb(t_ps2 **lst)
{
	t_ps2 *tmp;
	t_ps2 *tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	tmp2 = tmp->next;
	tmp2->next = tmp;
	tmp->next = tmp->next->next;
	*lst = tmp2;
}

void	ft_ss(t_ps **lst, t_ps2 **lst2)
{
	ft_sa(lst);
	ft_sb(lst2);
}

void	ft_pa(t_ps **lst, t_ps2 **lst2)
{
	t_ps *tmp;
	t_ps2 *tmp2;

	if (!*lst2)
		return;
	tmp = (t_ps *)malloc(sizeof(t_ps));
	if (!tmp)
		return ;
	tmp2 = *lst2;
	tmp->data = tmp2->data;
	tmp->index = tmp2->index;
	if (!*lst)
		tmp->next = NULL;
	else
		tmp->next = *lst;
	*lst = tmp;
	*lst2 = tmp2->next;
	free(tmp2);
}

void	ft_pb(t_ps **lst, t_ps2 **lst2)
{
	t_ps *tmp;
	t_ps2 *tmp2;

	if (!*lst)
		return;
/* 	tmp2 = (t_ps2 *)malloc(sizeof(t_ps2));
	if (!tmp2)
		return ; */
	tmp = *lst;
	tmp2 = *lst2;
/* 	tmp2->data = tmp->data;
	tmp2->index = tmp->index; */
	if (!*lst2)
		tmp2->next = NULL;
	else
		tmp2->next = *lst2;
	*lst2 = tmp2;
	lst = &tmp->next;
	free(tmp);
}

void	ft_ra(t_ps **lst)
{
	t_ps *tmp;
	int i;
	int j;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = *lst;
	i = tmp->data;
	while (tmp->next)
	{
		j = tmp->next->data;
		tmp->data = j;
		tmp = tmp->next;
	}
	tmp->data = i;
	return ;
}

void	ft_rb(t_ps2 **lst)
{
	t_ps2 *tmp;
	int i;
	int j;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = *lst;
	i = tmp->data;
	while (tmp->next)
	{
		j = tmp->next->data;
		tmp->data = j;
		tmp = tmp->next;
	}
	tmp->data = i;
	return ;
}

void	ft_rr(t_ps **lst, t_ps2 **lst2)
{
	if (*lst)
		ft_ra(lst);
	if (*lst2)
		ft_rb(lst2);
}

void	ft_rra(t_ps **lst)
{
	int	i;
	int	j;
	int	k;
	t_ps	*tmp;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = *lst;
	j = tmp->data;
	while (tmp->next)
	{
		if (!tmp->next->next)
			i = tmp->next->data;
		tmp = tmp->next;
		k = tmp->data;
		tmp->data = j;
		j = k;
	}
	(*lst)->data = i;
}

void	ft_rrb(t_ps2 **lst)
{
	int	i;
	int	j;
	int	k;
	t_ps2	*tmp;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = *lst;
	j = tmp->data;
	while (tmp->next)
	{
		if (!tmp->next->next)
			i = tmp->next->data;
		tmp = tmp->next;
		k = tmp->data;
		tmp->data = j;
		j = k;
	}
	(*lst)->data = i;
}

void	ft_rrr(t_ps **lst, t_ps2 **lst2)
{
	if (*lst)
		ft_rra(lst);
	if (*lst2)
	ft_rrb(lst2);
}