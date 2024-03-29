/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmindt <anmindt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:01:50 by anmindt           #+#    #+#             */
/*   Updated: 2024/03/05 21:11:56 by anmindt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//einfache print ft für chars, die ad on zum count zurück gibt
//alternativ geht auch *count += 1
void	print_c(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

//ft zum printen eines strings inkl. count erhöhen
void	put_str(char *str, int *count)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		print_c(*str, count);
		str++;
	}
}
