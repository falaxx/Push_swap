#include "push_swap.h"
t_p fill_tab(t_p *p, int nb)
{
	int i;
	int j;
	int k;

	k = p->tab;
	j = 0;
	i = p->size - nb;
	while(i != p->size && j < p->tab)
	{
		p->min[j] = p->clone[i];
		j++;
		i++;
	}
	p->sizemin = j;
	j = 0;
	while (i + j < p->size)
		j++;
	i = p->size - p->tab;
	if(j < p->tab)
		i = p->size - j;
	j = 0;
	while (i != p->size && j < p->tab)
	{
		p->max[p->tab - k] = p->clone[i];
		k--;
		i++;
		j++;
	}
	p->sizemax = j;
// printf("min = %d max = %d",p->sizemin,p->sizemax);
	return (*p);
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
	return(*p);
}

int		find_in_tab(long l, long* tab, int size)
{
	int i = 0;
	while (i < size)
	{
		if (tab[i] == l)
			return (1);
		i++;
	}
	return (0);
}
//
t_p		is_min_max(t_p *p)
{
	int i = 0;
	int j = 0;
	int k = 0;

	j = p->sizemax;
	k =  p->sizemin;

	while(k + j > 0)
	{
		while (p->a[i] == 10000000000)
			i++;
		if (j > 0)
		{
			if (find_in_tab(p->a[i], p->max, p->tab) == 1)
			{
				*p = pb(p);
				// *p = rb(p);
				p->nb += 1;
				j--;
			}
			if (find_in_tab(p->a[p->size-1], p->max, p->tab) == 1)
			{
				*p = rra(p);
				*p = pb(p);
				// *p = rb(p);
				p->nb += 2;
				j--;
			}
		}
		if (k > 0)
		{
			if (find_in_tab(p->a[i], p->min, p->tab) == 1)
			{
				*p = pb(p);
				*p = rb(p);
				p->nb += 2;
				k--;
			}
			if (find_in_tab(p->a[p->size-1], p->min, p->tab) == 1)
			{
				*p = rra(p);
				*p = pb(p);
				*p = rb(p);
				p->nb += 3;
				k--;
			}
		}
		i = 0;
		if (k + j == 0)
			break;
		// printf("j = %d k = %d",j,k);
		*p = ra(p);
		p->nb += 1;
	}
	p->done = 1;
	return (*p);
}
t_p find_max(t_p *p)
{
	int max;
	int i = 0;
	int j = 0;
	int dis = 0;

	while (p->b[i] == 10000000000)
		i++;
	j = i;
	max = p->b[i];
	while (i < p->size)
	{
		if (p->b[i] > max)
		{
			max = p->b[i];
			dis = i;
		}
		i++;
	}
	i = 0;
	while (p->b[i] == 10000000000)
		i++;
	while(p->b[i] != max)
	{
		if(dis - j < p->size - dis)
			*p = rb(p);
		else
			*p = rrb(p);
		p->nb += 1;
	}
	*p = pa(p);
	p->nb += 1;
	return (*p);
}

t_p		algo(t_p *p)
{
	int i = 0;
	while(p->done < 2)
	{
		i = 0;
		while(i < p->size)
		{
			p->clone[i] = p->a[i];
			i++;
		}
		*p = min_max(p);
		// printf("min = %d max = %d",p->sizemin,p->sizemax);
		*p = is_min_max(p);
		// i = 0;
		// while( i < p->sizemin )
		// {
		// 	printf("min[%d] = %ld\n",i, p->min[i]);
		// 	i++;
		// }
		// i = 0;
		// while( i < p->sizemax )
		// {
		// 	printf("max[%d] = %ld\n",i, p->max[i]);
		// 	i++;
		// }
		if (p->a[p->size - 1] == 10000000000)
			p->done = 2;
			// break;
	}

	while(p->done < 3)
	{
		*p = find_max(p);
		if (p->b[p->size - 1] == 10000000000)
			p->done = 3;
	}
	return(*p);
}
