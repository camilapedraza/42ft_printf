/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:47:00 by mpedraza          #+#    #+#             */
/*   Updated: 2025/11/19 17:55:18 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_char(char ch, int count)
{
	write(1, &ch, 1);
		count++;
	return (count);
}

int	print_string(char *str, int count)
{
	while (*str)
		count = print_char(*(str++), count);
	return (count);
}

int	print_number(int n, int count)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		count = print_char('-', count);
		nb = -nb;
	}
	if (nb > 9)
	{
		count = print_number((nb / 10), count);
		count = print_char((nb % 10 + 48), count);
	}
	if (nb < 10)
		count = print_char((nb + 48), count);
	return (count);
}

int	print_unsigned(int n, int count)
{
	unsigned int	nb;

	nb = (unsigned int)n;
	if (nb > 9)
		count = print_unsigned((nb / 10), count);
	count = print_char((nb % 10 + 48), count);
	return (count);
}

int	print_hex(int n, char f, int count)
{
	unsigned int	nb;
	char			base;

	base = 'a';
	if (f == 'X')
		base = 'A';
	nb = (unsigned int)n;
	if (nb > 15)
	{
		count = print_hex((nb / 16), f, count);
		count = print_hex((nb % 16), f, count);
	}
	else
	{
		if (nb < 10)
			count = print_char((nb + '0'), count);
		else
			count = print_char((nb - 10 + base), count);
	}
	return (count);
}

int	print_ptr(int n, int count)
{
	unsigned long	nb;

	nb = (unsigned long)n;
	if (nb > 15)
	{
		count = print_ptr((nb / 16), count);
		count = print_ptr((nb % 16), count);
	}
	else
	{
		if (nb < 10)
			count = print_char((nb + '0'), count);
		else
			count = print_char((nb - 10 + 'a'), count);
	}
	return (count);
}

static int	parse_spec(char spec, int count, va_list args)
{
	if (spec == '%')
		count = print_char('%', count);
	else if (spec == 'c')
		count = print_char(va_arg(args, int), count);
	else if (spec == 's')
		count = print_string(va_arg(args, char *), count);
	else if (spec == 'd' || spec == 'i')
		count = print_number(va_arg(args, int), count);
	else if (spec == 'u')
		count = print_unsigned(va_arg(args, int), count);
	else if (spec == 'x' || spec == 'X')
		count = print_hex(va_arg(args, int), spec, count);
	else if (spec == 'p')
		count = print_ptr((unsigned long)va_arg(args, void *), count);
	else
		count = print_char(spec, count);
	return (count);
}

static int	parse_str(va_list args, char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[i++])
	{
		if (str[i] != '%')
			count = print_char(str[i], count);
		else
			count = parse_spec(str[++i], count, args);
	}
	return (count);
}

int	ft_printf(const char *f, ...)
{
	int		count;
	char	*str;
	va_list	args;

	if (!f || !*f)
		return (0);
	str = ft_strdup(f);
	if (!str)
		return (0);
	va_start(args, f);
	count = parse_str(args, str);
	va_end(args);
	free(str);
	return (count);
}
