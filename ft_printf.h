/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:48:12 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/26 17:34:56 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int	ft_printf(const char *f, ...);
int	print_chr(char ch, int count);
int	print_hex(int n, char f, int count);
int	print_nbr(int n, int count);
int	print_ptr(uintptr_t nb, int count);
int	print_str(char *str, int count);
int	print_uns(unsigned int n, int count);

#endif
