/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:22:08 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/08 11:25:34 by kweihman         ###   ########.fr       */
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

void	*ft_memset(void *s, int c, size_t n)
{
	void	*start;

	start = s;
	while (n-- > 0)
		*(unsigned char *)s++ = c;
	return (start);
}
