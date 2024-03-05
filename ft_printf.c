/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Second draft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmindt <anmindt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:29:25 by anmindt           #+#    #+#             */
/*   Updated: 2024/02/06 13:29:25 by anmindt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	argptr;

	if (!str)
		return (-1);
	count = 0;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print_form(*str, &count, argptr);
			str++;
		}
		if (*str == '\0')
			break ;
		if (*str == '%')
			continue ;
		print_c(*str, &count);
		str++;
	}
	va_end(argptr);
	return (count);
}

/* int main() {
	ft_printf(" %%%% ");
	//printf("%c", '0');
	// ft_printf("%d\n", n1);
	// ft_printf("%d\n", n2);
	// printf("%x %X hi %cll %s %u %u %p\n", 10, 26, 'a', "dort", 1, 2, str);

  return 0;
} */
