/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:04:20 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/11 19:50:26 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*sort(t_p *p, long *tab)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < p->size)
	{
		if (tab[i] != 10000000000)
			nb++;
		i++;
	}
	i = p->size - nb;
	while (i < p->size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap(&(tab[i]), &(tab[i + 1]));
			i = p->size - nb - 1;
		}
		i++;
	}
	p->nb_left = nb;
	return (tab);
}

int		is_sorted(int size, long *tab)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

t_p		find_max(t_p *p, int i, int j, int dis)
{
	int max;

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
	i = j;
	while (p->b[i] != max)
	{
		if (dis - j < p->size - dis)
			rb(p, 1);
		else
			rrb(p, 1);
	}
	pa(p, 1);
	return (*p);
}

void	algo2(t_p *p)
{
	while (1)
	{
		*p = find_max(p, 0, 0, 0);
		if (p->b[p->size - 1] == 10000000000)
			break ;
	}
	// int i = 0;
	// while (i < p->size)
	// {
	// 	printf("a[%d] = %ld\n", i, p->a[i]);
	// 	i++;
	// }
	ft_exit(1, p);
}

void	algo(t_p *p)
{
	int i;

	i = 0;
	while (i < p->size)
	{
		p->clone[i] = p->a[i];
		i++;
	}
	p->clone = sort(p, p->clone);
	i = 0;
	while (1)
	{
		if (p->clone[0] == p->a[0] && p->done == 0)
		{
			p->clone[0] = 10000000000;
			p->b[p->size - 1] = p->a[0];
			p->a[0] = 10000000000;
			ft_putstr("pb\n");
			p->done = 1;
		}
		apply_algo(p);
		if (p->b[0] != 10000000000)
			break ;
	}
	algo2(p);
}
