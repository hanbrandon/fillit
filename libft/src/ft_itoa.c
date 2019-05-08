/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:14:09 by doyang            #+#    #+#             */
/*   Updated: 2018/12/05 02:57:07 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigit(long n)
{
	int		i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	ft_checknegative(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int		digitlen;
	long	mod;
	int		negbool;
	char	*alpha;

	mod = n;
	negbool = ft_checknegative(mod);
	digitlen = ft_countdigit(mod);
	alpha = ft_strnew(digitlen + negbool);
	if (!alpha)
		return (NULL);
	if (negbool)
	{
		mod = -mod;
		alpha[0] = '-';
	}
	while (digitlen > 0)
	{
		alpha[digitlen - 1 + negbool] = (mod % 10) + '0';
		digitlen--;
		mod /= 10;
	}
	return (alpha);
}
