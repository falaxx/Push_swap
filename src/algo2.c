/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:04:20 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/10 19:01:41 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ra_or_rra(int l, t_p *p)
// {
// 	int i;
// 	int j;
// 	int k;
//
// 	k = 0;
// 	i = 0;
// 	j = 0;
// 	while (p->clone[i] == 10000000000)
// 		k++;
// 	while (i < p->size)
// 	{
// 		j = 0;
// 		while (j < p->range)
// 		{
// 			if (p->a[l + i] == p->clone[j + k])
// 			{
// 				ra(p, 0);
// 				return ;
// 			}
// 			if (p->a[p->size -1 - i] == p->clone[p->size -1 -j])
// 			{
// 				rra(p, 0);
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	ra(p, 0);
// }

int rra_or(t_p *p)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;

	while (i < p->size)
	{
		j = 0;
		k = 0;
		while (j < p->range)
		{
			while(p->clone[p->size -1 -i -k] == 10000000000)
				k++;
			if (p->a[p->size -1 - i] == p->clone[p->size -1 -j - k])
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	printf("boucle?\n");
	return (i);
}

int ra_or(int l, t_p *p)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (i < p->size)
	{
		j = 0;
		k = 0;
		while (j < p->range)
		{
			while(p->clone[j + k] == 10000000000)
				k++;
			if (p->a[l + i] == p->clone[j + k] || p->a[l + i] == p->clone[p->size -1 -j])
			{
				ra(p, 0);
				return (i);
			}
			j++;
		}
		i++;
	}
	return (i);
}

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

int		find_in_tab_2(long l, t_p *p, int i, int j)
{
	i = p->size -1;
	j = i - p->range;
	while (i > j)
	{
		if (p->clone[i] == l)
		{
			p->clone[i] = 10000000000;
			return (3);
		}
		if (p->clone[i] == p->a[p->size -1])
		{
			p->clone[i] = 10000000000;
			return (4);
		}
		if (p->clone[i] == 10000000000)
			j--;
		i--;
	}
	return(0);
}

int		find_in_tab(long l, t_p *p)
{
	int i = 0;
	int j = 0;
	while (p->clone[j] == 10000000000)
		j++;
	while (i < p->range)
	{
		if (p->clone[j + i] == l)
		{
			p->clone[j + i] = 10000000000;
			return (1);
		}
		if (p->clone[j + i] == p->a[p->size -1])
		{
			p->clone[j + i] = 10000000000;
			return (2);
		}
		if (p->clone[j + i] == 10000000000)
			j++;
		else
			i++;

	}
	return (find_in_tab_2(l, p, 0, 0));
}

void	apply_algo(t_p *p)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (p->a[i] == 10000000000)
		i++;
	k = find_in_tab(p->a[i], p);
	if (k == 1)
	{
		pb(p, 0);
		p->nb_operation += 1;
	}
	if (k == 2)
	{
		rra(p, 0);
		pb(p, 0);
		p->nb_operation += 2;
	}
	if (k == 3)
	{
		pb(p, 0);
		rb(p, 0);
		p->nb_operation += 2;
	}
	if (k == 4)
	{
		rrr(p, 0);
		pb(p, 0);
		p->nb_operation += 3;
	}
	// if (find_in_tab(p->a[i], p->clone, p,
	// "top") == 1)
	// {
	// 	pb(p, 0);
	// 	p->nb_operation += 1;
	// }
	// if (find_in_tab(p->a[p->size-1], p->clone, p,
	// "top") == 1)
	// {
	// 	rra(p, 0);
	// 	pb(p, 0);
	// 	p->nb_operation += 2;
	// }
	// if (find_in_tab(p->a[i], p->clone, p,
	// "bot") == 0)
	// {
	// 	pb(p, 0);
	// 	rb(p, 0);
	// 	p->nb_operation += 2;
	// }
	// if (find_in_tab(p->a[p->size-1], p->clone, p,
	// 	"bot") == 1)
	// {
	// 	rra(p, 0);
	// 	pb(p, 0);
	// 	rb(p, 0);
	// 	p->nb_operation += 3;
	// }
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
	if (ra_or(i, p) < rra_or(p))
		ra(p, 0);
	else
		rra(p, 0);
	p->nb_operation++;
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
			rb(p, 0);
		else
			rrb(p, 0);
		p->nb_operation += 1;
	}
	pa(p, 0);
	p->nb_operation += 1;
	return (*p);
}

void	algo(t_p *p)
{
	int i = 0;
	// int k = 0;
	i = 0;
	while(i < p->size)
	{
		p->clone[i] = p->a[i];
		i++;
	}
	p->clone = sort(p, p->clone);
	while (1)
	{
		// printf("range = %d",p->range);
		// k = 0;
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
		apply_algo(p);
		// sleep(1);
		if (p->b[0] != 10000000000)
			break;
		// if (p->nb_operation > 250)
		// {

		// sleep(2);
		// printf("blocked?");
		// exit(0);
		// }
		// printf("pb[0] =  %zu\n",p->b[0]);
		// printf("pa[p->size -1] =  %zu\n",p->a[p->size -1 ]);
		// printf("nb = %d\n",p->nb_operation);
	}
	// k = 0;
	// while( k < p->size )
	// {
	// 	printf("b[%d] = %ld\n",k, p->b[k]);
	// 	k++;
	// }
	// k = 0;

	while(1)
	{
		*p = find_max(p);
		if (p->b[p->size - 1] == 10000000000)
			break;
	}

	// k = 0;
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
