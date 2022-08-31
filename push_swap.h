/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:21:47 by chillion          #+#    #+#             */
/*   Updated: 2022/08/31 16:08:21 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

typedef struct ps_list
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct ps_list	*next;
}	t_ps;

void	ft_sa(t_ps **lst);
void	ft_sb(t_ps **lst);
void	ft_ss(t_ps **lst, t_ps **lst2);
void	ft_pa(t_ps **lst, t_ps **lst2);
void	ft_pb(t_ps **lst, t_ps **lst2);
void	ft_ra(t_ps **lst);
void	ft_rb(t_ps **lst);
void	ft_rr(t_ps **lst, t_ps **lst2);
void	ft_rra(t_ps **lst);
void	ft_rrb(t_ps **lst);
void	ft_rrr(t_ps **lst, t_ps **lst2);

void	ft_printlst(t_ps **start);
void	ft_clean_lst(t_ps **start);
void	ft_order_rest(t_ps **lst);
int		ft_find_index(t_ps **lst);
void	ft_choice_elem(t_ps **lst, t_ps **lst2);
void	ft_switch_costb(t_ps **lst2, int k);
int		ft_switch_costa(t_ps **lst, t_ps **lst2, int j, int k);
int		ft_switch_rra(t_ps **lst, int j);
int		ft_switch_ra(t_ps **lst, int j);
void	ft_switch_rr(t_ps **lst, t_ps **lst2);
void	ft_switch_rrr(t_ps **lst, t_ps **lst2);
int		ft_low_counter(t_ps **lst2);
int		ft_low_count(t_ps **lst2);
void	ft_top_costb(t_ps **lst);
void	ft_costa_tob(t_ps **lst, t_ps **lst2);
void	ft_top_costa(t_ps **lst);
void	ft_targpos_lst(t_ps **lst, t_ps **lst2, int argc);
void	ft_index_supp(t_ps **lst, t_ps **lst2, int argc);
int		ft_index_inf(t_ps **lst, t_ps **lst2);
void	ft_pos_lst(t_ps **lst, t_ps **lst2);
void	ft_pull_lowtob(t_ps **stack, t_ps **stack2, int argc);
void	ft_pull_rest(t_ps **stack, t_ps **stack2, int count, int argc);
void	ft_index_list(t_ps **lst);
void	ft_control_list(t_ps **stack, const char *nptr, int argc);
int		ft_tried_list(t_ps **lst);
void	ft_push_list(t_ps **lst, const char *nptr);
int		ft_checklst(t_ps **lst, int count);
void	ft_clean_lst(t_ps **start);
void	ft_lst_addlast(t_ps **lst, int i);
void	ft_lst_addfirst(t_ps **start, int i);
void	ft_printlst(t_ps **start);
void	ft_tri_list(t_ps **stack, t_ps **stack2, int argc);
void	tri_for_more3(t_ps **stack, t_ps **stack2, int argc);
void	ft_trio_list(t_ps **stack, int argc);

#endif