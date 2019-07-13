/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:53:23 by fmerding          #+#    #+#             */
/*   Updated: 2019/07/13 22:54:37 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <SDL.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct		s_texture
{
	Uint32			*content;
	SDL_Texture		*texture;
	Uint32			color_tmp;
}					t_texture;

typedef struct		s_p
{
	int				ac;
	long			*a;
	long			*b;
	long			*clone;
	int				size;
	int				range;
	int				nb_left;
	int				done;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_texture		*tex;
	SDL_Event		event;
	long			max;
	long			min;
	long			ppx;
	long			ppy;
	int				sdl;
}					t_p;

void				algo(t_p *p, int i);
void				algo2(t_p *p);
void				sa(t_p *p, int mode);
void				sb(t_p *p, int mode);
void				ss(t_p *p, int mode);
void				pa(t_p *p, int mode);
void				pb(t_p *p, int mode);
void				ra(t_p *p, int mode);
void				rb(t_p *p, int mode);
void				rr(t_p *p, int mode, int i, int j);
void				rra(t_p *p, int mode);
void				rrb(t_p *p, int mode);
void				rrr(t_p *p, int mode);
void				swap(long *a, long *b);
void				ft_exit(int mode, t_p *p);
void				fill(char ***split, t_p *p);
void				brute_force(t_p *p);
int					is_sorted(int size, long *tab);
void				apply_algo(t_p *p, int i, int k);
int					find_top(long l, t_p *p, int mode, int i);
int					find_bot(t_p *p, int mode, int j);
void				ft_exit2(t_p *p);
void				initialize_sdl(t_p *p);
void				update_image(t_p *p, t_texture *tex);
void				set_pixel(t_texture *text, Uint32 color, t_vec2 coord);
void				render(t_p *p);
void				apply(t_p *p);
int					operation(t_p *p, char *line);
int					find_top(long l, t_p *p, int mode, int i);
void				clone(t_p *p);
void				apply_sdl(t_p *p, char *line);
int					check_s(t_p *p, long *tab);
int					check_r(t_p *p, long *tab);
t_texture			black(t_texture tex);

#endif
