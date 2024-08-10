/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specification.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:03:41 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 17:20:43 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char **p_string, va_list args, int *pbp)
{
	t_specs	specs;

	*p_string++;
	if (**p_string == '\0')
		return (-1);
	if (**p_string == '%')
		return (put_percent(pbp, p_string));
	memset(specs.flags, 0, 6);
	specs.field_width = -1;
	specs.precision = -1;
	if (get_specs(&specs, p_string) == -1)
		return (-1);
	if (char_in_str(**p_string, "cspdiuxX") == 0)
		return (-1);
	convert(p_string, args, pbp, &specs);
}

int	convert(char **p_string, va_list args, int *pbp, t_specs *psp)
{
	if (**p_string == 's')
		ft_convert_s(va_arg(args, char *), pbp, psp);
}

int	put_percent(int *pbp, char **p_string)
{
	write(1, "%%", 1);
	*pbp++;
	*p_string++;
	return (0);
}

int	get_specs(t_specs *psp, char **p_string)
{
	if (get_flags(psp, p_string) == -1)
		return (-1);
	if (get_width(psp, p_string) == -1)
		return (-1);
	if (**p_string == '.')
		if (get_prec(psp, p_string) == -1)
			return (-1);
	return (0);
}

int	get_flags(t_specs *psp, char **p_string)
{
	while (char_in_str(**p_string, "-0# +"))
	{
		if (char_in_str(**p_string, psp->flags) == 0)
			add_char_to_flags(**p_string, psp);
		if (char_in_str(**p_string, psp->flags) == 1)
			return (-1);
		*p_string++;
	}
	return (0);
}

int	get_width(t_specs *psp, char **p_string)
{
	while (char_in_str(**p_string, "0123456789"))
	{
		if (psp->field_width == -1)
			psp->field_width = 0;
		if (lmt_check(psp->field_width, **p_string) == -1)
			return (-1);
		psp->field_width *= 10;
		psp->field_width += **p_string - '0';
		*p_string++;
	}
	return (0);
}

// Since the non-negative precision is almost identical to width, I
//  could make them one function.
int	get_prec(t_specs *psp, char **p_string)
{
	psp->precision = 0;
	*p_string++;
	while (char_in_str(**p_string, "0123456789"))
	{
		if (lmt_check(psp->precision, **p_string) == -1)
			return (-1);
		psp->precision *= 10;
		psp->precision += **p_string - '0';
		*p_string++;
	}
	return (0);
}

void	add_char_to_flags(char a, t_specs *psp)
{
	while (*(psp->flags) != '\0')
		(psp->flags)++;
	*(psp->flags) = a;
}
