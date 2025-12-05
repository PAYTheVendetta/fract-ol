/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:17:56 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/05 03:20:22 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	map(double unscaled_num, double new_min,
		double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}
