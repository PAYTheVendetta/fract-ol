/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 03:24:17 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/06 14:18:48 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_pixel_put(int x, int y, t_ftimg *img, int color)
{
	char	*pixel;
	int		bytes_per_pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	bytes_per_pixel = img->bpp / 8;
	pixel = img->pixels_ptr + (y * img->line_len + x * bytes_per_pixel);
	*(unsigned int *)pixel = (unsigned int)color;
}
