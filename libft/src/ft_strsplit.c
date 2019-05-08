/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:03:03 by doyang            #+#    #+#             */
/*   Updated: 2018/12/05 16:42:06 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getnext(const char *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static int	ft_wordlen(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**wordlist;
	int		wcount;
	int		track;

	if (!s)
		return (NULL);
	track = 0;
	wcount = ft_countword((char *)s, c);
	wordlist = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!wordlist)
		return (NULL);
	while (track < wcount)
	{
		s = ft_getnext(s, c);
		wordlist[track] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (!wordlist[track])
		{
			ft_freefail((char **)wordlist, track);
			return (NULL);
		}
		track++;
		s += ft_wordlen(s, c);
	}
	wordlist[track] = NULL;
	return (wordlist);
}
