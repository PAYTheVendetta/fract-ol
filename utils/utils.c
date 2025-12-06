/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:39:07 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/06 14:32:22 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_complex	real_pixel(double x, double y, t_fract	*fract)
{
	t_complex	relative;
	double		real_max;
	double		real_min;

	real_max = fract->range_r.real_x;
	real_min = fract->range_r.i_y;
	relative.real_x = (x / (WIDTH - 1)) * (real_max - real_min) + real_min;
	real_max = fract->range_i.real_x;
	real_min = fract->range_i.i_y;
	relative.i_y = real_max - (y / (HEIGHT - 1)) * (real_max - real_min);
	return (relative);
}

t_complex	what_fractal(int x, int y, t_complex *c, t_fract *fract)
{
	t_complex	z;

	z.i_y = 0;
	z.real_x = 0;
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		*c = fract->julia;
		return (real_pixel(x, y, fract));
	}
	else
		*c = real_pixel(x, y, fract);
	return (z);
}

void	cal_movi(t_fract *fract, int button)
{
	double	move_x;
	double	move_y;

	move_x = (fract->range_r.real_x - fract->range_r.i_y) * 0.05;
	move_y = (fract->range_i.real_x - fract->range_i.i_y) * 0.05;
	if (button == 65362 || button == 119)
	{
		fract->range_i.real_x += move_y;
		fract->range_i.i_y += move_y;
	}
	else if (button == 65364 || button == 115)
	{
		fract->range_i.real_x -= move_y;
		fract->range_i.i_y -= move_y;
	}
	else if (button == 65361 || button == 97)
	{
		fract->range_r.real_x -= move_x;
		fract->range_r.i_y -= move_x;
	}
	else if (button == 65363 || button == 100)
	{
		fract->range_r.real_x += move_x;
		fract->range_r.i_y += move_x;
	}
}

void	cal_zoom(t_fract *fract, t_complex pos_maus, double zoom)
{
	double	range_real;
	double	range_img;

	range_real = (fract->range_r.i_y - pos_maus.real_x) * zoom;
	fract->range_r.i_y = pos_maus.real_x + range_real;
	range_real = (fract->range_r.real_x - pos_maus.real_x) * zoom;
	fract->range_r.real_x = pos_maus.real_x + range_real;
	range_img = (fract->range_i.i_y - pos_maus.i_y) * zoom;
	fract->range_i.i_y = pos_maus.i_y + range_img;
	range_img = (fract->range_i.real_x - pos_maus.i_y) * zoom;
	fract->range_i.real_x = pos_maus.i_y + range_img;
}
