/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:19:31 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/14 00:30:35 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_texture	red(t_texture tex, t_p *p, t_vec2 pos, long l)
{
	t_vec2 save;
	t_vec2 next;

	if (l == 10000000000)
		return (tex);
	pos.y = pos.y * p->ppy;
	next.x = pos.x + p->ppx * l;
	next.y = pos.y + p->ppy;
	save = pos;
	while (pos.x < next.x)
	{
		while (pos.y < next.y)
		{
			set_pixel(&tex, 0xfe0000ff, pos);
			pos.y++;
		}
		pos.y = save.y;
		pos.x++;
	}
	return (tex);
}

t_texture	black(t_texture tex)
{
	t_vec2 pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.x < WIDTH)
	{
		while (pos.y < HEIGHT)
		{
			set_pixel(&tex, 0x000000ff, pos);
			pos.y++;
		}
		pos.y = 0;
		pos.x++;
	}
	return (tex);
}

t_texture	blacked(t_texture tex, t_p *p, t_vec2 pos)
{
	t_vec2 save;
	t_vec2 next;

	pos.y = pos.y * p->ppy;
	next.x = pos.x + 500;
	next.y = pos.y + p->ppy;
	save = pos;
	while (pos.x < next.x)
	{
		while (pos.y < next.y)
		{
			set_pixel(&tex, 0x000000ff, pos);
			pos.y++;
		}
		pos.y = save.y;
		pos.x++;
	}
	return (tex);
}

t_texture	blue(t_texture tex, t_p *p, t_vec2 pos, long l)
{
	t_vec2 save;
	t_vec2 next;

	if (l == 10000000000)
		return (tex);
	pos.y = pos.y * p->ppy;
	next.x = pos.x + p->ppx * l;
	next.y = pos.y + p->ppy;
	save = pos;
	while (pos.x < next.x)
	{
		while (pos.y < next.y)
		{
			set_pixel(&tex, 0x0066ffff, pos);
			pos.y++;
		}
		pos.y = save.y;
		pos.x++;
	}
	return (tex);
}

void		render(t_p *p)
{
	int		x;
	int		y;
	int		i;
	t_vec2	pos;
	t_vec2	pos2;

	i = 0;
	x = 0;
	y = 0;
	clone(p);
	while (i < p->size)
	{
		pos.x = x;
		pos2.x = x + 500;
		pos.y = y;
		pos2.y = y;
		if (find_top(p->a[i], p, 1, 0) == 0)
			*p->tex = blue(*p->tex, p, pos, p->a[i]);
		else if (find_top(p->a[i], p, 1, 0) != 0)
			*p->tex = red(*p->tex, p, pos, p->a[i]);
		*p->tex = blue(*p->tex, p, pos2, p->b[i]);
		i++;
		y++;
	}
	update_image(p, p->tex);
}
