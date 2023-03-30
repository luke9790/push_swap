/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:15:32 by lmasetti          #+#    #+#             */
/*   Updated: 2023/01/31 11:11:19 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*	
funzione atoi riapplicata alla struct
*/

int	ftatois(char *str, t_mem *mem)
{
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (str && ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		if ((sign == 1 && nbr > 2147483647) || (sign == -1 && nbr > 2147483648))
			exit_error(mem);
		str++;
	}
	return ((int)(nbr * sign));
}

int	ft_assoluto(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_maggiore(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_minore(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
