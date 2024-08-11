/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:22:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/11 16:52:22 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_in_str(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	chars_in_str(char *cs, char *s)
{
	while (*cs)
	{
		if (char_in_str(*cs, s) == 1)
			return (1);
		cs++;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	void	*start;

	start = s;
	while (n-- > 0)
		*(unsigned char *)s++ = c;
	return (start);
}

int	lmt_check(int value, char next)
{
	if (value == 0)
		return (0);
	if (value > 0)
	{
		if (INT_MAX / value < 10)
			return (-1);
		if (INT_MAX / value > 10)
			return (0);
		if (INT_MAX / value == 10)
			if (INT_MAX % value < next - '0')
				return (-1);
	}
	if (value < 0)
	{
		if (INT_MIN / value < 10)
			return (-1);
		if (INT_MIN / value > 10)
			return (0);
		if (INT_MIN / value == 10)
			if (INT_MIN % value > next - '0')
				return (-1);
	}
	return (0);
}
