/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:10:50 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 17:10:57 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// In clang, "#0+ " all give "unspecified behavior" warnings, 
//  so I decided they will return error.
// Printf manual only states "unspecified behavior" for "#0".
int	ft_convert_s(char *str, int *p_bytes_printed, t_specs *psp)
{
	if (chars_in_str("#0+ ", psp->flags))
		return (-1);
	if (str == NULL)
	{
		str = "(null)";
		psp->precision = 6;
	}
	psp->precision = set_length(str, psp->precision);
	if (char_in_str('-', psp->flags) == 1 && psp->field_width > psp->precision)
		put_fillers(' ', psp->field_width - psp->precision, p_bytes_printed);
	write_str(str, p_bytes_printed, psp->precision);
	if (char_in_str('-', psp->flags) == 0 && psp->field_width > psp->precision)
		put_fillers(' ', psp->field_width - psp->precision, p_bytes_printed);
}

void	write_str(char *str, int *p_bytes_printed, int prec)
{
	while (prec != 0)
	{
		write(1, str, 1);
		str++;
		(*p_bytes_printed)++;
		prec--;
	}
}

void	put_fillers(char filler, int amount, int *p_bytes_printed)
{
	while (amount != 0)
	{
		write(1, &filler, 1);
		amount--;
		(*p_bytes_printed)++;
	}
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
