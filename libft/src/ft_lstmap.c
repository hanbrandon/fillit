/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyang <doyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:26:33 by doyang            #+#    #+#             */
/*   Updated: 2018/12/05 16:06:16 by doyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flist;
	t_list	*ref;

	if (!lst)
		return (NULL);
	flist = f(lst);
	ref = flist;
	while (lst->next)
	{
		lst = lst->next;
		flist->next = f(lst);
		if (!(flist->next))
		{
			free(flist->next);
			return (NULL);
		}
		flist = flist->next;
	}
	return (ref);
}
