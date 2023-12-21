/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:22:40 by npremont          #+#    #+#             */
/*   Updated: 2023/12/21 15:53:28 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;
	t_data	*img;

	img = &data->img;
	if (y < 0 || y >= HEIGHT || x < 0 
		|| x >= WIDTH)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_close(int keycode, t_vars *vars)
{
	if (keycode)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_struc(vars);
	}
	else
	{
		ft_free_struc(vars);
		free(vars);
	}
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		ft_close(53, vars);
	}
	return (0);
}

int	ft_on_close(t_vars *vars)
{
	ft_close(1, vars);
	return (0);
}
