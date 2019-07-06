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
	int		ac;
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
void	ft_exit(int mode);
void	fill(char ***split, t_p *p);
void		brute_force(t_p *p);
int		is_sorted(int size, long* tab);
#endif
