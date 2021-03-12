/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:11:32 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/12 14:20:43 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*check_deads(void *arg)
{
	t_params	*p;
	int			phil;
	int			i;

	p = (t_params*)arg;
	phil = p->phil;
	sem_post(p->semindexcaner);
	while (1)
	{
		if (p->notepme != 0)
			if (p->eated[phil] >= p->notepme)
				break ;
		if (get_time() - p->last_meal_time[phil] > p->ttdie)
		{
			output(p, 5, phil);
			p->died -= 1;
			i = -1;
			while (++i < p->nop)
				sem_post(p->semdie);
			return (NULL);
		}
		usleep(500);
	}
	sem_post(p->semdie);
	return (0);
}

int		unlink_semaphores(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_INDEX);
	sem_unlink(SEM_INDEXCANER);
	sem_unlink(SEM_OUTPUT);
	sem_unlink(SEM_DIE);
	return (0);
}

int		init_semaphores(t_params *p)
{
	p->semfork = sem_open(SEM_FORKS, O_CREAT, 0600, p->nop);
	p->semindex = sem_open(SEM_INDEX, O_CREAT, 0600, 1);
	p->semindexcaner = sem_open(SEM_INDEXCANER, O_CREAT, 0600, 1);
	p->semoutput = sem_open(SEM_OUTPUT, O_CREAT, 0600, 1);
	p->semdie = sem_open(SEM_DIE, O_CREAT, 0600, p->nop);
	return (0);
}

int		while_loops(t_params *p)
{
	int i;

	i = -1;
	while (++i < p->nop)
	{
		sem_wait(p->semindex);
		sem_wait(p->semindexcaner);
		p->phil = i;
		pthread_create(&p->check_death[i], NULL, check_deads, p);
		pthread_create(&p->philo[i], NULL, living, p);
	}
	i = -1;
	while (++i < p->nop)
		sem_wait(p->semdie);
	i = -1;
	while (++i < p->nop)
		sem_wait(p->semdie);
	return (0);
}

int		main(int argc, char **argv)
{
	t_params	*p;

	if (!(p = malloc(sizeof(t_params))))
		return (1);
	if (check_input(p, argv, argc) == 1)
		return (1);
	if (init_values(p) == 1)
		return (1);
	unlink_semaphores();
	init_semaphores(p);
	while_loops(p);
	unlink_semaphores();
	return (0);
}
