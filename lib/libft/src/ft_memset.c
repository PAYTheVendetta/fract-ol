/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:21:40 by aialonso          #+#    #+#             */
/*   Updated: 2025/12/03 14:50:08 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	n;
	char	*y;

	n = 0;
	y = (char *)b;
	while (n < len)
	{
		y[n] = c;
		n++;
	}
	return (b);
}

// int	main(void)
// {
// 	void	*m;
// 	int n;

// 	n = 0;
// 	m = ft_memset(m, 'b', 4);
// 	printf("%p\n", m);
// 	while (m != '\0')
// 	{
// 		write(1, &m[n], 1);
// 		n++;
// 	}
// 	return (0);
// }