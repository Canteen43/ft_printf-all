/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:33:01 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 17:41:29 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>	// write()
# include <stdarg.h>	// va_start, va_arg, va_copy, va_end
# include <limits.h>	// INT_MAX, INT_MIN

typedef struct s_conversion_specifications
{
	char	flags[6];
	int		field_width;
	int		precision;
}	t_specs;

int		ft_convert_s(char *str, int *pbp, t_specs *psp);
void	write_str(char *str, int *pbp, int prec);
void	put_fillers(char filler, int amount, int *pbp);
int		set_length(char *str, int prec);
int		char_in_str(char c, char *s);
int		chars_in_str(char *cs, char *s);
void	*ft_memset(void *s, int c, size_t n);
int		lmt_check(int value, char next);
int		min(int a, int b);
int		max(int a, int b);
int		handle_conversion(char **p_string, va_list args, int *pbp);
int		convert(char **p_string, va_list args, int *pbp, t_specs *p_specs);
int		put_percent(int *pbp, char **p_string);
int		get_specs(t_specs *p_specs, char **p_string);
int		get_flags(t_specs *p_specs, char **p_string);
int		get_width(t_specs *p_specs, char **p_string);
int		get_prec(t_specs *p_specs, char **p_string);
void	add_char_to_flags(char a, t_specs *p_specs);
int		ft_printf(const char *string, ...);
void	print_character(char **p_string, int *p_bytes_printed);

#endif // FT_PRINTF_H