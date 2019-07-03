#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

// typedef struct	s_p
// {
// 	long	*a;
// 	long	*b;
// 	long 	*clone;
// 	long	*min;
// 	long	*max;
// 	int		tab;
// 	int		size;
// 	int		done;
// 	int		nb;
// 	int		sizemin;
// 	int		sizemax;
// }				t_p;

typedef struct	s_p
{
	long	*a;
	long	*b;
	long 	*clone;
	int		tab;
	int		size;
	int		done;
	int		brute;
	int		nb;
}				t_p;

t_p		algo(t_p *p);
t_p		sa(t_p *p, int mode);
t_p		sb(t_p *p, int mode);
t_p		ss(t_p *p, int mode);
t_p		pa(t_p *p, int mode);
t_p		pb(t_p *p, int mode);
t_p		ra(t_p *p, int mode);
t_p		rb(t_p *p, int mode);
t_p		rr(t_p *p, int mode);
t_p		rra(t_p *p, int mode);
t_p		rrb(t_p *p, int mode);
t_p		rrr(t_p *p, int mode);
void	swap(long *a, long *b);
void	ft_exit(t_p *p, int mode);
t_p		brute_force(t_p *p);
int		is_sorted(int size, long* tab);
#endif
