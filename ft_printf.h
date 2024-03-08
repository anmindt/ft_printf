/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmindt <anmindt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:36:50 by anmindt           #+#    #+#             */
/*   Updated: 2024/03/08 19:20:25 by anmindt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

//core functions for initialising printing with specific format
int		ft_printf(const char *str, ...);
void	print_form(char str, int *count, va_list argptr);

//functions for converting and printing numbers
void	ft_print_nbr(int n, int *count);
void	ft_print_unum(unsigned int n, int *count);
int		ft_narrlen(unsigned int n);
char	*ft_narr(unsigned int n);
void	ft_print_and_free(char *str, int *count);
void	ft_dectohex_up(unsigned int n, char c, int *count);

//functions for printing chars and strings
void	print_c(char c, int *count);
void	put_str(char *str, int *count);

#endif
