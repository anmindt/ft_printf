/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmindt <anmindt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:01:09 by anmindt           #+#    #+#             */
/*   Updated: 2024/03/05 20:47:12 by anmindt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_form(char str, int *count, va_list argptr)
{
	if (str == '%')
		print_c(str, count);
	else if (str == 'c')
		print_c(va_arg(argptr, int), count);
	else if (str == 's')
		put_str(va_arg(argptr, char *), count);
	else if (str == 'i' || str == 'd')
		ft_print_nbr(va_arg(argptr, int), count);
	else if (str == 'u')
		ft_print_unum(va_arg(argptr, unsigned int), count);
	else if (str == 'x' || str == 'X')
		ft_dectohex_up(va_arg(argptr, unsigned long long), str, count);
	else if (str == 'p')
	{
		write(1, "0x", 2);
		(*count) += 2;
		ft_dectohex_up((unsigned long long)
			va_arg(argptr, void *), str, count);
	}
}
