/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:57:46 by ehafidi           #+#    #+#             */
/*   Updated: 2021/02/28 20:40:11 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	check_time_to_eat(t_params *p, char **argv)
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

int	check_input(t_params *p, char **argv, int argc)
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

int	malloc_values(t_params *p)
{
	if (!(p->c = (pid_t *)malloc(sizeof(pid_t *) * p->nop)))
		return (1);
	return (0);
}

int	init_values(t_params *p)
{
	int i;

	if (malloc_values(p) == 1)
		return (1);
	p->died = 1;
	p->done_eating = 0;
	i = -1;
	while (++i < p->nop)
		p->eated = 0;
	return (0);
}
