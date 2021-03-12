/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:13:43 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/01 17:58:13 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_usleep(long start_time, long delay)
{
	usleep(delay * 0.8 * 1000);
	while (1)
	{
		if (get_time() - start_time >= delay)
			break ;
		usleep(500);
	}
}

int		get_fork(t_params *p, int phil)
{
	pthread_mutex_lock(&p->mutexphilo[phil]);
	if (phil != p->nop - 1)
	{
		if (pthread_mutex_lock(&p->mutexphilo[phil + 1]) != 0)
			return (1);
	}
	else
		pthread_mutex_lock(&p->mutexphilo[0]);
	if (output(p, 1, phil) == 1)
		return (1);
	if (output(p, 1, phil) == 1)
		return (1);
	p->last_meal_time[phil] = get_time();
	if (output(p, 2, phil) == 1)
		return (1);
	ft_usleep(get_time(), p->tteat);
	pthread_mutex_unlock(&p->mutexphilo[phil]);
	if (phil != p->nop - 1)
	{
		if (pthread_mutex_unlock(&p->mutexphilo[phil + 1]) != 0)
			return (1);
	}
	else
		pthread_mutex_unlock(&p->mutexphilo[0]);
	return (0);
}

void	*living(void *arg)
{
	t_params	*p;
	int			phil;

	p = (t_params*)arg;
	phil = p->phil;
	pthread_mutex_unlock(p->mutexindex);
	while (1)
	{
		if (get_fork(p, phil) == 1)
			break ;
		if (output(p, 3, phil) == 1)
			break ;
		ft_usleep(get_time(), p->ttsleep);
		if (output(p, 4, phil) == 1)
			break ;
	}
	return (NULL);
}
