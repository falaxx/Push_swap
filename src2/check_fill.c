/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:36:41 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/13 22:45:42 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	fill2(t_p *p)
{
	char *line;

	line = NULL;
	check_double(p);
	clone(p);
	if (p->max - p->min == 0)
		p->ppx = 500;
	else
		p->ppx = 500 / (p->max - p->min);
	p->ppy = HEIGHT / p->size;
	if (p->sdl == 0)
		apply(p);
	else
		apply_sdl(p, line);
	ft_exit(1, p);
}

void	fill(char ***split, t_p *p)
{
	int i;
	int j;
	int k;

	j = 0 + p->sdl;
	i = 0;
	while (i < p->size)
	{
		k = 0;
		while (split[j][k] != 0)
		{
			p->a[i] = ft_getnbr_n(split[j][k], 0);
			p->b[i] = 10000000000;
			if (p->a[i] < p->min)
				p->min = p->a[i];
			if (p->a[i] > p->max)
				p->max = p->a[i];
			k++;
			i++;
		}
		j++;
	}
	fill2(p);
}
