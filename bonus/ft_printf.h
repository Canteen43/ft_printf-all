/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:33:01 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/11 16:23:54 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>	// write()
# include <stdarg.h>	// va_start, va_arg, va_copy, va_end
# include <limits.h>	// INT_MAX, INT_MIN

// Variables and their meaning:
//  os	- original string. The constant string that is passed as 1st arg.
//	p	- prefix for any variable that is a pointer to something.
//	bp	- bytes printed. The return of the function.
//	sp	- specifications. A struct that contains fl, width and pr.
//	fw	- field width.
//	pr	- precision.
//	fl	- flags, meaning "#+0- ".

typedef struct s_conversion_specifications
{
	char	fl[6];
	int		fw;
	int		pr;
}	t_sp;

int		ft_convert_s(char *str, int *pbp, t_sp *psp);
void	write_str(char *str, int *pbp, int prec);
void	put_fillers(char filler, int amount, int *pbp);
int		set_length(char *str, int prec);
int		char_in_str(char c, char *s);
int		chars_in_str(char *cs, char *s);
void	*ft_memset(void *s, int c, size_t n);
int		lmt_check(int value, char next);
int		min(int a, int b);
int		max(int a, int b);
int		handle_conversion(const char **pos, va_list args, int *pbp);
int		convert(const char **pos, va_list args, int *pbp, t_sp *psp);
int		put_percent(int *pbp, const char **pos);
int		get_sp(t_sp *psp, const char **pos);
int		get_fl(t_sp *psp, const char **pos);
int		get_width(t_sp *psp, const char **pos);
int		get_prec(t_sp *psp, const char **pos);
void	add_char_to_fl(char a, t_sp *psp);
int		ft_printf(const char *string, ...);
void	print_character(const char **pos, int *pbp);

#endif // FT_PRINTF_H