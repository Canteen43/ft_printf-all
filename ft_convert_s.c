/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:10:50 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 13:59:18 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// In clang, "#0+ " all give "unspecified behavior" warnings, 
//  so I decided they will return error.
// Printf manual only states "unspecified behavior" for "#0".
int	ft_convert_s(char *str, int *p_bytes_printed, t_specs *p_specs)
{
	if (chars_in_str("#0+ ", p_specs->flags))
		return (-1);
	
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	char_cnt = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		char_cnt++;
	}
	return (char_cnt);

	if (p_specs->precision < 0)
		normal string;
	if (p_specs->precision >= 0)
		normal string;
}
