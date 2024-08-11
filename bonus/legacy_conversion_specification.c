/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specification.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:03:41 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/11 16:36:07 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	// if (**pos == 's')
	// 	res = ft_convert_s(va_arg(args, char *), pbp, psp);
	// if (**pos == 's')
	// 	res = ft_convert_s(va_arg(args, char *), pbp, psp);
	// if (**pos == 's')
	// 	res = ft_convert_s(va_arg(args, char *), pbp, psp);
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

int	get_sp(t_sp *psp, const char **pos)
{
	if (get_fl(psp, pos) == -1)
		return (-1);
	if (get_width(psp, pos) == -1)
		return (-1);
	if (**pos == '.')
		if (get_prec(psp, pos) == -1)
			return (-1);
	return (0);
}

int	get_fl(t_sp *psp, const char **pos)
{
	while (char_in_str(**pos, "-0# +"))
	{
		if (char_in_str(**pos, psp->fl) == 1)
			return (-1);
		if (char_in_str(**pos, psp->fl) == 0)
			add_char_to_fl(**pos, psp);
		(*pos)++;
	}
	return (0);
}

int	get_width(t_sp *psp, const char **pos)
{
	while (char_in_str(**pos, "0123456789"))
	{
		if (psp->fw == -1)
			psp->fw = 0;
		if (lmt_check(psp->fw, **pos) == -1)
			return (-1);
		psp->fw *= 10;
		psp->fw += **pos - '0';
		(*pos)++;
	}
	return (0);
}

// Since the non-negative pr is almost identical to width, I
//  could make them one function.
int	get_prec(t_sp *psp, const char **pos)
{
	psp->pr = 0;
	(*pos)++;
	while (char_in_str(**pos, "0123456789"))
	{
		if (lmt_check(psp->pr, **pos) == -1)
			return (-1);
		psp->pr *= 10;
		psp->pr += **pos - '0';
		(*pos)++;
	}
	return (0);
}

void	add_char_to_fl(char a, t_sp *psp)
{
	int	i;

	i = 0;
	while (psp->fl[i] != '\0')
		i++;
	psp->fl[i] = a;
}
