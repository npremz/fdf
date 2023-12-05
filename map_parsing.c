/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:36 by npremont          #+#    #+#             */
/*   Updated: 2023/11/22 12:41:45 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_getfile(int fd, int *size)
{
	char	*line;
	char	*file;

	if (fd < 0)
		return (NULL);
	file = calloc(1, sizeof(char));
	if (!file)
		return (NULL);
	*size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
		{
			++*size;
			file = ft_strjoin(file, line);
		}
		free(line);
	}
	return (file);
}

char	***ft_map_parsing(int fd)
{
	char	*file;
	char	***res;
	char	**tmp;
	int		i;
	int		oi;

	file = ft_getfile(fd, &i);
	if (!file)
		return (NULL);
	tmp = ft_split(file, '\n');
	if (!tmp)
		return (free(file), NULL);
	res = malloc((i + 1) * (sizeof(char ***)));
	if (!res)
		return (ft_free_split(tmp), free(file), NULL);
	oi = i - 1;
	res[i] = 0;
	while (i-- > 0)
	{
		res[i] = ft_split(tmp[i], ' ');
		if (!res[i])
			return (ft_free_ds(res, oi), ft_free_split(tmp), free(file), NULL);
	}
	ft_free_split(tmp);
	return (free(file), res);
}
