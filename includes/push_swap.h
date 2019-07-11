#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct	s_p
{
	int		ac;
	long	*a;
	long	*b;
	long 	*clone;
	int		size;
	int		range;
	int		nb_left;
	int		nb_operation;
	int		done;
}				t_p;

void	algo(t_p *p);
void	sa(t_p *p, int mode);
void	sb(t_p *p, int mode);
void	ss(t_p *p, int mode);
void	pa(t_p *p, int mode);
void	pb(t_p *p, int mode);
void	ra(t_p *p, int mode);
void	rb(t_p *p, int mode);
void	rr(t_p *p, int mode, int i, int j);
void	rra(t_p *p, int mode);
void	rrb(t_p *p, int mode);
void	rrr(t_p *p, int mode);
void	swap(long *a, long *b);
void	ft_exit(int mode, t_p *p);
void	fill(char ***split, t_p *p);
void	brute_force(t_p *p);
int		is_sorted(int size, long* tab);
void	apply_algo(t_p *p);
int		find_top(long l, t_p *p, int mode, int i);
int		find_bot(t_p *p, int mode, int j);
#endif
