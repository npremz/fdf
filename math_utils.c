/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:31:04 by npremont          #+#    #+#             */
/*   Updated: 2023/12/21 16:23:54 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

u_int32_t	ft_hexstr2int(char *hex)
{
	u_int32_t	val;
	u_int8_t	byte;
	size_t		i;

	val = 0;
	byte = 0;
	i = 0;
	while (hex[i])
	{
		byte = hex[i++];
		if (byte >= '0' && byte <= '9')
			byte -= '0';
		else if (byte >= 'a' && byte <= 'f')
			byte -= 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte -= 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}

double	*ft_init_point(int x, int y, char *z, int stance)
{
	double	*point;
	char	*color;

	point = malloc(sizeof(double) * 4);
	if (!point)
		return (NULL);
	point[0] = x * stance;
	point[1] = y * stance;
	point[2] = -(ft_atoi(z)) * stance / 10;
	color = ft_strchr(z, 'x');
	if (color)
		point[3] = ft_hexstr2int(color);
	else
		point[3] = 0;
	return (point);
}

t_list	*ft_getpoints(char ***map, int stance)
{
	int		i;
	int		j;
	t_list	*points;
	double	*point;

	i = 0;
	j = 0;
	points = NULL;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			point = ft_init_point(i, j, map[j][i], stance);
			if (!point)
				return (ft_lstclear(&points, &ft_free), NULL);
			ft_lstadd_back(&points, ft_lstnew(point));
			++i;
		}
		++j;
	}
	return (points);
}

t_dim	ft_get_dim(char ***map)
{
	int		height;
	int		width;
	t_dim	dim;
	int		stance;

	height = 0;
	width = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			++width;
		}
		++height;
	}
	stance = STANCE;
	while ((stance * (height * 2)) > HEIGHT && (stance * (width * 2)) > WIDTH)
		--stance;
	dim.height = (height - 1) * stance;
	dim.width = (width - 1) * stance;
	dim.stance = stance;
	dim.points = ft_getpoints(map, stance);
	return (dim);
}
