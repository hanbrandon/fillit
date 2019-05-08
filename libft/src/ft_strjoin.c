/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:21:49 by doyang            #+#    #+#             */
/*   Updated: 2018/12/05 16:43:02 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *ccat;

	if (!s1 || !s2)
		return (NULL);
	ccat = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ccat)
		return (NULL);
	ft_strcpy(ccat, s1);
	ft_strcat(ccat, s2);
	return (ccat);
}
