/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:23:05 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/05 02:30:41 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

# define WIDTH  800
# define HEIGHT 800

typedef struct s_ftimg
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_ftimg;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_wind;
	t_ftimg	img;
}	t_mlx;

typedef struct s_fract
{
	char	*name;
	double	real_x;
	double	i_y;
	t_mlx	smlx;
}	t_fract;


#endif