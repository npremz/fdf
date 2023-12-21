/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:25:28 by npremont          #+#    #+#             */
/*   Updated: 2023/12/21 16:07:17 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putproj(double *point, t_dim plan, t_vars *data, int color)
{
	double	x_proj;
	double	y_proj;

	x_proj = (point[0] - point[1]) / sqrt(2) + plan.width;
	y_proj = (point[0] + 2 * point[1] + point[2]) / sqrt(6) + 10;
	if (point[3] != 0)
		color = point[3];
	ft_mlx_pixel_put(data, x_proj, y_proj, color);
}

void	ft_printjoin(t_vars *data, t_dim plan)
{
	double	*point;
	double	*b_point;
	double	*r_point;

	while (plan.points)
	{
		point = (double *)plan.points->content;
		r_point = ft_get_rpoint(point, plan);
		b_point = ft_get_bpoint(point, plan);
		if (r_point)
			ft_print_rline(point, r_point, plan, data);
		if (b_point)
			ft_print_bline(point, b_point, plan, data);
		plan.points = plan.points->next;
	}
}

void	ft_screen_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx)
	{
		vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FdF");
		vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
		vars->img.addr = mlx_get_data_addr(vars->img.img,
				&vars->img.bits_per_pixel,
				&vars->img.line_length, &vars->img.endian);
		ft_printjoin(vars, vars->plan);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
		mlx_key_hook(vars->win, key_hook, vars);
		mlx_hook(vars->win, 17, 0, ft_on_close, vars);
		mlx_loop(vars->mlx);
	}
	else 
	{
		ft_free_map(vars->map);
		ft_printf("Erreur d'image\n");
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	int		fd;
	t_vars	*vars;

	if (ac != 2)
		return (ft_printf("Erreur : Le programme prend 1 argument\n"), 0);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (perror("Malloc error:"), 1);
	fd = open(av[1], O_RDONLY);
	vars->map = ft_map_parsing(fd);
	close(fd);
	if (!vars->map)
		return (free(vars), perror("Error"), 1);
	vars->plan = ft_get_dim(vars->map);
	if (vars->plan.points == NULL)
	{
		ft_printf("Erreur d'allocation\n");
		return (ft_free_map(vars->map), free(vars), 1);
	}
	ft_screen_init(vars);
	ft_close(0, vars);
	return (0);
}
