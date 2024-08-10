/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:21:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/08/10 17:29:08 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*str;
	int		nbr;

	str = "Hello, I am Karl!";
	nbr = ft_printf("This is my string: %30.5s|End!", str);
	printf("\n%d\n", nbr);
}
