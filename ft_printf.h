/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:41:06 by manujime          #+#    #+#             */
/*   Updated: 2022/11/24 12:42:21 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h> //delete after testing

int		ft_printf(const char *string, ...);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int nbr);
int		ft_printptr(void *ptr);
int		ft_printhex(unsigned long nbr, char f);

#endif