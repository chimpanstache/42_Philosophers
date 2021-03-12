/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_message2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:41:56 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/12 18:33:30 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

// char *g_message1 = "has taken a fork\n";
// char *g_message2 = "is eating\n";
char *g_message3 = "is sleeping\n";
char *g_message4 = "is thinking\n";
char *g_message5 = "died\n";
// int g_ln1 = 18;
// int g_ln2 = 11;
int g_ln3 = 13;
int g_ln4 = 13;
int g_ln5 = 6;

int		set_message(int index, int phil, t_params *p, char *buff)
{
	int digit;

	if (p->died <= 0)
		return (1);
	digit = ft_itoa_custom((int)get_time() - p->start_time, buff);
	digit = digit + ft_itoa_custom(phil, &buff[digit + 1]);
	digit += 2;
	if (index == 5)
		ft_memcpy(&buff[digit], g_message5, g_ln5);
	else if (index == 3)
		ft_memcpy(&buff[digit], g_message3, g_ln3);
	else if (index == 4)
		ft_memcpy(&buff[digit], g_message4, g_ln4);
	// else if (index == 2)
	// {
	// 	p->eated++;
	// 	ft_memcpy(&buff[digit], g_message2, g_ln2);
	// }

	// else if (index == 1)
	// 	ft_memcpy(&buff[digit], g_message1, g_ln1);
	return (0);
}

int		output(t_params *p, int index, int phil)
{
	char buff[50];

	sem_wait(p->semoutput);
	memset(buff, 0, 50);
	memset(buff, ' ', 49);
	if (set_message(index, phil, p, buff) == 1)
		return (1);
	if (p->died <= 0)
		return (1);
	write(1, buff, ft_strlen(buff));
	if (index == 5)
		return (1);
	sem_post(p->semoutput);
	return (0);
}

