#include "push_swap.h"

void	ft_exit(int i)
{
	if (i == 0)
		ft_putstr("Error\n");
		while(1);
	exit(0);
}

int		check(char *av)
{
	int i = 0;

	if (ft_strlen(av) > 11 || av == '\0')
		ft_exit(0);
	if (ft_atol(av) > 2147483647 || ft_atol(av) < -2147483648)
		ft_exit(0);
	while(av[i] != '\0')
	{
		if (av[i] != '-' && ft_isdigit(av[i]) == 0)
			ft_exit(0);
		else if (av[i] == '-' && ft_isdigit(av[i + 1]) == 0)
			ft_exit(0);
		i++;
	}
	return (0);
}

void	init(char ***split, t_p *p)
{
	long	a[p->size];
	long	b[p->size];
	long	clone[p->size];
	int		i;

	i = 0;
	p->a = a;
	p->b = b;
	p->clone = clone;
	while (i < p->size)
	{
		a[i] = 10000000000;
		b[i] = 10000000000;
		clone[i] = 10000000000;
		p->a[i] = a[i];
		p->b[i] = b[i];
		p->clone[i] = clone[i];
		i++;
	}
	fill(split, p);
	p->done = 0;
	p->nb = 0;
}

void free_split(char ***split, int ac)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;

	while (i < ac)
	{
		j = 0;
		while(split[i][j] != 0)
		{
			free(split[i][j]);
			j++;
			k++;
		}
		free(split[i]);
		i++;
	}
	while(1);
	exit(0);
}

void split(char **av, t_p *p, int ac)
{
	int i;
	int j;
	char **split[ac];

	i = 0;
	while (i < ac)
	{
		j = 0;
		split[i] = ft_strsplit(av[i+1], ' ');
		while (split[i][j] != 0)
		{
			check(split[i][j]);
			j++;
			p->size++;
		}
		i++;
	}
	init(split, p);
	free_split(split, ac);
}

int		main(int ac, char **av)
{
	t_p	p;
	int	i;
	int	j;

	i = 0;
	j = 0;
	p.ac = ac -1;
	p.size = 0;
	p.a = NULL;
	p.b = NULL;
	p.clone = NULL;
	if (ac == 1)
		ft_exit(0);
	split(av, &p, p.ac);

	// while (i < p.size -2)
	// {
	// 	j = 0;
	// 	// p->split[i] = ft_strsplit(av[i+1], ' ');
	// 	while (p.split[i][j] != 0)
	// 	{
	// 		// check(p->split[i][j], p);
	// 		printf("%s\n",p.split[i][j]);
	// 		j++;
	// 		// p->size++;
	// 	}
	// 	i++;
	// }

	// check(av, &p);
	// if (!(p.a = (long *)malloc(sizeof(long) * p.size)))
	// 	ft_exit(&p, 1); //ft_exit
	// if (!(p.b = (long *)malloc(sizeof(long) * p.size)))
	// 	ft_exit(&p, 1);
	// if (!(p.clone = (long *)malloc(sizeof(long) * p.size)))
	// 	ft_exit(&p, 1);
	// while(i < p.size)
	// {
	// 	p.a[i] = ft_getnbr_n(av[i + 1], 0);
	// 	p.b[i] = 10000000000;
	// 	i++;
	// }
	i = 0;
	// p.tab = p.size / 20 + 1;
	// while( i < p.size )
	// {
	// 	printf("a[%d] = %ld\n",i, p.a[i]);
	// 	i++;
	// }
	// i = 0;
	// while( i < p.size )
	// {
	// 	printf("b[%d] = %ld\n",i, p.b[i]);
	// 	i++;
	// }
	// if (p.size < 10)
		// p = brute_force(&p);
	// if (p.size > 4)
	// 	p = algo(&p);
	// i = 0;
	// while( i < p.size )
	// {
	// 	printf("clone[%d] = %ld\n",i, p.clone[i]);
	// 	i++;
	// }
	// i = 0;
	// i = 0;
	//
	// while( i < p.size )
	// {
	// 	printf("a[%d] = %ld\n",i, p.a[i]);
	// 	i++;
	// }
	// i = 0;
	// while( i < p.size )
	// {
	// 	printf("b[%d] = %ld\n",i, p.b[i]);
	// 	i++;
	// }
	// i = 0;
	// printf("nb operations = %d",p.nb);
}
