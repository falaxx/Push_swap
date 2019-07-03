#include "push_swap.h"

void	swap(long *a, long *b)
{
	long tmpa;
	long tmpb;

	tmpa = *a;
	tmpb = *b;
	*a = tmpb;
	*b = tmpa;
}

t_p sa(t_p *p, int mode)
{
	int i = 0;
	while(i < p->size)
	{
		while (p->a[i] == 10000000000)
			i++;
		swap(&(p->a[i]),&(p->a[i+1]));
		break;
	}
	if (mode == 1)
		ft_putstr("sa\n");
	return (*p);
}

t_p sb(t_p *p, int mode)
{
	int i = 0;
	while(i < p->size)
	{
		while (p->b[i] == 10000000000)
			i++;
		swap(&(p->b[i]),&(p->b[i+1]));
		break;
	}
	if (mode == 1)
		ft_putstr("sb\n");
	return (*p);
}

t_p ss(t_p *p, int mode)
{
	int i = 0;
	while(i < p->size)
	{
		while (p->b[i] == 10000000000)
			i++;
		swap(&(p->b[i]),&(p->b[i+1]));
		break;
	}
	i = 0;
	while(i < p->size)
	{
		while (p->a[i] == 10000000000)
			i++;
		swap(&(p->a[i]),&(p->a[i+1]));
		break;
	}
	if (mode == 1)
		ft_putstr("ss\n");
	return (*p);
}
