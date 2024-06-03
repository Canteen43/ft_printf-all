/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:21:06 by kweihman          #+#    #+#             */
/*   Updated: 2024/05/31 13:47:56 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		nbr;
	char	*str;
	char	*ptr;

	*ptr = NULL;
	str = NULL;
	printf("Original printf:\n");
	nbr = printf("%p", ptr);
	printf("\n%d", nbr);
	printf("\nMy printf:\n");
	nbr = ft_printf("%p", ptr);
	printf("\n%d\n", nbr);
}
