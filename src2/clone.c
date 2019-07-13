/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:39:10 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/13 22:39:32 by fmerding         ###   ########.fr       */
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

void	clone(t_p *p)
{
	int i;

	i = 0;
	while (i < p->size)
	{
		p->clone[i] = p->a[i];
		i++;
	}
	p->clone = sort(p, p->clone);
}
