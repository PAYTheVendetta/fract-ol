/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:23:14 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/05 03:08:58 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
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
}

int	main(int argc, char **argv)
{
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	if (!ft_strncmp(argv[1], "mandelbrot", 11) && argc == 2)
		fract->name = argv[1];
	else if (!ft_strncmp(argv[1], "julia", 11) && argc == 4)
		fract->name = argv[1];
	else
	{
		ft_printf("Usage: ./fractol <fractal>");
		ft_printf("Available fractals: mandelbrot, julia, burningship");
		free(fract);
		return (0);
	}
	init(fract);
	/* eventos */
	render(fract);
	/* loop */
	return (0);
}
