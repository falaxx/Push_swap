/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:34:07 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/13 21:42:50 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*next_try2(char *try, int i, int j)
{
	try[i] = 'a';
	j = i - 1;
	try[j] += 1;
	while (try[j] == 'd')
	{
		try[j] = 'a';
		if (j == 0)
		{
			i = 0;
			while (try[i + 1] != '\0')
				i++;
			try[i + 1] = 'a';
			break ;
		}
		j--;
		try[j] += 1;
	}
	return (try);
}

void	next_try(char *try)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (try[i + 1] != '\0')
		i++;
	try[i] += 1;
	if (try[i] == 'd' && i == 0)
	{
		try[i + 1] = 'a';
		try[i] = 'a';
	}
	else if (try[i] == 'd' && i > 0)
		try = next_try2(try, i, j);
}

void	apply_try(char *str, t_p *p, int mode)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == 'a')
			sa(p, mode);
		if (str[i] == 'b')
			rra(p, mode);
		if (str[i] == 'c')
			ra(p, mode);
		i--;
	}
}

void	brute_force2(t_p *p, int i, char *try)
{
	while (1)
	{
		i = 0;
		while (i < p->size)
		{
			p->a[i] = p->clone[i];
			p->b[i] = 10000000000;
			i++;
		}
		if (try[12] != '\0')
			algo(p, 0);
		apply_try(try, p, 0);
		if (is_sorted(p->size, p->a) == 1 && p->b[p->size - 1] == 10000000000)
			break ;
		next_try(try);
	}
}

void	brute_force(t_p *p)
{
	int		i;
	char	try[20];

	i = 0;
	ft_bzero(try, 20);
	try[0] = 'a';
	i = 0;
	while (i < p->size)
	{
		p->clone[i] = p->a[i];
		i++;
	}
	if (is_sorted(p->size, p->a) == 1 && p->b[p->size - 1] == 10000000000)
		ft_exit(1, p);
	brute_force2(p, i, try);
	apply_try(try, p, 1);
}
