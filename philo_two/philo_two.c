/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:13:43 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/01 11:34:18 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	if (output(p, 1, phil) == 1)
		return (1);
	if (output(p, 1, phil) == 1)
		return (1);
	p->last_meal_time[phil] = get_time();
	if (output(p, 2, phil) == 1)
		return (1);
	ft_usleep(get_time(), p->tteat);
	sem_post(p->semfork);
	sem_post(p->semfork);
	return (0);
}

void	*living(void *arg)
{
	t_params	*p;
	int			phil;

	p = (t_params*)arg;
	phil = p->phil;
	sem_post(p->semindex);
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
