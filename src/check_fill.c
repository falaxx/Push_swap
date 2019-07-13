/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:36:41 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/13 22:05:48 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_r(t_p *p, long *tab)
{
	int i;
	int a;
	int b;

	i = 0;
	while (tab[i] == 10000000000)
		i++;
	a = tab[i] - tab[i + 1];
	if (a < 0)
		a = tab[i + 1] - tab[i];
	b = tab[i] - tab[p->size - 1];
	if (b < 0)
		b = tab[p->size - 1] - tab[i];
	if (i < p->size - 3)
	{
		if (a > b)
			return (1);
	}
	return (0);
}

int		check_s(t_p *p, long *tab)
{
	int i;
	int a;
	int b;

	i = 0;
	while (tab[i] == 10000000000)
		i++;
	if (i > p->size - 2)
		return (0);
	a = tab[i] - tab[i + 1];
	if (a < 0)
		a = tab[i + 1] - tab[i];
	b = tab[i] - tab[i + 2];
	if (b < 0)
		b = tab[i + 2] - tab[i];
	if (i < p->size - 3)
	{
		if (a > b)
			return (1);
	}
	return (0);
}

void	check_double(t_p *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p->size)
	{
		j = i + 1;
		while (j < p->size)
		{
			if (p->a[i] == p->a[j])
				ft_exit(0, p);
			j++;
		}
		i++;
	}
}

void	fill(char ***split, t_p *p)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 0;
	while (i < p->size)
	{
		k = 0;
		while (split[j][k] != 0)
		{
			p->a[i] = ft_getnbr_n(split[j][k], 0);
			p->b[i] = 10000000000;
			p->clone[i] = p->a[i];
			k++;
			i++;
		}
		j++;
	}
	check_double(p);
	brute_force(p);
}
