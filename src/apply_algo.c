/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:52:35 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/12 00:21:11 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		dis_bot(t_p *p, int i, int j)
{
	int dis;
	int res;

	dis = 0;
	i = p->size - 1;
	res = 0;
	while (i > 0)
	{
		j = 0;
		while (j < p->range)
		{
			res = find_top(p->a[i - j], p, 0, 0);
			if (res == 1)
				return (dis + j + 1);
			if (res == 3)
				return (dis + j + 1);
			j++;
		}
		dis++;
		i--;
	}
	return (-41);
}

int		dis_top(t_p *p, int i, int j)
{
	int dis;
	int res;

	dis = 0;
	res = 0;
	while (p->a[i] == 10000000000)
		i++;
	while (i < p->size)
	{
		j = 0;
		while (j < p->range)
		{
			res = find_top(p->a[i + j], p, 0, 0);
			if (res == 1)
				return (dis + j);
			if (res == 3)
				return (dis + j);
			j++;
		}
		dis++;
		i++;
	}
	return (-42);
}

int	check_b(t_p *p)
{
	int i;
	int a;
	int b;
	i = 0;
	while (p->b[i] == 10000000000)
		i++;
	a = p->b[i] - p->b[i + 1];
	if (a < 0)
		a = p->b[i + 1] - p->b[i];
	b = p->b[i] - p->b[p->size - 1];
	if (b < 0)
		b = p->b[p->size - 1] -p->b[i];
	if (i < p->size - p->range * 2)
	{
		if (a > b)
			return (1);
	}
	return (0);
}

void	apply_algo(t_p *p)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	j = 0;
	while (p->a[i] == 10000000000)
		i++;
	k = find_top(p->a[i], p, 1, 0);
	if (k == 2 || k == 4)
	{
		j = check_b(p);
		if (j == 0)
			rra(p, 1);
		else
			rr(p, 1, 0, 0);
	}
	if (k != 0)
		pb(p, 1);
	if (k > 2)
	{
		if (dis_top(p, 0, 0) <= dis_bot(p, 0, 0))
			rr(p, 1, 0, 0);
		else
			rb(p, 1);
	}
	if (k != 0 && p->done == 0)
		p->done = 1;
	if (k != 0)
	{
		k = check_b(p);
		if (dis_top(p, 0, 0) <= dis_bot(p, 0, 0) && k == 1)
			rr(p, 1, 0, 0);
		else if(dis_top(p, 0, 0) > dis_bot(p, 0, 0) && k == 1)
			rb(p, 1);
		j = 0;
		while (p->b[j] == 10000000000)
			j++;
		if (p->b[j] < p->b[j + 1] && p->a[i] < p->a[i + 1])
			ss(p, 1); // plutot check j par rapport a j + 2
		else if (p->b[j] < p->b[j + 1] && p->a[i] > p->a[i + 1])
			sb(p, 1);
		return ;
	}
	if (dis_top(p, 0, 0) <= dis_bot(p, 0, 0))
		ra(p, 1);
	else
		rra(p, 1);
}
