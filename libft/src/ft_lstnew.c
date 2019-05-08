/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:36:55 by doyang            #+#    #+#             */
/*   Updated: 2018/12/05 16:16:09 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *freshlink;

	freshlink = (t_list *)ft_memalloc(sizeof(t_list));
	if (!freshlink)
		return (NULL);
	if (!content)
	{
		freshlink->content = NULL;
		content_size = 0;
	}
	else
	{
		freshlink->content = ft_memalloc(content_size);
		if (!(freshlink->content))
		{
			free(freshlink);
			return (NULL);
		}
		ft_memcpy(freshlink->content, content, content_size);
	}
	freshlink->content_size = content_size;
	freshlink->next = NULL;
	return (freshlink);
}
