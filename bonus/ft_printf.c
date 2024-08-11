/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:40:48 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/11 16:54:37 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *os, ...)
{
	va_list		args;
	int			bp;

	bp = 0;
	va_start(args, os);
	while (*os)
	{
		if (*os != '%')
			print_character(&os, &bp);
		else if (handle_conversion(&os, args, &bp) == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (bp);
}

void	print_character(const char **pos, int *pbp)
{
	write(1, *pos, 1);
	(*pos)++;
	(*pbp)++;
}

int	handle_conversion(const char **pos, va_list args, int *pbp)
{
	t_sp	sp;

	(*pos)++;
	if (**pos == '\0')
		return (-1);
	if (**pos == '%')
		return (put_percent(pbp, pos));
	ft_memset(sp.fl, 0, 6);
	sp.fw = -1;
	sp.pr = -1;
	if (get_sp(&sp, pos) == -1)
		return (-1);
	if (char_in_str(**pos, "cspdiuxX") == 0)
		return (-1);
	if (convert(pos, args, pbp, &sp) == -1)
		return (-1);
	(*pos)++;
	return (0);
}

int	convert(const char **pos, va_list args, int *pbp, t_sp *psp)
{
	int	res;

	if (**pos == 's')
		res = ft_convert_s(va_arg(args, char *), pbp, psp);
	if (**pos == 'x' || **pos == 'X')
		res = ft_convert_x(va_arg(args, unsigned int), pbp, psp);
	if (res == -1)
		return (-1);
	return (0);
}

int	put_percent(int *pbp, const char **pos)
{
	write(1, "%%", 1);
	(*pbp)++;
	(*pos)++;
	return (0);
}
