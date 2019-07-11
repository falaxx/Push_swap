/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:36:41 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/11 22:50:34 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		operation(t_p *p, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(p, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(p, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(p, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(p, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(p, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(p, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(p, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(p, 0, 0, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(p, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(p, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(p, 0);
	else
		return (-1);
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
			if (p->a[i] < p->min)
				p->min = p->a[i];
			if (p->a[i] > p->max)
				p->max = p->a[i];
			k++;
			i++;
		}
		j++;
	}
	p->ppx = 500/(p->max - p->min);
	p->ppy = HEIGHT / p->size;
	printf("min = %ld max = %ld",p->min, p->max);
	apply(p);
	ft_exit(1, p);
}
