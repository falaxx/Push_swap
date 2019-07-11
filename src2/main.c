#include "push_swap.h"

void	ft_exit(int i, t_p *p)
{
	if (i == 0)
		write(2, "Error\n", 7);
	if (p->a != NULL)
		free(p->a);
	if (p->b != NULL)
		free(p->b);
	if (p->tex != NULL)
		SDL_DestroyTexture(p->tex->texture);
	if (p->renderer != NULL)
		SDL_DestroyRenderer(p->renderer);
	if (p->window != NULL)
		SDL_DestroyWindow(p->window);
	exit(0);
}

int		check(char *av, t_p *p)
{
	int i;

	i = 0;
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
			check(split[i][j], p);
			j++;
			p->size++;
		}
		i++;
	}
	init(split, p, ac);
	free_split(split, ac, p);
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
	p.min = 10000000000;
	p.max = -10000000000;
	if (ac == 1)
		ft_exit(0, &p);
	split(av, &p, p.ac);
	return (0);
}
