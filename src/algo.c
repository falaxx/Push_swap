#include "push_swap.h"
t_p fill_tab(t_p *p, int nb)
{
	int i;
	int j;

	j = 0;
	i = p->size - nb;
	while(i != p.size && j < 10)
	{
		p.min[j] = p.clone[j];
		j++;
		i++;
	}
	i = p->size -1;
	if (j == 10 && nb != p->size -1)
	while (i != p->size - nb && j < 20)
	{

	}

}

t_p		min_max(t_p *p)
{
	int i = 0;
	int nb = 0;

	while(i < p->size)
	{
		if (p->clone[i] != 10000000000)
			nb++;
		i++;
	}
	i = p->size - nb;
	while(i < p->size - 1)
	{
		if (p->clone[i] > p->clone[i+1])
		{
			swap(&(p->clone[i]), &(p->clone[i+1]));
			i = p->size - nb - 1;
		}
		i++;
	}
	i = p->size - nb - 1;
	*p = fill_tab(p, nb);
	// while(found != (10 - (10 - nb)
	// {
	//
	// 	found ++;
	// }
	return(*p);
}

t_p		algo(t_p *p)
{
	int i = 0;
	// while(p->done = 0)
	// {
		while(i < p->size)
		{
			p->clone[i] = p->a[i];
			i++;
		}
		*p = min_max(p);
	// }
	return(*p);
}
