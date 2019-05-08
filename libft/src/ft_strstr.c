/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 01:04:30 by doyang            #+#    #+#             */
/*   Updated: 2018/12/03 16:31:30 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *longer;
	char *shorter;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		longer = (char *)haystack;
		shorter = (char *)needle;
		while (*longer == *shorter && *shorter)
		{
			longer++;
			shorter++;
		}
		if (!*shorter)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
