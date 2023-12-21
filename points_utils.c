/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:22:59 by npremont          #+#    #+#             */
/*   Updated: 2023/12/21 15:37:21 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	*ft_get_rpoint(double *point, t_dim plan)
{
	while (plan.points)
	{
		if (((double *)plan.points->content)[0] == point[0] + plan.stance &&
			((double *)plan.points->content)[1] == point[1])
			return (((double *)plan.points->content));
		plan.points = plan.points->next;
	}
	return (NULL);
}

double	*ft_get_bpoint(double *point, t_dim plan)
{
	while (plan.points)
	{
		if (((double *)plan.points->content)[1] == point[1] + plan.stance &&
			((double *)plan.points->content)[0] == point[0])
			return (((double *)plan.points->content));
		plan.points = plan.points->next;
	}
	return (NULL);
}

void	ft_print_rline(double *point, double *r_point, t_dim plan, t_vars *data)
{
	if (point[2] == r_point[2])
	{
		while (point[0] <= r_point[0])
		{
			if (point[2] == 0)
				ft_putproj(point, plan, data, INT_MAX);
			else
				ft_putproj(point, plan, data, 16572163);
			++point[0];
		}
		point[0] = r_point[0] - plan.stance;
	}
	else
	{
		ft_h_angle_r(point, r_point, plan, data);
	}
}

void	ft_print_bline(double *point, double *b_point, t_dim plan, t_vars *data)
{
	if (point[2] == b_point[2])
	{
		while (point[1] <= b_point[1])
		{
			if (point[2] == 0)
				ft_putproj(point, plan, data, INT_MAX);
			else
				ft_putproj(point, plan, data, 16572163);
			++point[1];
		}
		point[1] = b_point[1] - plan.stance;
	}
	else
	{
		ft_h_angle_b(point, b_point, plan, data);
	}
}
