/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:48:58 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/06 20:51:40 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_p *p, int mode)
{
	int i;

	i = p->size - 2;
	while (i >= 0)
	{
		if (p->a[i] == 10000000000)
			break ;
		swap(&(p->a[i]), &(p->a[i + 1]));
		i--;
	}
	if (mode == 1)
		ft_putstr("rra\n");
}

void	rrb(t_p *p, int mode)
{
	int i;

	i = p->size - 2;
	while (i >= 0)
	{
		if (p->b[i] == 10000000000)
			break ;
		swap(&(p->b[i]), &(p->b[i + 1]));
		i--;
	}
	if (mode == 1)
		ft_putstr("rrb\n");
}

void	rrr(t_p *p, int mode)
{
	int i;

	i = p->size - 2;
	while (i >= 0)
	{
		if (p->b[i] == 10000000000)
			break ;
		swap(&(p->b[i]), &(p->b[i + 1]));
		i--;
	}
	i = p->size - 2;
	while (i >= 0)
	{
		if (p->a[i] == 10000000000)
			break ;
		swap(&(p->a[i]), &(p->a[i + 1]));
		i--;
	}
	if (mode == 1)
		ft_putstr("rr\n");
}
