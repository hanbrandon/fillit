/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:22:30 by doyang            #+#    #+#             */
/*   Updated: 2018/12/03 23:12:14 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	if (!s || (start + len) > ft_strlen(s))
		return (NULL);
	substr = ft_strnew(len);
	if (!substr)
		return (NULL);
	return (ft_strncpy(substr, s + start, len));
}
