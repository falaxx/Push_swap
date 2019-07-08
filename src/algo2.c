#include "push_swap.h"





//
// void	apply_algo(p)
// {
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
//
// 	while(k + j > 0)
// 	{
// 		while (p->a[i] == 10000000000)
// 			i++;
// 		if (j > 0)
// 		{
// 			if (find_in_tab(p->a[i], p->max, p->tab) == 1)
// 			{
// 				*p = pb(p);
// 				// *p = rb(p);
// 				p->nb += 1;
// 				j--;
// 			}
// 			if (find_in_tab(p->a[p->size-1], p->max, p->tab) == 1)
// 			{
// 				*p = rra(p);
// 				*p = pb(p);
// 				// *p = rb(p);
// 				p->nb += 2;
// 				j--;
// 			}
// 		}
// 		if (k > 0)
// 		{
// 			if (find_in_tab(p->a[i], p->min, p->tab) == 1)
// 			{
// 				*p = pb(p);
// 				*p = rb(p);
// 				p->nb += 2;
// 				k--;
// 			}
// 			if (find_in_tab(p->a[p->size-1], p->min, p->tab) == 1)
// 			{
// 				*p = rra(p);
// 				*p = pb(p);
// 				*p = rb(p);
// 				p->nb += 3;
// 				k--;
// 			}
// 		}
// 		i = 0;
// 		if (k + j == 0)
// 			break;
// 		// printf("j = %d k = %d",j,k);
// 		*p = ra(p);
// 		p->nb += 1;
// 	}
// 	p->done = 1;
// 	return (*p);
// }

long	*sort(t_p *p, long *tab)
{
	int i = 0;
	int nb = 0;

	while(i < p->size)
	{
		if (tab[i] != 10000000000)
			nb++;
		i++;
	}
	i = p->size - nb;
	while(i < p->size - 1)
	{
		if (tab[i] > tab[i+1])
		{
			swap(&(tab[i]), &(tab[i+1]));
			i = p->size - nb - 1;
		}
		i++;
	}
	p->nb_left = nb;
	return(tab);
}

int		is_sorted(int size, long* tab)
{
	int i = 0;
	while (i < size - 1)
	{
		if (tab[i] < tab[i+1])
			i++;
		else
			return (0);
	}
	return (1);
}

int		find_in_tab(long l, long* tab, t_p *p, char *mode)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = p->range;
	while (tab[j] == 10000000000)
		j++;
	if (mode[0] == 't')
	{
		while (i < size)
		{
			if (tab[j + i] == l)
				return (1);
			i++;
		}
		return (0);
	}
	i = p->size -1;
	j = i - p->range;
	if (mode[0] == 'b')
	{
		while (i > j)
		{
			if (tab[i] == l)
				return (1);
			i--;
		}
	}
	return (0);
}


void	apply_algo(t_p *p)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (p->a[i] == 10000000000)
		i++;
	if (find_in_tab(p->a[i], p->clone, p,
	"top") == 1)
	{
		pb(p, 0);
		p->nb_operation += 1;
	}
	if (find_in_tab(p->a[p->size-1], p->clone, p,
	"top") == 1)
	{
		rra(p, 0);
		pb(p, 0);
		p->nb_operation += 2;
	}
	if (find_in_tab(p->a[i], p->clone, p,
	"bot") == 0)
	{
		pb(p, 0);
		rb(p, 0);
		p->nb_operation += 2;
	}
	if (find_in_tab(p->a[p->size-1], p->clone, p,
		"bot") == 1)
	{
		rra(p, 0);
		pb(p, 0);
		rb(p, 0);
		p->nb_operation += 3;
	}
	// printf("find in tab %zu = %d \n",p->a[i], find_in_tab(p->a[i], p->a, p->range,"top"));
	// if (find_in_tab(p->a[p->size-1], p->clone, p->range,
	// "bot") == 1)
	// {
	// 	rra(p, 0);
	// 	pb(p, 0);
	// 	p->nb_operation += 2;
	// }
	// if (p->nb_left >= p->range)
	// {
	// 	// while( k < p->size )
	// 	// {
	// 	// 	printf("a[%d] = %ld\n",k, p->a[k]);
	// 	// 	k++;
	// 	// }
	//
	// 	p->nb_operation += 1;
	// 	k = 0;
	// 	// sleep(1);
	// }
		ra(p, 0);
		p->nb_operation++;
}

void	algo(t_p *p)
{
	int i = 0;
	int k = 0;
	if (is_sorted(p->size, p->a) == 1)
		ft_exit(1, p);
		while( k < p->size )
		{
			printf("a[%d] = %ld\n",k, p->a[k]);
			k++;
		}
		k = 0;
		while( k < p->size )
		{
			printf("b[%d] = %ld\n",k, p->b[k]);
			k++;
		}
	while (1)
	{
		// printf("range = %d",p->range);
		i = 0;
		while(i < p->size)
		{
			p->clone[i] = p->a[i];
			i++;
		}
		p->clone = sort(p, p->clone);
		apply_algo(p);
		k = 0;
		// while( k < p->size )
		// {
		// 	printf("a[%d] = %ld\n",k, p->a[k]);
		// 	k++;
		// }
		// k = 0;
		// while( k < p->size )
		// {
		// 	printf("b[%d] = %ld\n",k, p->b[k]);
		// 	k++;
		// }
		// k = 0;
		// while( k < p->size )
		// {
		// 	printf("clone[%d] = %ld\n",k, p->clone[k]);
		// 	k++;
		// }
		if (p->b[0] != 10000000000)
			break;
	}
	k = 0;
	while( k < p->size )
	{
		printf("a[%d] = %ld\n",k, p->a[k]);
		k++;
	}
	k = 0;
	while( k < p->size )
	{
		printf("b[%d] = %ld\n",k, p->b[k]);
		k++;
	}
	k = 0;
	// while( k < p->size )
	// {
	// 	printf("clone[%d] = %ld\n",k, p->clone[k]);
	// 	k++;
	// }
	printf("nb = %d",p->nb_operation);
	ft_exit(1, p);

	// if (is_sorted(p->size, p->a) == 1 && p->b[p->size -1]
	// == 10000000000)
	// p->done = 2;
	// while(p->done < 3)
	// {
	// 	*p = find_max(p);
	// 	if (p->b[p->size - 1] == 10000000000)
	// 		p->done = 3;
	// }
}
