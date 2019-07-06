/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:42:54 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/06 21:02:07 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_p *p, int mode)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p->size)
	{
		while (p->a[i] == 10000000000)
			i++;
		j = i;
		swap(&(p->a[i]), &(p->a[i + 1]));
		i++;
	}
	swap(&(p->a[i]), &(p->a[j]));
	if (mode == 1)
		ft_putstr("ra\n");
}

void	rb(t_p *p, int mode)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p->size)
	{
		while (p->b[i] == 10000000000)
			i++;
		j = i;
		swap(&(p->b[i]), &(p->b[i + 1]));
		i++;
	}
	swap(&(p->b[i]), &(p->b[j]));
	if (mode == 1)
		ft_putstr("rb\n");
}

void	rr(t_p *p, int mode, int i, int j)
{
	while (i < p->size)
	{
		while (p->b[i] == 10000000000)
			i++;
		j = i;
		swap(&(p->b[i]), &(p->b[i + 1]));
		i++;
	}
	swap(&(p->b[i]), &(p->b[j]));
	i = 0;
	j = 0;
	while (i < p->size)
	{
		while (p->a[i] == 10000000000)
			i++;
		j = i;
		swap(&(p->a[i]), &(p->a[i + 1]));
		i++;
	}
	swap(&(p->a[i]), &(p->a[j]));
	if (mode == 1)
		ft_putstr("rr\n");
}
