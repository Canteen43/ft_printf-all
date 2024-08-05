/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:03:41 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/05 17:44:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char **p_string, va_list args, int *p_bytes_printed)
{
	t_conv_specs	specs;

	*p_string++;
	if (**p_string == '\0')
		return (-1);
	if (**p_string == '%')
		return (put_percent(p_bytes_printed, p_string));
	get_specs(&specs, p_string);
}

int	put_percent(int *p_bytes_printed, char **p_string)
{
	write(1, "%%", 1);
	*p_bytes_printed++;
	*p_string++;
	return (0);
}

int	get_specs(t_conv_specs *p_specs, char **p_string)
{
	if (get_flags(p_specs, p_string) == -1)
		return (-1);
}

int	get_flags(t_conv_specs *p_specs, char **p_string)
{
	while (is_flag(p_string))
	{
		if (**p_string == "-")
		{
			if (p_specs->left_adjusted == 1)
				return (-1);
			p_specs->left_adjusted = 1;
		}
		if (**p_string == "0")
			p_specs->zero_padded = 1;
		if (**p_string == "#")
			p_specs->left_adjusted = 1;
		if (**p_string == " ")
			p_specs->add_space = 1;
		if (**p_string == "+")
			p_specs->add_plus = 1;
		*p_string++;
	}

}

int	is_flag(char **p_string)
{
	if (**p_string == "-")
		return (1);
	if (**p_string == "0")
		return (1);
	if (**p_string == "#")
		return (1);
	if (**p_string == " ")
		return (1);
	if (**p_string == "+")
		return (1);
	return (0);
}
