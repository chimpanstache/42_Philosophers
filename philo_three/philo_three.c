/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:13:43 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/12 18:54:49 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	sem_wait(p->semfork);
	sem_wait(p->semfork);
	// if (output(p, 1, phil) == 1)
	// 	return (1);
	// if (output(p, 1, phil) == 1)
	// 	return (1);
	if (output_eat(p, phil) == 1)
		return (1);	
	p->last_meal_time = get_time();
	// if (output(p, 2, phil) == 1)
	// 	return (1);
	ft_usleep(get_time(), p->tteat);
	sem_post(p->semfork);
	sem_post(p->semfork);
	return (0);
}

int		living(t_params *p)
{
	pthread_t	check_death;
	int			phil;

	phil = p->phil;
	sem_wait(p->semindex);
	p->start_time = get_time();
	p->last_meal_time = p->start_time;
	pthread_create(&check_death, NULL, check_deads, p);
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
	return (0);
}
