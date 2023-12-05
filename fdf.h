/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:41:07 by npremont          #+#    #+#             */
/*   Updated: 2023/12/04 11:45:34 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft/libft.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* CONSTANTES */

#define STANCE 10

/* STRUCTURES */

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_dim {
	int		width;
	int		height;
	int		depth;
	t_list	*points;
}				t_dim;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	char	***map;
	t_dim	plan;
}				t_vars;

/* FUNCTIONS */

char	***ft_map_parsing(int fd);
void	ft_mlx_pixel_put(t_vars *data, int x, int y, int color);
void	ft_close(int keycode, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int mousecode, t_vars *vars);
t_dim	ft_get_dim(char ***map);
double	*ft_get_rpoint(double *point, t_dim plan);
double	*ft_get_bpoint(double *point, t_dim plan);
void	ft_putproj(double *point, t_dim plan, t_vars *data, int color);
void	ft_print_rline(double *point, double *r_point, t_dim plan, 
			t_vars *data);
void	ft_print_bline(double *point, double *b_point, t_dim plan, 
			t_vars *data);
void	ft_h_angle_r(double *point, double *des_point, t_dim plan,
			t_vars *data);
void	ft_h_angle_b(double *point, double *des_point, t_dim plan,
			t_vars *data);
void	ft_free(void *ptr);
void	ft_free_split(char **split);
void	ft_free_ds(char ***split, size_t og_i);
void	ft_free_map(char ***map);
void	ft_free_struc(t_vars *vars);
int		ft_checkmap(char ***map);
int		ft_on_close(t_vars *vars);
