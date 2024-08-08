/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:33:01 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/08 11:22:36 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>	// write()
# include <stdarg.h>	// va_start, va_arg, va_copy, va_end

typedef struct s_conversion_specifications
{
	char	*flags[6];
	int		field_width;
	int		precision;
}	t_specs;

int	ft_printf(const char *str, ...);
int	ft_convert_c(int c);
int	ft_convert_d(int n);
int	ft_convert_i(int n);
int	ft_convert_p(void *ptr);
int	ft_convert_percent(void);
int	ft_convert_s(char *str);
int	ft_convert_u(unsigned int n);
int	ft_convert_x_cap(unsigned int n);
int	ft_convert_x(unsigned int n);

#endif // FT_PRINTF_H