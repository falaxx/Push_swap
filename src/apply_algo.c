/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:52:35 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/13 21:56:24 by fmerding         ###   ########.fr       */
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

void	apply_algo2(t_p *p, int j, int k)
{
	pb(p, 1);
	while (check_r(p, p->b) == 1)
	{
		if (check_r(p, p->a) == 1)
			rr(p, 1, 0, 0);
		else
			rb(p, 1);
	}
	k = check_s(p, p->a);
	j = check_s(p, p->b);
	if (k == 1 && j == 1)
		ss(p, 1);
	return ;
}

void	apply_algo(t_p *p, int i, int k)
{
	while (p->a[i] == 10000000000)
		i++;
	k = find_top(p->a[i], p, 1, 0);
	if (k == 2 || k == 4)
		rra(p, 1);
	if (k != 0 && p->done == 0)
		p->done = 1;
	if (k != 0)
		apply_algo2(p, i, k);
	k = check_r(p, p->b);
	if (dis_top(p, 0, 0) <= dis_bot(p, 0, 0) && k == 1)
		rr(p, 1, 0, 0);
	if (dis_top(p, 0, 0) <= dis_bot(p, 0, 0) && k == 0)
		ra(p, 1);
	else
		rra(p, 1);
}
