#include "push_swap.h"

void	ft_exit(t_p *p, int i)
{
	if (i == 0)
		ft_putstr("Error\n");
	if (p->a != NULL)
		ft_memdel((void **)&p->a);
	if (p->b != NULL)
		ft_memdel((void **)&p->b);
	if (p->clone != NULL)
		ft_memdel((void **)&p->clone);
	exit(0);
}

int		check(char **av, t_p *p)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < p->size)
	{
		if (ft_strlen(av[i+1]) > 11 || av[i+1][0] == '\0')
			ft_exit(p, 0);
		if (ft_atol(av[i+1]) > 2147483647 || ft_atol(av[i+1]) < -2147483648)
			ft_exit(p, 0);
		j = 0;
		while(av[i+1][j] != '\0')
		{
			if (av[i+1][j] != '-' && ft_isdigit(av[i+1][j]) == 0)
				ft_exit(p, 0);
			k = i + 1;
			while (k < p->size)
			{
				if (ft_strcmp(av[i+1],av[k+1]) == 0)
					ft_exit(p, 0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
int		main(int ac, char **av)
{
	t_p 	p;
	int 	i = 0;

	p.size = ac - 1;
	p.done = 0;
	p.nb = 0;
	p.a = NULL;
	p.b = NULL;
	p.clone = NULL;
	if (!(p.a = (long *)malloc(sizeof(long) * p.size)))
		ft_exit(&p, 1); //ft_exit
	if (!(p.b = (long *)malloc(sizeof(long) * p.size)))
		ft_exit(&p, 1);
	if (!(p.clone = (long *)malloc(sizeof(long) * p.size)))
		ft_exit(&p, 1);
	if (ac == 1)
		ft_exit(&p, 0);
	check(av, &p);
	while(i < p.size)
	{
		p.a[i] = ft_getnbr_n(av[i + 1], 0);
		p.b[i] = 10000000000;
		i++;
	}
	i = 0;
	p.tab = p.size / 20 + 1;
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
		p = brute_force(&p);
	// if (p.size > 4)
	// 	p = algo(&p);
	i = 0;
	// while( i < p.size )
	// {
	// 	printf("clone[%d] = %ld\n",i, p.clone[i]);
	// 	i++;
	// }
	i = 0;
	// i = 0;
	//
	while( i < p.size )
	{
		printf("a[%d] = %ld\n",i, p.a[i]);
		i++;
	}
	i = 0;
	while( i < p.size )
	{
		printf("b[%d] = %ld\n",i, p.b[i]);
		i++;
	}
	i = 0;
	// printf("nb operations = %d",p.nb);

}
