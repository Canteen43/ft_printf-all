/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:20:36 by kweihman          #+#    #+#             */
/*   Updated: 2024/05/22 18:45:15 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	count_args(char *str)
{
	int	arg_cnt;

	arg_cnt = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
			arg_cnt++;
		str++;
	}
	return (arg_cnt);
}

void	mini_printf(char *str, ...)
{
	int			arg_cnt;
	va_list		args;

	arg_cnt = count_args(str);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			write(1, "!!", 2);
			str++;
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(args);
}
