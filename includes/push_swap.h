#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct	s_p
{
	long	*a;
	long	*b;
	int		size;
	int		done;
}				t_p;

t_p		sa(t_p *p);
t_p		sb(t_p *p);
t_p		ss(t_p *p);
t_p		pa(t_p *p);
t_p		pb(t_p *p);
t_p		ra(t_p *p);
t_p		rb(t_p *p);
t_p		rr(t_p *p);
t_p		rra(t_p *p);
t_p		rrb(t_p *p);
t_p		rrr(t_p *p);
void	swap(long *a, long *b);

#endif
