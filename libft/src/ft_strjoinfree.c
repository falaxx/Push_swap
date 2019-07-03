/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:30:30 by fmerding          #+#    #+#             */
/*   Updated: 2019/06/22 18:30:32 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int frees1, int frees2)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char*)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, s2);
	if (s1 == s2 && (frees1 || frees2))
	{
		free(s1);
		return (ret);
	}
	if (frees1)
		free(s1);
	if (frees2)
		free(s2);
	return (ret);
}
