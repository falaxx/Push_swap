/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:22:44 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/14 00:17:55 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check(char *av, t_p *p, int j)
{
	int i;

	i = 0;
	if (ft_strlen(av) == 2 && av[0] == '-' && av[1] == 'v' && av[2] == '\0')
	{
		p->sdl = 1;
		if (j != 0)
			ft_exit(0, p);
		p->size--;
		return (0);
	}
	if (ft_strlen(av) > 11 || av == '\0')
		ft_exit(0, p);
	if (ft_atol(av) > 2147483647 || ft_atol(av) < -2147483648)
		ft_exit(0, p);
	while (av[i] != '\0')
	{
		if (av[i] != '-' && ft_isdigit(av[i]) == 0)
			ft_exit(0, p);
		else if (av[i] == '-' && ft_isdigit(av[i + 1]) == 0)
			ft_exit(0, p);
		i++;
	}
	return (0);
}

void	free_split(char ***split, int ac, t_p *p)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (split[i][j] != 0)
		{
			free(split[i][j]);
			j++;
			k++;
		}
		free(split[i]);
		i++;
	}
	ft_exit(1, p);
}

void	init(char ***split, t_p *p, int ac)
{
	if (!(p->a = (long *)malloc(sizeof(long) * (p->size))))
		free_split(split, ac, p);
	if (!(p->b = (long *)malloc(sizeof(long) * (p->size))))
		free_split(split, ac, p);
	if (!(p->clone = (long *)malloc(sizeof(long) * (p->size))))
		free_split(split, ac, p);
	p->range = p->size / 15 + 2;
	if (p->size > 100)
		p->range = p->size / 40 + 2;
	fill(split, p);
}

void	split(char **av, t_p *p, int ac)
{
	int		i;
	int		j;
	char	**split[ac];

	i = 0;
	while (i < ac)
	{
		j = 0;
		split[i] = ft_strsplit(av[i + 1], ' ');
		while (split[i][j] != 0)
		{
			check(split[i][j], p, i);
			j++;
			p->size++;
		}
		i++;
	}
	if (p->size == 0 && p->sdl == 1)
		ft_exit(0, p);
	init(split, p, ac);
}

int		main(int ac, char **av)
{
	t_p		p;

	p.window = NULL;
	p.renderer = NULL;
	p.tex = NULL;
	p.ac = ac - 1;
	p.size = 0;
	p.a = NULL;
	p.b = NULL;
	p.clone = NULL;
	p.min = 10000000000;
	p.max = -10000000000;
	p.sdl = 0;
	if (ac == 1)
		ft_exit(1, &p);
	split(av, &p, p.ac);
	return (0);
}
