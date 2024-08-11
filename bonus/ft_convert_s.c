/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:10:50 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/11 16:34:18 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// In clang, "#0+ " all give "unspecified behavior" warnings, 
//  so I decided they will return error.
// Printf manual only states "unspecified behavior" for "#0".
int	ft_convert_s(char *str, int *pbp, t_sp *psp)
{
	if (chars_in_str("#0+ ", psp->fl))
		return (-1);
	if (str == NULL)
	{
		if (psp->pr >= 0 && psp->pr <= 5)
			str = "";
		else
			str = "(null)";
	}
	psp->pr = set_length(str, psp->pr);
	if (char_in_str('-', psp->fl) == 1 && psp->fw > psp->pr)
		put_fillers(' ', psp->fw - psp->pr, pbp);
	write_str(str, pbp, psp->pr);
	if (char_in_str('-', psp->fl) == 0 && psp->fw > psp->pr)
		put_fillers(' ', psp->fw - psp->pr, pbp);
	return (0);
}

void	write_str(char *str, int *pbp, int prec)
{
	while (prec != 0)
	{
		write(1, str, 1);
		str++;
		(*pbp)++;
		prec--;
	}
}

void	put_fillers(char filler, int amount, int *pbp)
{
	while (amount != 0)
	{
		write(1, &filler, 1);
		amount--;
		(*pbp)++;
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
