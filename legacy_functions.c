/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:07:12 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 17:07:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_convert_s(char *str, int *p_bytes_printed, t_specs *p_specs)
{
	if (chars_in_str("#0+ ", p_specs->flags))
		return (-1);
	if (str == NULL)
	{
		str = "(null)";
		p_specs->precision = 6;
	}
	p_specs->precision = set_length(str, p_specs->precision);
	if (p_specs->field_width <= p_specs->precision)
		write_str(str, p_bytes_printed, p_specs->precision);
	else
	{
		if (char_in_str('-', p_specs->flags) == 1)
		{
			write_str(str, p_bytes_printed, p_specs->precision);
			put_fillers(' ', p_specs->field_width - p_specs->precision, p_bytes_printed);
		}
		if (char_in_str('-', p_specs->flags) == 0)
		{
			put_fillers(' ', p_specs->field_width - p_specs->precision, p_bytes_printed);
			write_str(str, p_bytes_printed, p_specs->precision);
		}
	}
}