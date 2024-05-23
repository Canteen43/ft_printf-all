/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:21:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/05/22 18:44:30 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mini_printf.c"

int	main(void)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = "Hello";
	ptr2 = "Girls";
	mini_printf("Variable 1: %c, two percents: %%, Variable 2: %d", 3, 4);
}
