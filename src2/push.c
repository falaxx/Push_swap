/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:39:05 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/11 19:21:21 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_p *p, int mode)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p->size)
	{
		while (p->b[j] == 10000000000)
			j++;
		while (p->a[i] == 10000000000)
			i++;
		swap(&(p->a[i - 1]), &(p->b[j]));
		break ;
	}
	if (mode == 1)
		ft_putstr("pa\n");
}

void	pb(t_p *p, int mode)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < p->size)
	{
		while (p->b[j] == 10000000000)
			j++;
		while (p->a[i] == 10000000000)
			i++;
		swap(&(p->a[i]), &(p->b[j - 1]));
		break ;
	}
	if (mode == 1)
		ft_putstr("pb\n");
}
