/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:10:21 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/06 14:17:41 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	init_data(t_fract	*fract)
{
	fract->range_r.real_x = 1.0;
	fract->range_r.i_y = -2.0;
	fract->range_i.real_x = 1.5;
	fract->range_i.i_y = -1.5;
	if (!ft_strncmp(fract->name, "julia", 5))
	{
		fract->range_r.real_x = 2.0;
		fract->range_r.i_y = -2.0;
		fract->range_i.real_x = 2.0;
		fract->range_i.i_y = -2.0;
	}
	fract->max_iter = 50;
}

void	init(t_fract	*fract)
{
	fract->smlx.mlx = mlx_init();
	if (fract->smlx.mlx == NULL)
		malloc_error();
	fract->smlx.mlx_wind = mlx_new_window(fract->smlx.mlx,
			WIDTH, HEIGHT, fract->name);
	if (fract->smlx.mlx_wind == NULL)
	{
		mlx_destroy_display(fract->smlx.mlx);
		free(fract->smlx.mlx);
		malloc_error();
	}
	fract->smlx.img.img_ptr = mlx_new_image(fract->smlx.mlx,
			WIDTH, HEIGHT);
	if (fract->smlx.img.img_ptr == NULL)
	{
		mlx_destroy_window(fract->smlx.mlx, fract->smlx.mlx_wind);
		mlx_destroy_display(fract->smlx.mlx);
		free(fract->smlx.mlx);
		malloc_error();
	}
	fract->smlx.img.pixels_ptr = mlx_get_data_addr(fract->smlx.img.img_ptr,
			&fract->smlx.img.bpp, &fract->smlx.img.line_len,
			&fract->smlx.img.endian);
	init_data(fract);
}
