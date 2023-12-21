/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2123/11/16 15:53:51 by npremont          #+#    #+#             */
/*   Updated: 2023/12/21 15:34:14 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_h_angle_r(double *point, double *des_point, t_dim plan, t_vars *data)
{
	double	height;
	double	og_z;
	double	line_len;
	double	i;

	og_z = point[2];
	if (point[2] < des_point[2])
		height = point[2] - des_point[2];
	else
		height = des_point[2] - point[2];
	line_len = sqrt(pow(data->plan.stance, 2) + pow(height, 2));
	i = 0;
	while (i < line_len)
	{
		ft_putproj(point, plan, data, 13183502);
		point[0] += data->plan.stance / line_len;
		if (point[2] < des_point[2])
			point[2] -= height / line_len;
		else
			point[2] += height / line_len;
		++i;
	}
	point[0] = des_point[0] - data->plan.stance;
	point[2] = og_z;
}

void	ft_h_angle_b(double *point, double *des_point, t_dim plan, t_vars *data)
{
	double	height;
	double	og_z;
	double	line_len;
	double	i;

	og_z = point[2];
	if (point[2] < des_point[2])
		height = point[2] - des_point[2];
	else
		height = des_point[2] - point[2];
	line_len = sqrt(pow(data->plan.stance, 2) + pow(height, 2));
	i = 0;
	while (i < line_len)
	{
		ft_putproj(point, plan, data, 13183502);
		point[1] += data->plan.stance / line_len;
		if (point[2] < des_point[2])
			point[2] -= height / line_len;
		else
			point[2] += height / line_len;
		++i;
	}
	point[1] = des_point[1] - data->plan.stance;
	point[2] = og_z;
}
