/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:11:32 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/12 14:14:56 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*check_deads(void *arg)
{
	t_params	*p;
	int			phil;

	p = (t_params*)arg;
	phil = p->phil;
	pthread_mutex_unlock(p->mutexindexcaner);
	while (1)
	{
		if (p->notepme != 0)
			if (p->eated[phil] >= p->notepme)
				break ;
		if (get_time() - p->last_meal_time[phil] > p->ttdie)
		{
			output(p, 5, phil);
			p->died -= 1;
			pthread_mutex_unlock(p->mutexdie);
			return (NULL);
		}
		usleep(500);
	}
	p->done_eating++;
	if (p->done_eating == p->nop)
		pthread_mutex_unlock(p->mutexdie);
	return (0);
}

int		init_mutexes(t_params *p)
{
	int i;

	i = -1;
	while (++i < p->nop)
		pthread_mutex_init(&p->mutexphilo[i], NULL);
	pthread_mutex_init(p->mutexindex, NULL);
	pthread_mutex_init(p->mutexoutput, NULL);
	pthread_mutex_init(p->mutexindexcaner, NULL);
	pthread_mutex_init(p->mutexdie, NULL);
	pthread_mutex_lock(p->mutexdie);
	return (0);
}

int		destroy_mutexes(t_params *p)
{
	int i;

	i = -1;
	while (++i < p->nop)
		if (pthread_mutex_destroy(&p->mutexphilo[i]) != 0)
			return (1);
	if (pthread_mutex_destroy(p->mutexindex) != 0)
		return (1);
	if (pthread_mutex_destroy(p->mutexoutput) != 0)
		return (1);
	if (pthread_mutex_destroy(p->mutexindexcaner) != 0)
		return (1);
	if (pthread_mutex_destroy(p->mutexdie) != 0)
		return (1);
	if (pthread_mutex_destroy(p->mutexdie) != 0)
		return (1);
	return (0);
}

int		thread_loop(t_params *p)
{
	int i;

	i = -1;
	while (++i < p->nop)
	{
		if (pthread_mutex_lock(p->mutexindex) != 0)
			return (1);
		if (pthread_mutex_lock(p->mutexindexcaner) != 0)
			return (1);
		p->phil = i;
		if (pthread_create(&p->check_death[i], NULL, check_deads, p) != 0)
			return (1);
		if (pthread_create(&p->philo[i], NULL, living, p) != 0)
			return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_params *p;

	if (!(p = malloc(sizeof(t_params))))
		return (1);
	if (check_input(p, argv, argc) == 1)
		return (1);
	if (init_values(p) == 1)
	{
		free_all(p);
		return (1);
	}
	init_mutexes(p);
	if (thread_loop(p) == 1)
		return (1);
	if (pthread_mutex_lock(p->mutexdie) != 0)
		return (1);
	if (destroy_mutexes(p) == 1)
		return (1);
	free_all(p);
	return (0);
}
