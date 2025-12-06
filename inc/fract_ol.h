/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:23:05 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/06 14:32:43 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include <mlx.h>

# define WIDTH  800
# define HEIGHT 800

typedef struct s_ftimg
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_ftimg;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_wind;
	t_ftimg	img;
}	t_mlx;

typedef struct s_complex
{
	double	real_x;
	double	i_y;
}	t_complex;

typedef struct s_fract
{
	char		*name;
	t_complex	range_r;
	t_complex	range_i;
	int			max_iter;
	t_complex	julia;
	t_mlx		smlx;
}	t_fract;

/* init */
void		init(t_fract	*fract);
void		render(t_fract *fract);

/* draw */
void		my_pixel_put(int x, int y, t_ftimg *img, int color);

/* events */
void		events(t_fract *fract);
int			key_handler(int button, void *param);
int			maus_handler(int button, int x, int y, void *param);
int			close_window(void *param);

/* utils */
t_complex	real_pixel(double x, double y, t_fract	*fract);
t_complex	what_fractal(int x, int y, t_complex *c, t_fract *fract);
void		cal_movi(t_fract *fract, int button);
void		cal_zoom(t_fract *fract, t_complex pos_maus, double zoom);

#endif