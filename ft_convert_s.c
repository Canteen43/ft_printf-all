/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:10:50 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 15:57:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// In clang, "#0+ " all give "unspecified behavior" warnings, 
//  so I decided they will return error.
// Printf manual only states "unspecified behavior" for "#0".
int	ft_convert_s(char *str, int *p_bytes_printed, t_specs *p_specs)
{
	char *ns;

	ns = "(null)";
	if (chars_in_str("#0+ ", p_specs->flags))
		return (-1);
	if (str == NULL)
	{
		str = ns;
		p_specs->precision = 6;
	}
	p_specs->precision = set_length(str, p_specs->precision);
	if field width is smaller than precision, print string;
	if field width is bigger than prec, check minus flags, print spaces, print str;
	dont forget to update bytes printed;
}

int	set_length(char *str, int prec)
{
	int	cnt;

	cnt = 0;
	while (*str && prec != 0)
	{
		cnt++;
		str++;
		prec--;
	}
	return (cnt);
}
