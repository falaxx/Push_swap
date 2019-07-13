/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 04:34:23 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/14 00:12:05 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(int size, long *tab)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int		operation(t_p *p, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(p, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(p, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(p, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(p, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(p, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(p, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(p, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(p, 0, 0, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(p, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(p, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(p, 0);
	else
		return (-1);
	return (0);
}

void	apply_sdl(t_p *p, char *line)
{
	initialize_sdl(p);
	*p->tex = black(*p->tex);
	while (1)
	{
		while ((SDL_PollEvent(&(p->event))) != -42
		&& get_next_line(0, &line) > 0)
		{
			free(line);
			if (operation(p, line) == -1)
				ft_exit(0, p);
			*p->tex = black(*p->tex);
			render(p);
			if (p->event.type == SDL_QUIT || (p->event.type == SDL_KEYDOWN &&
				p->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				ft_exit(1, p);
		}
		if (is_sorted(p->size, p->a) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_exit(1, p);
	}
}

void	apply(t_p *p)
{
	char *line;

	line = NULL;
	while (1)
	{
		while (get_next_line(0, &line) > 0)
		{
			if (operation(p, line) == -1)
			{
				free(line);
				ft_exit(0, p);
			}
			free(line);
		}
		if (is_sorted(p->size, p->a) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_exit(1, p);
	}
}
