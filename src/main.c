/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:23:14 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/06 14:14:49 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	if (!fract)
		return (1);
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fract->name = argv[1];
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fract->name = argv[1];
		fract->julia.real_x = ft_atodbl(argv[2]);
		fract->julia.i_y = ft_atodbl(argv[3]);
	}
	else
	{
		ft_printf("Usage: ./fractol <fractal>");
		ft_printf("Available fractals: mandelbrot, julia, burningship");
		free(fract);
		return (0);
	}
	init(fract);
	render(fract);
	events(fract);
	mlx_loop(fract->smlx.mlx);
	return (0);
}
