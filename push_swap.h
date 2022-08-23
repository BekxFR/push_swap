#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

typedef struct	ps_list
{
	int				data; // valeur
	int				index; // pos list full
	int				pos; // pos actuelle
	int				target_pos; // pos finale dans SA de l'elem dans SB
	int				cost_a; // nbre d'actions TOP of SA
	int				cost_b; // nbre d'actions TOP of SB
	struct ps_list	*next;
}	t_ps;

typedef struct	ps_list2
{
	int					data;
	int					index;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct	ps_list2	*next;
}	t_ps2;

void	ft_sa(t_ps **lst);
void	ft_sb(t_ps2 **lst);
void	ft_ss(t_ps **lst, t_ps2 **lst2);
void	ft_pa(t_ps **lst, t_ps2 **lst2);
void	ft_pb(t_ps **lst, t_ps2 **lst2);
void	ft_ra(t_ps **lst);
void	ft_rb(t_ps2 **lst);
void	ft_rr(t_ps **lst, t_ps2 **lst2);
void	ft_rra(t_ps **lst);
void	ft_rrb(t_ps2 **lst);
void	ft_rrr(t_ps **lst, t_ps2 **lst2);

#endif