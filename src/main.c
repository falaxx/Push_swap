#include "push_swap.h"

int main(int ac, char **av)
{
	t_p 	p;
	int 	i = 0;

	p.size = ac - 1;
	p.done = 0;
	p.nb = 0;
	if (!(p.a = (long *)malloc(sizeof(long) * p.size)))
		exit(0); //ft_exit
	if (!(p.b = (long *)malloc(sizeof(long) * p.size)))
		exit(0);
	if (!(p.clone = (long *)malloc(sizeof(long) * p.size)))
		exit(0);
	while(i < p.size)
	{
		p.a[i] = ft_getnbr_n(av[i + 1], 0);
		if (p.a[i] > 2147483647 || p.a[i] < -2147483648)
			ft_putstr("Error\n"); // ft_exit; // ft_check number en fait.
		p.b[i] = 10000000000;
		// p.clone[i] = p.a[i];
		i++;
	}
	i = 0;

	// p = pb(&p);
	// p = pb(&p);
	//
	// p = pb(&p);
	//
	// p = pb(&p);

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
	p = algo(&p);
	i = 0;

	while( i < p.size )
	{
		printf("clone[%d] = %ld\n",i, p.clone[i]);
		i++;
	}
	i = 0;
	// while( i < p.size )
	// {
	// 	printf("b[%d] = %ld\n",i, p.b[i]);
	// 	i++;
	// }
	// printf("%d felix \n / toutsas",10000000000);
	// sort tab print chaque actions;

}