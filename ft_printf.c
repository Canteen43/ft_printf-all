/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:40:48 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 12:43:46 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			bytes_printed;

	bytes_printed = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string != '%')
			print_character(&string, &bytes_printed);
		else if (handle_conversion(&string, args, &bytes_printed) == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (bytes_printed);
}

void	print_character(char **p_string, int *p_bytes_printed)
{
	write(1, *p_string, 1);
	*p_string++;
	*p_bytes_printed++;
}
