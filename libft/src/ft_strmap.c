/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:38:30 by doyang            #+#    #+#             */
/*   Updated: 2018/12/05 16:44:33 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*temp;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	temp = ft_strnew(ft_strlen(s));
	if (!temp)
		return (NULL);
	while (s[i])
	{
		temp[i] = f(s[i]);
		i++;
	}
	return (temp);
}
