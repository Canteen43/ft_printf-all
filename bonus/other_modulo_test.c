/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:22:38 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 12:25:27 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	div_and_mod(int a, int b)
{
	printf("%d divided by %d equals %d.\n", a, b, a / b);
	printf("%d modulo %d equals %d.\n\n", a, b, a % b);
}

int	main(void)
{
	div_and_mod(7, 3);
	div_and_mod(-7, 3);
	div_and_mod(7, -3);
	div_and_mod(-7, -3);
	return (0);
}
