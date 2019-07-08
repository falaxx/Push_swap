#include "push_swap.h"

void	ft_exit(int i, t_p *p)
{
	if (i == 0)
		ft_putstr("Error\n");
	if (p->a != NULL)
		free(p->a);
	if (p->b != NULL)
		free(p->b);
	if (p->clone != NULL)
		free(p->clone);
	exit(0);
}

int		check(char *av, t_p *p)
{
	int i = 0;

	if (ft_strlen(av) > 11 || av == '\0')
		ft_exit(0, p);
	if (ft_atol(av) > 2147483647 || ft_atol(av) < -2147483648)
		ft_exit(0, p);
	while(av[i] != '\0')
	{
		if (av[i] != '-' && ft_isdigit(av[i]) == 0)
			ft_exit(0, p);
		else if (av[i] == '-' && ft_isdigit(av[i + 1]) == 0)
			ft_exit(0, p);
		i++;
	}
	return (0);
}



void free_split(char ***split, int ac, t_p *p)
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
	p->range = p->size / 20 + 1;
	fill(split, p);
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
	p.nb_operation = 0;
	if (ac == 1)
		ft_exit(0, &p);
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
