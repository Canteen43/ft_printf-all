/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:32:24 by kweihman          #+#    #+#             */
/*   Updated: 2024/05/30 15:16:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int	percent_handler(const char *str, va_list args)
{
	str++;
	if (*str == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	if (*str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	if (*str == 's')
		return (ft_putstr_rtn(va_arg(args, char *)));
	if (*str == 'p')
		return (1);
	if (*str == 'd' || *str == 'i')
		return (1);
	if (*str == 'u')
		return (1);
	if (*str == 'x')
		return (1);
	if (*str == 'X')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			char_cnt;

	char_cnt = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			str++;
			char_cnt++;
		}
		else
		{
			char_cnt += percent_handler(str, args);
			str += 2;
		}
	}
	va_end(args);
	return (char_cnt);
}
