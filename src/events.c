/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 04:49:06 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/06 14:33:14 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_window(void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	mlx_destroy_image(fract->smlx.mlx, fract->smlx.img.img_ptr);
	mlx_destroy_window(fract->smlx.mlx, fract->smlx.mlx_wind);
	mlx_destroy_display(fract->smlx.mlx);
	free(fract->smlx.mlx);
	free(fract);
	exit(0);
	return (0);
}

int	maus_handler(int button, int x, int y, void *param)
{
	t_fract		*fract;
	t_complex	pos_maus;
	double		zoom;

	fract = (t_fract *)param;
	if (button == 4 || button == 5)
	{
		pos_maus = real_pixel(x, y, fract);
		if (button == 4)
		{
			zoom = 0.9;
			fract->max_iter += 5;
		}
		else if (button == 5)
		{
			zoom = 1.1;
			fract->max_iter -= 5;
		}
		cal_zoom(fract, pos_maus, zoom);
		render(fract);
	}
	return (0);
}

int	key_handler(int button, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	(void)fract;
	if (button == 65307)
		close_window(param);
	if (button == 65362 || button == 119)
		cal_movi(fract, button);
	if (button == 65364 || button == 115)
		cal_movi(fract, button);
	if (button == 65361 || button == 97)
		cal_movi(fract, button);
	if (button == 65363 || button == 100)
		cal_movi(fract, button);
	render(fract);
	return (0);
}

void	events(t_fract *fract)
{
	mlx_mouse_hook(fract->smlx.mlx_wind, maus_handler, fract);
	mlx_key_hook(fract->smlx.mlx_wind, key_handler, fract);
	mlx_hook(fract->smlx.mlx_wind, 17, 0, close_window, fract);
}
