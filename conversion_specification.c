/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:03:41 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/08 11:36:32 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char **p_string, va_list args, int *p_bytes_printed)
{
	t_specs	specs;

	*p_string++;
	if (**p_string == '\0')
		return (-1);
	if (**p_string == '%')
		return (put_percent(p_bytes_printed, p_string));
	memset(specs.flags, 0, 6);
	specs.field_width = -1;
	specs.precision = -1;
	if (get_specs(&specs, p_string) == -1)
		return (-1);
}

int	put_percent(int *p_bytes_printed, char **p_string)
{
	write(1, "%%", 1);
	*p_bytes_printed++;
	*p_string++;
	return (0);
}

int	get_specs(t_specs *p_specs, char **p_string)
{
	if (get_flags(p_specs, p_string) == -1)
		return (-1);
}

int	get_flags(t_specs *p_specs, char **p_string)
{
	while (char_in_str(**p_string, "-0# +"))
	{
		if (char_in_str(**p_string, p_specs->flags) == 0)
			add_char_to_flags(**p_string, p_specs);
		if (char_in_str(**p_string, p_specs->flags) == 1)
			return (-1);
		*p_string++;
	}
	while (char_in_str(**p_string, "0123456789"))
	{
		adjust field_width with atoi;
		*p_string++;
	}
	if (**p_string == '.')
	{
		p_specs->precision = 0;
		*p_string++;
	}
	while (char_in_str(**p_string, "0123456789"))
	{
		adjust precision with atoi;
		*p_string++;
	}
}

void	add_char_to_flags(char a, t_specs *p_specs)
{
	while (*(p_specs->flags) != '\0')
		(p_specs->flags)++;
	*(p_specs->flags) = a;
}
