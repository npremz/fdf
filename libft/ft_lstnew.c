/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:52:08 by npremont          #+#    #+#             */
/*   Updated: 2023/12/27 12:41:58 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;
	char	*to_close;

	elem = NULL;
	elem = (t_list *)malloc(sizeof(t_list));
	if (elem)
	{
		to_close = ft_strrchr((char *)content, '\n');
		if (to_close)
			*(char *)to_close = '\0';
		elem->content = content;
		elem->next = NULL;
	}
	return (elem);
}
