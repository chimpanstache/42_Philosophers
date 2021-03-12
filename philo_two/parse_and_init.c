/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:06:36 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/01 13:41:37 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		check_time_to_eat(t_params *p, char **argv)
{
	p->notepme = 0;
	if (argv[5] != NULL)
	{
		p->notepme = ft_atoi(argv[5]);
		if (p->notepme < 1)
		{
			write(1, "wrong number of eating each times\n", 22);
			return (1);
		}
	}
	return (0);
}

int		check_input(t_params *p, char **argv, int argc)
{
	if (argc < 5 || argc > 6)
	{
		write(1, "wrong nb of args\n", 18);
		return (1);
	}
	p->nop = ft_atoi(argv[1]);
	if (p->nop < 2)
	{
		write(1, "wrong nb of Philosophers\n", 26);
		return (1);
	}
	p->ttdie = ft_atoi(argv[2]);
	p->tteat = ft_atoi(argv[3]);
	p->ttsleep = ft_atoi(argv[4]);
	if (p->ttdie < 1 || p->tteat < 1 || p->ttsleep < 1)
	{
		write(1, "wrong timing numbers\n", 22);
		return (1);
	}
	if (check_time_to_eat(p, argv) == 1)
		return (1);
	return (0);
}

int		malloc_values(t_params *p)
{
	if (!(p->eated = malloc(sizeof(int *) * p->nop)))
		return (1);
	if (!(p->last_meal_time = malloc(sizeof(long *) * p->nop)))
		return (1);
	if (!(p->philo = malloc(sizeof(pthread_t) * p->nop)))
		return (1);
	if (!(p->check_death = malloc(sizeof(pthread_t) * p->nop)))
		return (1);
	return (0);
}

int		init_values(t_params *p)
{
	int i;

	if (malloc_values(p) == 1)
		return (1);
	p->start_time = get_time();
	p->done_eating = 0;
	(p->died) = 1;
	i = -1;
	while (++i < p->nop)
		p->last_meal_time[i] = p->start_time;
	i = -1;
	while (++i < p->nop)
		p->eated[i] = 0;
	return (0);
}
