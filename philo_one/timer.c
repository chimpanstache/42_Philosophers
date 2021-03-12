/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:27:08 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/01 13:16:19 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	free_all(t_params *p)
{
	if (p->last_meal_time)
		free(p->last_meal_time);
	if (p->eated)
		free(p->eated);
	if (p->mutexphilo)
		free(p->mutexphilo);
	if (p->mutexindex)
		free(p->mutexindex);
	if (p->mutexindexcaner)
		free(p->mutexindexcaner);
	if (p->philo)
		free(p->philo);
	if (p->check_death)
		free(p->check_death);
	if (p->mutexoutput)
		free(p->mutexoutput);
}
