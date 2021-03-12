/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_message_eat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:41:56 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/12 18:56:25 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

char *g_message1 = "has taken a fork";
char *g_message2 = "is eating";
// char *g_message3 = "is sleeping\n";
// char *g_message4 = "is thinking\n";
// char *g_message5 = "died\n";
int g_ln1 = 17;
int g_ln2 = 10;
// int g_ln3 = 13;
// int g_ln4 = 13;
// int g_ln5 = 6;

void		*ft_memcpy_eat(void *dest, const void *src, size_t n)
{
	char *dest1;
	char *src1;

	dest1 = (char *)dest;
	src1 = (char *)src;
	while (n > 0)
	{
		if (*src1 != '\0')
			*dest1 = *src1;
		dest1++;
		src1++;
		n--;
	}
	return (dest);
}

int		set_message_eat(int phil, t_params *p, char *buff)
{
	int digit;

	if (p->died <= 0)
		return (1);
	digit = ft_itoa_custom((int)get_time() - p->start_time, buff);
	digit = digit + ft_itoa_custom(phil, &buff[digit + 1]);
	digit += 2;
	ft_memcpy_eat(&buff[digit], g_message1, g_ln1);	
	digit = 50;
	digit += ft_itoa_custom((int)get_time() - p->start_time, &buff[digit]);
	digit = digit + ft_itoa_custom(phil, &buff[digit + 1]);
	digit += 2;
	ft_memcpy_eat(&buff[digit], g_message1, g_ln1);	
	digit = 100;
	digit += ft_itoa_custom((int)get_time() - p->start_time, &buff[digit]);
	digit = digit + ft_itoa_custom(phil, &buff[digit + 1]);
	digit += 2;	
	ft_memcpy_eat(&buff[digit], g_message2, g_ln2);
	p->eated++;				
	return (0);
}

int		output_eat(t_params *p, int phil)
{
	char *buff = malloc(sizeof(buff)* 150);

	sem_wait(p->semoutput);
	memset(buff, 0, 150);
	memset(buff, ' ', 149);
	buff[49] = '\n';
	buff[99] = '\n';
	buff[148] = '\n';
	if (set_message_eat(phil, p, buff) == 1)
		return (1);		
	if (p->died <= 0)
		return (1);
	write(1, buff, ft_strlen(buff));
	sem_post(p->semoutput);
	return (0);
}

