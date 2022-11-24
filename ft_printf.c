/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:41:29 by manujime          #+#    #+#             */
/*   Updated: 2022/11/23 16:59:17 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		write(1, &str[c], 1);
		c++;
	}
	return (c);
}

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'x' || format == 'X')
		len += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'p')
		len += ft_printptr(va_arg(args, void *));
	return (len);
}

int	ft_printf(char const *string, ...)
{
	va_list	args;
	int		len;
	int		c;

	c = 0;
	len = 0;
	va_start(args, string);
	while (string[c])
	{
		if (string[c] == '%')
		{
			len += ft_formats(args, string[c + 1]);
			c += 2;
		}
		if (string[c] != '%')
			len += ft_printchar(string[c]);
		c++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int		len;
	char	c;
	char	*string;
	int		nbr;
	int		ngbr;

	len = 0;
	c = 'Y';
	string = "Yes, strings are working 1234";
	nbr = 123456;
	ngbr = -123456;
	len = ft_printf("characers: %c \n", c);
	printf("%i \n", len);
	len = printf("characers: %c \n", c);
	printf("%i \n", len);
	len = ft_printf("strings: %s \n", string);
	printf("%i \n", len);
	len = printf("strings: %s \n", string);
	printf("%i \n", len);
	len = ft_printf("decimal and integrers: %i \n", nbr);
	printf("%i \n", len);
	len = printf("decimal and integrers: %i \n", nbr);
	printf("%i \n", len);
	len = ft_printf("decimal and integrers: %i \n", ngbr);
	printf("%i \n", len);
	len = printf("decimal and integrers: %i \n", ngbr);
	printf("%i \n", len);
	len = ft_printf("hex: %X \n", nbr);
	printf("%i \n", len);
	len = printf("hex: %X \n", nbr);
	printf("%i \n", len);
	len = ft_printf("pointer: %p \n", string);
	printf("%i \n", len);
	len = printf("pointer: %p \n", string);
	printf("%i \n", len);
}
