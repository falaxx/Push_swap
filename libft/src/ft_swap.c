/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 22:33:21 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/20 15:16:22 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmpa;
	int tmpb;

	tmpa = *a;
	tmpb = *b;
	*a = tmpb;
	*b = tmpa;
}
