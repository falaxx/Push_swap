/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:50:46 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/14 15:54:08 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_bot2(t_p *p, int mode, int j)
{
	int i;

	i = 0;
	while (p->clone[j] == 10000000000)
		j++;
	while (i < p->range)
	{
		if (p->clone[j + i] == p->a[p->size - 1])
		{
			if (mode == 1)
				p->clone[j + i] = 10000000000;
			return (2);
		}
		if (p->clone[j + i] == 10000000000)
			j++;
		else
			i++;
	}
	return (0);
}

int		find_bot(t_p *p, int mode, int j)
{
	int i;

	i = p->size - 1;
	j = i - p->range;
	while (i > j)
	{
		if (p->clone[i] == p->a[p->size - 1])
		{
			if (mode == 1)
				p->clone[i] = 10000000000;
			return (4);
		}
		if (p->clone[i] == 10000000000)
			j--;
		i--;
	}
	i = find_bot2(p, mode, j);
	if (i == 2)
		return (2);
	return (0);
}

int		find_top2(long l, t_p *p, int mode)
{
	int i;
	int j;

	i = p->size - 1;
	j = i - p->range;
	while (i > j)
	{
		if (p->clone[i] == l)
		{
			if (mode == 1)
				p->clone[i] = 10000000000;
			return (3);
		}
		if (p->clone[i] == 10000000000)
			j--;
		i--;
	}
	return (0);
}

int		find_top(long l, t_p *p, int mode, int i)
{
	int j;

	j = 0;
	while (p->clone[j] == 10000000000)
		j++;
	while (i < p->range)
	{
		if (p->clone[j + i] == l)
		{
			if (mode == 1)
				p->clone[j + i] = 10000000000;
			return (1);
		}
		if (p->clone[j + i] == 10000000000)
			j++;
		else
			i++;
	}
	j = find_top2(l, p, mode);
	if (j == 3)
		return (3);
	if (mode == 1)
		return (find_bot(p, mode, 0));
	return (0);
}

void	ft_exit(int i, t_p *p)
{
	if (i == 0)
		write(2, "Error\n", 7);
	if (p->a != NULL)
		free(p->a);
	if (p->b != NULL)
		free(p->b);
	if (p->clone != NULL)
		free(p->clone);
	exit(0);
}
