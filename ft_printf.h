/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:36:03 by Hassan            #+#    #+#             */
/*   Updated: 2022/03/28 18:52:55 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *c, ...);
void	do_action(const char *c, va_list ap, int *nc);
void	ft_putchar(char c, int *nb);
void	ft_putstr(char *str, int *nb);
void	ft_putnbr(int n, int *nb);
void	ft_hex(unsigned long n, int *nb);
void	ft_hex_lower(unsigned int n, int *nb);

#endif