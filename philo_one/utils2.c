/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:42:07 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/12 14:36:57 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			ft_atoi(const char *str)
{
	long i;
	long nb;

	i = 0;
	nb = 0;
	while (*str == '\n' || *str == '\v' || *str == '\f' ||
			*str == '\r' || *str == '\t' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i++;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
		if (nb > LONG_MAX || nb < 0)
			return (i > 0) ? 0 : -1;
	}
	if (i % 2 != 0)
		nb = -nb;
	return (nb);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

static int	countdigit(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	nb = 0;
	if (n == 0)
		return (1);
	nb = (unsigned int)n;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int			ft_itoa_custom(int n, char *arr)
{
	int		sign;
	int		len;
	int		len2;

	sign = 0;
	len = countdigit(n);
	len2 = len;
	arr[len] = ' ';
	while (len-- > sign)
	{
		arr[len] = n % 10 + '0';
		n = n / 10;
	}
	return (len2);
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *dest1;
	char *src1;

	dest1 = (char *)dest;
	src1 = (char *)src;
	while (n > 0)
	{
		if (*dest1 != *src1)
			*dest1 = *src1;
		dest1++;
		src1++;
		n--;
	}
	return (dest);
}
