/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmindt <anmindt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:42:21 by anmindt           #+#    #+#             */
/*   Updated: 2024/03/05 20:49:46 by anmindt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unum(unsigned int n, int *count)
{
	char	c;

	if (n > 9)
	{
		ft_print_nbr(n / 10, count);
		ft_print_nbr(n % 10, count);
	}
	else
	{
		c = n + 48;
		print_c(c, count);
	}
}

