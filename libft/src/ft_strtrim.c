/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:27:49 by doyang            #+#    #+#             */
/*   Updated: 2018/12/05 16:41:40 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*cpy;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_iswhitespace(s[i]))
		i++;
	while (ft_iswhitespace(s[j - 1]))
		j--;
	if (j < i)
		j = i;
	cpy = ft_strnew(j - i);
	if (!cpy)
		return (NULL);
	ft_strncpy(cpy, s + i, j - i);
	return (cpy);
}
