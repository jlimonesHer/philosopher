/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:13:04 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/16 11:58:55 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief cuenta los cararcters de una string
 * 
 * @param s string a contar
 * @return size_t tamaño de la string
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * @brief compara n caracteres de dos string
 * 
 * @param s1 string 1
 * @param s2 string 2
 * @param n numero de caracteres a comparar
 * @return int difererncia en el caracter encontrado
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && s1[i] && s2[i]
		&& (*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i)))
		i++;
	if ((i >= n) || (!s1[i] && !s2[i]))
		return (0);
	else
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}

/**
 * @brief copia una string y devuelve la copia
 * 
 * @param s string a copiar
 * @return char* copia de la string pasada por parametro
 */
char	*ft_strdup(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief convierte una string en un numero entero
 * 
 * @param array string a convertir
 * @return int el numero convertido en numero
 */
int	ft_atoi(char *array)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((array[i] > 8 && array[i] < 14) || array[i] == 32)
		i++;
	if (array[i] == '-' || array[i] == '+')
	{
		if (array[i] == '-')
			sign = -1;
		i++;
	}
	while (array[i] != '\0')
	{
		if (array[i] >= '0' && array[i] <= '9')
			result = result * 10 + (array[i] - '0');
		else
			return (result * sign);
		i++;
	}
	return (result * sign);
}

/**
 * @brief comprueba que el argumento sea valido, libera la memoria reservada
 * 
 * @param atoi_nbr string a comprobar
 * @return int numero parseado
 */
int	cmp_atoi(char *atoi_nbr)
{
	int		number;
	char	*str_number;

	number = ft_atoi(atoi_nbr);
	str_number = ft_itoa(number);
	while (atoi_nbr[0] == '+')
		atoi_nbr++;
	if (ft_strncmp(atoi_nbr, str_number, ft_strlen(atoi_nbr)) != 0)
	{
		free(str_number);
		return (-1);
	}
	free(str_number);
	return (number);
}
