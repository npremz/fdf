/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:36 by npremont          #+#    #+#             */
/*   Updated: 2023/12/27 14:03:26 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*ft_getfile(int fd)
{
	char	*line;
	t_list	*node;
	t_list	*file;

	if (fd < 0)
		return (NULL);
	file = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
		{
			node = ft_lstnew(line);
			if (!node)
				return (ft_lstclear(&file, free), NULL);
			ft_lstadd_back(&file, node);
		}
	}
	return (file);
}

char	***ft_map_parsing(int fd)
{
	t_list	*file;
	t_list	*head;
	char	***res;
	int		i;

	file = ft_getfile(fd);
	if (!file)
		return (NULL);
	res = malloc((ft_lstsize(file) + 1) * (sizeof(char ***)));
	if (!res)
		return (ft_lstclear(&file, free), NULL);
	i = 0;
	head = file;
	while (file)
	{
		res[i] = ft_split((char *)file->content, ' ');
		if (!res[i])
			return (ft_free_ds(res), ft_lstclear(&file, free), NULL);
		++i;
		file = file->next;
	}
	res[i] = 0;
	ft_lstclear(&head, free);
	return (res);
}
