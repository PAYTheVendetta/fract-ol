/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:09:21 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/05 03:17:48 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	handle_pixel(int x, int y, t_fract *fract)
{
	t_fract	z;
	t_fract	c;
	int		i;
	int		color;

	i = 0;
	while (i)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real_x * z.real_x) + (z.i_y * z.i_y))
		{
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
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
}
