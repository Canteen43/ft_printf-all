/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:21:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/11 15:47:28 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*str;
	int		nbr;

	str = "Hello, I am Karl!";
	str = NULL;
	nbr = ft_printf("This is my string: %30.6s|End!", str);
	printf("\nThis should be 24 plus the length of the string: %d\n", nbr);
}
