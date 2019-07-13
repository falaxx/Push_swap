/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:47:00 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/13 21:47:16 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_exit(1, p);
}
