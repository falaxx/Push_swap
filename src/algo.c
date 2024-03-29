/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:04:20 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/13 21:55:51 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*sort2(t_p *p, long *tab)
{
	int i;
	int j;

	i = 0;
	while (i < p->size / 2)
	{
		swap(&(tab[i]), &(tab[i + p->size / 2]));
		i++;
	}
	j = 0;
	while (i < p->size)
	{
		swap(&(tab[i]), &(tab[p->size - 1 - j]));
		i++;
		j++;
	}
	return (tab);
}

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
		if (tab[i] < tab[i + 1])
		{
			swap(&(tab[i]), &(tab[i + 1]));
			i = p->size - nb - 1;
		}
		i++;
	}
	tab = sort2(p, tab);
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

void	algo(t_p *p, int i)
{
	i = 0;
	while (i < p->size)
	{
		p->clone[i] = p->a[i];
		i++;
	}
	p->clone = sort(p, p->clone);
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
		apply_algo(p, 0, 0);
		if (p->a[p->size - 2] == 10000000000)
			pb(p, 1);
		if (p->b[0] != 10000000000)
			break ;
	}
	algo2(p);
}
