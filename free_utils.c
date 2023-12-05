/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:02:51 by npremont          #+#    #+#             */
/*   Updated: 2023/11/20 14:52:07 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

void	ft_free_ds(char ***split, size_t og_i)
{
	if (!split)
		return ;
	while (split[og_i] != 0)
	{
		ft_free_split(split[og_i]);
		--og_i;
	}
	free(split);
}

void	ft_free_map(char ***map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		ft_free_split(map[i]);
		++i;
	}
	free(map);
}

void	ft_free_struc(t_vars *vars)
{
	ft_free_map(vars->map);
	ft_lstclear(&vars->plan.points, free);
	free(vars);
}
