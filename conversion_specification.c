/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:03:41 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/07 18:54:23 by kweihman         ###   ########.fr       */
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
	while (char_in_str(**p_string, "-0# +"))
	{
		if (value_of_spec(**p_string) == 0)
			make value 1
		if (value_of_spec(**p_string) == 1)
			Return error
		*p_string++;
	}
	while (char_in_str(**p_string, "0123456789"))
		adjust field_width with atoi
		*p_string++;
	if (**p_string == '.')
		*p_string++;
	while (char_in_str(**p_string, "0123456789"))
		adjust precision with atoi
		*p_string++;
	

}



int	value_of_spec(t_conv_specs *p_specs, char a)
{
	if (a == '-')
		return(p_specs->left_adjusted)
	if (a == '0')
		return(p_specs->zero_padded)
	if (a == '#')
		return(p_specs->alt_form)
	if (a == ' ')
		return(p_specs->add_plus)
	if (a == '+')
		return(p_specs->add_plus)
}

