/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmindt <anmindt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:59:49 by anmindt           #+#    #+#             */
/*   Updated: 2024/03/08 19:27:47 by anmindt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//rekursive ft zum printen einer Ziffer inkl. count erhöhen
void	ft_print_nbr(int n, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
	}
	else if (n < 0)
	{
		print_c('-', count);
		n = -n;
		ft_print_nbr(n, count);
	}
	else if (n > 9)
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

//Länge des strings/Arrays ermitteln
int	ft_narrlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

//Array mit der Zahl als Hexadezimal-Version entsprechenden Größe erstellen
char	*ft_narr(unsigned int n)
{
	char	*arr;
	int		i;

	i = ft_narrlen(n);
	arr = (char *) malloc(i + 1);
	if (!arr)
		return (NULL);
	arr[i] = '\0';
	return (arr);
}

//write str in stio and free the allocated mem space of it afterwards
void	ft_print_and_free(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		(*count)++;
		i++;
	}
	free(str);
}

//Hexadezimal Konversion mit Rückgabe des entsprechenden Strings
//string mit hexadezimal-version wird erstelt

void	ft_dectohex_up(unsigned int n, char c, int *count)
{
	int		i;
	char	*arr;
	char	*u_hex;
	char	*l_hex;
	char	*hex;

	i = ft_narrlen(n);
	arr = ft_narr(n);
	u_hex = "0123456789ABCDEF";
	l_hex = "0123456789abcdef";
	if (c == 'X')
		hex = u_hex;
	else
		hex = l_hex;
	while (i > 0)
	{
		arr[i - 1] = hex[n % 16];
		n = n / 16;
		i--;
	}
	ft_print_and_free(arr, count);
}
