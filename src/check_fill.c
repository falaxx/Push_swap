/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:36:41 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/11 18:35:21 by fmerding         ###   ########.fr       */
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
			p->clone[i] = p->a[i];
			k++;
			i++;
		}
		j++;
	}
	check_double(p);
	brute_force(p);
}
