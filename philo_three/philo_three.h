/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:14:19 by ehafidi           #+#    #+#             */
/*   Updated: 2021/03/12 18:54:40 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# define BEGIN 0
# define SLEEP 1
# define THINK 2

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <limits.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

# define SEM_FORKS "forks"
# define SEM_INDEX "semindex"
# define SEM_INDEXCANER "semindexcaner"
# define SEM_OUTPUT "semoutput"
# define SEM_DIE "semdie"
# define SEM_EAT "semeat"

typedef struct	s_params
{
	int			done_eating;
	int			died;
	int			eated;
	int			phil;
	int			nop;
	int			ttdie;
	int			tteat;
	int			ttsleep;
	int			notepme;
	long		start_time;
	long		last_meal_time;
	sem_t		*semfork;
	pid_t		*c;
	sem_t		*semindex;
	sem_t		*semindexcaner;
	sem_t		*semoutput;
	sem_t		*semdie;
	pthread_t	check_death;
}				t_params;

typedef struct	s_output
{
	char *to_join;
	char *timestamp;
	char *philo;
	char *output;
	char *output2;
}				t_output;

int				ft_atoi(const char *nptr);
long			get_time(void);
int				output(t_params *p, int index, int phil);
int				living(t_params *p);
void			*caner(t_params *p, int phil);
void			free_all(t_params *p);
void			*check_deads(void *arg);
int				check_input(t_params *p, char **argv, int argc);
int				init_values(t_params *p);
size_t			ft_strlen(const char *str);
int				ft_itoa_custom(int n, char *arr);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				output_eat(t_params *p, int phil);
void			*ft_memcpy_eat(void *dest, const void *src, size_t n);

#endif
