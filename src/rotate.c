#include "push_swap.h"

t_p ra(t_p *p)
{
	int i = 0;
	int j = 0;

	while(i < p->size)
	{
		while (p->a[i] == 10000000000)
			i++;
		j = i;
		swap(&(p->a[i]),&(p->a[i+1]));
		i++;
	}
	swap(&(p->a[i]),&(p->a[j]));
	ft_putstr("ra\n");
	return (*p);
}

t_p rb(t_p *p)
{
	int j = 0;
	int i = 0;

	while(i < p->size)
	{
		while (p->b[i] == 10000000000)
			i++;
		j = i;
		swap(&(p->b[i]),&(p->b[i+1]));
		i++;
	}
	swap(&(p->b[i]),&(p->b[j]));
	ft_putstr("rb\n");
	return (*p);
}

t_p rr(t_p *p)
{
	int j = 0;
	int i = 0;

	while(i < p->size)
	{
		while (p->b[i] == 10000000000)
			i++;
		j = i;
		swap(&(p->b[i]),&(p->b[i+1]));
		i++;
	}
	swap(&(p->b[i]),&(p->b[j]));
	i = 0;
	j = 0;
	while(i < p->size)
	{
		while (p->a[i] == 10000000000)
			i++;
		j = i;
		swap(&(p->a[i]),&(p->a[i+1]));
		i++;
	}
	swap(&(p->a[i]),&(p->a[j]));
	ft_putstr("rr\n");
	return (*p);
}
