/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:34:41 by aialonso          #+#    #+#             */
/*   Updated: 2025/11/30 18:33:01 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	n;

	n = 0;
	if (s == NULL)
		return (write(fd, "(null)", 6));
	if (!s)
		return (n);
	while (s[n])
		n += write(fd, &s[n], 1);
	return (n);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	let;
	int		len;

	len = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		len += write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		len += ft_putnbr_fd((n / 10), fd);
		len += ft_putnbr_fd((n % 10), fd);
	}
	if (n < 10)
	{
		let = n + '0';
		len += write(fd, &let, 1);
	}
	return (len);
}

int	ft_putnbrnb_fd(size_t n, int fd, unsigned int bas, char c)
{
	char	let;
	int		len;

	len = 0;
	if (n >= bas)
	{
		len += ft_putnbrnb_fd((n / bas), fd, bas, c);
		len += ft_putnbrnb_fd((n % bas), fd, bas, c);
	}
	if (n < bas)
	{
		if (n < 10)
			let = n + '0';
		else
			let = c + (n - 10);
		len += write(fd, &let, 1);
	}
	return (len);
}

int	ft_ptoa(void *address)
{
	size_t	count;
	ssize_t	num;

	num = (ssize_t)address;
	if (address != NULL)
	{
		count = ft_putstr_fd("0x", 1);
		count += ft_putnbrnb_fd(num, 1, 16, 'a');
	}
	else
		return (write(1, "(nil)", 5));
	return (count);
}
