/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzheng <rzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:05:55 by rzheng            #+#    #+#             */
/*   Updated: 2024/10/24 14:51:53 by rzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr);
static char	*pre_conv(int len);
static void	fill_number(char *result, long nbr, int len);

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	int		len;

	nbr = n;
	len = int_len(nbr);
	result = pre_conv(len);
	if (!result)
		return (NULL);
	if (nbr == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	fill_number(result, nbr, len);
	result[len] = '\0';
	return (result);
}

static void	fill_number(char *result, long nbr, int len)
{
	int	i;

	i = len - 1;
	while (nbr > 0)
	{
		result[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
}

static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	return (tmp);
}

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
