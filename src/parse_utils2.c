/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:28:02 by jlimones          #+#    #+#             */
/*   Updated: 2023/03/14 16:59:23 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_count_n(long long n)
{
	int	i;

	if (n < 0)
		n = n * -1;
	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_pos(int n2)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n2 + 1);
	if (!str)
		return (NULL);
	str[n2] = '\0';
	return (str);
}

static char	*ft_neg(int n2)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n2 + 2);
	if (!str)
		return (NULL);
	str[n2 + 1] = '\0';
		str[0] = '-';
	return (str);
}

/**
 * @brief replica la funcionalidad de la funcion itoa, convierte un 
 * entero a string.
 * 
 * @param n entero a convertir.
 * @return char* puntero a string
 */
char	*ft_itoa(int n)
{
	int				n2;
	long long		nlong;
	char			*str;

	nlong = (long long)n;
	n2 = ft_count_n(n);
	if (nlong < 0)
		str = ft_neg(n2);
	else
		str = ft_pos(n2);
	if (!str)
		return (NULL);
	while (0 < n2)
	{
		if (nlong < 0)
		{
			str[n2--] = ((nlong * -1) % 10) + 48;
		}
		else
			str[--n2] = (nlong % 10) + 48;
		nlong = nlong / 10;
	}
	return (str);
}