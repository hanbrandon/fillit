/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 01:45:28 by doyang            #+#    #+#             */
/*   Updated: 2018/12/03 16:41:40 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*longer;
	char	*shorter;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && i < (int)len)
	{
		longer = (char *)haystack;
		shorter = (char *)needle;
		j = 0;
		while (*longer == *shorter && i + j < (int)len && *shorter)
		{
			longer++;
			shorter++;
			j++;
		}
		if (!*shorter)
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
