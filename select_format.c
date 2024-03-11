/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmindt <anmindt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:01:09 by anmindt           #+#    #+#             */
/*   Updated: 2024/03/11 14:19:25 by anmindt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_form(char str, int *count, va_list argptr)
{
	void	*ptr;

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
		ft_dectohex_up(va_arg(argptr, unsigned int), str, count);
	else if (str == 'p')
	{
		ptr = (va_arg(argptr, void *));
		if (ptr != NULL)
		{
			put_str("0x", count);
			ft_dectohex_up((unsigned long long) ptr, str, count);
		}
		else
			put_str("(nil)", count);
	}
}
