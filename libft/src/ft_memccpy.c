/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:06:15 by doyang            #+#    #+#             */
/*   Updated: 2018/12/01 16:19:58 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *cpydst;
	char *cpysrc;

	cpydst = (char *)dst;
	cpysrc = (char *)src;
	while (n > 0)
	{
		*cpydst = *cpysrc;
		cpydst++;
		if (*cpysrc == (char)c)
			return ((void *)cpydst);
		cpysrc++;
		n--;
	}
	return (NULL);
}
