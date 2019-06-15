#include "push_swap.h"

t_p rra(t_p *p)
{
	int i = p->size - 2;

	while(i >= 0)
	{
		if (p->a[i] == 10000000000)
			break;
		swap(&(p->a[i]),&(p->a[i+1]));
		i--;
	}
	ft_putstr("rra\n");
	return (*p);
}

t_p rrb(t_p *p)
{
	int i = p->size - 2;

	while(i >= 0)
	{
		if (p->b[i] == 10000000000)
			break;
		swap(&(p->b[i]),&(p->b[i+1]));
		i--;
	}
	ft_putstr("rrb\n");
	return (*p);
}

t_p rrr(t_p *p)
{
	int i = p->size - 2;

	while(i >= 0)
	{
		if (p->b[i] == 10000000000)
			break;
		swap(&(p->b[i]),&(p->b[i+1]));
		i--;
	}
	i = p->size - 2;
	while(i >= 0)
	{
		if (p->a[i] == 10000000000)
			break;
		swap(&(p->a[i]),&(p->a[i+1]));
		i--;
	}
	ft_putstr("rr\n");
	return (*p);
}
