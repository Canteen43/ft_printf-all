/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legacy_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:00:09 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 14:08:11 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// It is unclear how to interpret negative precisions. This legacy function
//  followed the following manual, that states that negative precision is taken 
//  as if the precision wereomitted:
//   https://man7.org/linux/man-pages/man3/printf.3.html
// However, another manual states that if the precision is negative,
//  the precision is taken to be zero:
//   https://linux.die.net/man/3/printf
// And the clang compiler automatically warns if the precision is negative, so
//  that there is three differing ways. If anything, I would say the clang
//  compiler takes precedence.
int	get_prec(t_specs *p_specs, char **p_string)
{
	int	factor;

	p_specs->precision = 0;
	*p_string++;
	factor = 1;
	if (**p_string == '-')
	{
		factor = -1;
		*p_string++;
	}
	while (char_in_str(**p_string, "0123456789"))
	{
		if (lmt_check(p_specs->precision, **p_string) == -1)
			return (-1);
		p_specs->precision *= 10;
		p_specs->precision += (**p_string - '0') * factor;
		*p_string++;
	}
	return (0);
}
