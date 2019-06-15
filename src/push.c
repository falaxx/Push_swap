#include "push_swap.h"

t_p pa(t_p *p)
{
	int i = 0;
	int j = 0;
	while(i < p->size)
	{
		while (p->b[j] == 10000000000)
			j++;
		while (p->a[i] == 10000000000)
			i++;
		swap(&(p->a[i-1]),&(p->b[j]));
		break;
	}
	ft_putstr("pa\n");
	return (*p);
}

t_p pb(t_p *p)
{
	int i = 0;
	int j = 0;
	while(i < p->size)
	{
		while (p->b[j] == 10000000000)
			j++;
		while (p->a[i] == 10000000000)
			i++;
		swap(&(p->a[i]),&(p->b[j-1]));
		break;
	}
	ft_putstr("pb\n");
	return (*p);
}
