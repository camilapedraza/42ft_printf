/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:17:20 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/19 19:47:04 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	/*ft_printf("Test single string:\n");
	ft_printf("Hi, my name is Camila!");
	printf("Hi, my name is Camila!");
	
	ft_printf("Test single character - A:\n");
	ft_printf("%c", 65);
	printf("%c", 65);

	ft_printf("Test min int:\n");
    ft_printf("With D: %d\n", -2147483647);
	ft_printf("With I: %i\n", -2147483647);
    printf("With D: %d\n", -2147483647);
    printf("With I: %i\n", -2147483647);

	ft_printf("Test unsigned int:\n");
    ft_printf("With U: %u\n", -2567);
    printf("With U: %u\n", -2567);
	
	ft_printf("Test with string specifier:\n");
    ft_printf("%s\n", "Hi, my name is Camila!");
    printf("%s\n", "Hi, my name is Camila!");
	
	ft_printf("Test with hex:\n");
    ft_printf("x %x\n", -5689);
	ft_printf("X %X\n", 86541);
	printf("x %x\n", -5689);
	printf("X %X\n", 86541);
	*/

	int *nbr;
	int n;

	n = 7817;
	nbr = &n;
	ft_printf("Test with ptr:\n");
    ft_printf("%p\n", nbr);
    printf("%p\n", nbr);
}
