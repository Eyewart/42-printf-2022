/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:20:16 by Hassan            #+#    #+#             */
/*   Updated: 2022/03/28 19:02:58 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *nb)
{
	write(1, &c, 1);
}

void	do_action(const char *c, va_list ap, int *nc)
{
	char *str;
	if (*(c + 1) == 'c' || *(c + 1) == '%')
	{
		*str = va_arg(ap, int);
		*nc = *nc + write(1, &str, 1);
	}
	else if (*c == 's')
		ft_putstr(va_arg(ap, char*), nc);
	else if (*(c + 1) == 'p')
		ft_hex(va_arg(ap, unsigned long), nc);
	else if (*(c + 1) == 'd' || *(c + 1) == 'i' || *(c + 1) == 'u')
		ft_putnbr(va_arg(ap, int), nc);
	else if (*(c + 1) == 'x')
		ft_hex_lower(va_arg(ap, unsigned), nc);
	else if (*(c + 1) == 'X')
		ft_hex(va_arg(ap, unsigned), nc);
}

int	ft_printf(const char *c, ...)
{
	int		nc;
	va_list	ap;
	
	nc = 0;
	va_start(ap, c);
	while (*c)
	{
		if (*c == '%')
		{
			do_action(c++, ap, &nc);
			c++;
		}
		else
			nc = nc + write(1, c++, 1);
	}
	va_end(ap);
	return (nc);
}

/*%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.*/
