/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:49:10 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/23 22:57:26 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkfiletype(va_list argp, const char ptr, int *counter)
{
	if (ptr == 'c')
		*counter += ft_putchar(va_arg(argp, int));
	if (ptr == 's')
		*counter += ft_putstr(va_arg(argp, char *));
	if (ptr == 'd' || ptr == 'i')
		*counter += ft_putnbr(va_arg(argp, int));
	if (ptr == 'x')
		*counter += ft_hexlowercase(va_arg(argp, unsigned int));
	if (ptr == 'X')
		*counter += ft_hexuppercase(va_arg(argp, unsigned int));
	if (ptr == 'p')
		*counter += ft_putptr(va_arg(argp, void *));
	if (ptr == 'u')
		*counter += ft_putunsnbr(va_arg(argp, unsigned int));
	if (ptr == '%')
		*counter += write(1, "%", 1);
}

int	printf_body(int fd, const char *ptr, va_list *args)
{
	int			count;

	count = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			count += ft_printf_check(fd, *ptr, args);
			ptr++;
		}
		else
		{
			count += ft_putchar_pf(fd, *ptr);
			ptr++;
		}
	}
	return (count);
}

int	printf_debug(const char *str, ...)
{
	va_list		args;
	int			count;

	if (!DEBUG)
		return (-1);
	va_start(args, str);
	count = printf_body(2, str, &args);
	va_end(args);
	return (count);
}

int	fd_printf(int fd, const char *str, ...)
{
	va_list		args;
	int			count;

	va_start(args, str);
	count = printf_body(fd, str, &args);
	va_end(args);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			count;

	va_start(args, str);
	count = printf_body(1, str, &args);
	va_end(args);
	return (count);
}
