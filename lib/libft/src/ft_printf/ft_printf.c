/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aialonso <aialonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:49:06 by aialonso          #+#    #+#             */
/*   Updated: 2025/11/30 09:46:24 by aialonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_type(va_list arg, int typ)
{
	if (typ == 'c')
		return (ft_putchar_fd((char)va_arg(arg, int), 1));
	if (typ == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	if (typ == 'p')
		return (ft_ptoa(va_arg(arg, void *)));
	if (typ == 'd' || typ == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	if (typ == 'u')
		return (ft_putnbrnb_fd(va_arg(arg, unsigned int), 1, 10, 'a'));
	if (typ == 'x')
		return (ft_putnbrnb_fd(va_arg(arg, unsigned int), 1, 16, 'a'));
	if (typ == 'X')
		return (ft_putnbrnb_fd(va_arg(arg, unsigned int), 1, 16, 'A'));
	if (typ == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *text, ...)
{
	va_list	arg;
	size_t	n;
	size_t	charcoun;

	n = 0;
	charcoun = 0;
	if (!text)
		return (0);
	va_start(arg, text);
	while (text[n])
	{
		if (text[n] == '%')
		{
			charcoun = charcoun + get_type(arg, text[n + 1]);
			n = n + 2;
		}
		else
		{
			write(1, &text[n], 1);
			charcoun++;
			n++;
		}
	}
	return (charcoun);
}

/* int	main(void)
{
	printf("%d\n", ft_printf(" %x ", -1));
	printf("%d\n", printf(" %x ", -1));
	return (0);
} */