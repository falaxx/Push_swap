/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:50:50 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/06 21:00:49 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(long *a, long *b)
{
	long tmpa;
	long tmpb;

	tmpa = *a;
	tmpb = *b;
	*a = tmpb;
	*b = tmpa;
}

void	sa(t_p *p, int mode)
{
	int i;

	i = 0;
	while (i < p->size)
	{
		while (p->a[i] == 10000000000)
			i++;
		swap(&(p->a[i]), &(p->a[i + 1]));
		break ;
	}
	if (mode == 1)
		ft_putstr("sa\n");
}

void	sb(t_p *p, int mode)
{
	int i;

	i = 0;
	while (i < p->size)
	{
		while (p->b[i] == 10000000000)
			i++;
		swap(&(p->b[i]), &(p->b[i + 1]));
		break ;
	}
	if (mode == 1)
		ft_putstr("sb\n");
}

void	ss(t_p *p, int mode)
{
	int i;

	i = 0;
	while (i < p->size)
	{
		while (p->b[i] == 10000000000)
			i++;
		swap(&(p->b[i]), &(p->b[i + 1]));
		break ;
	}
	i = 0;
	while (i < p->size)
	{
		while (p->a[i] == 10000000000)
			i++;
		swap(&(p->a[i]), &(p->a[i + 1]));
		break ;
	}
	if (mode == 1)
		ft_putstr("ss\n");
}
