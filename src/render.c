/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:09:21 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/06 14:44:03 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_complex	cal_fractal(t_complex	z, t_complex c)
{
	t_complex	tmp;

	tmp.real_x = (z.real_x * z.real_x) - (z.i_y * z.i_y) + c.real_x;
	tmp.i_y = (2 * (z.real_x * z.i_y)) + c.i_y;
	return (tmp);
}

int	cal_color(double i, t_fract *fract)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		color;

	t = i / fract->max_iter;
	r = t * 153;
	g = t * 138;
	b = t * 209;
	color = (r << 16) | (g << 8) | b;
	return (color);
}

static void	handle_pixel(int x, int y, t_fract	*fract)
{
	int			i;
	int			color;
	t_complex	poin_real;
	t_complex	z;

	i = 0;
	poin_real = real_pixel(x, y, fract);
	z = what_fractal(x, y, &poin_real, fract);
	while (i < fract->max_iter)
	{
		z = cal_fractal(z, poin_real);
		if ((z.real_x * z.real_x + z.i_y * z.i_y) > 4)
		{
			color = cal_color(i, fract);
			my_pixel_put(x, y, &fract->smlx.img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fract->smlx.img, 0);
}

void	render(t_fract *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fract);
		}
	}
	mlx_put_image_to_window(fract->smlx.mlx, fract->smlx.mlx_wind,
		fract->smlx.img.img_ptr, 0, 0);
}
