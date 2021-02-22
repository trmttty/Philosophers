/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:27:31 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/22 17:19:21 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include "./libft/libft.h"

# define INVAL			"Error: Invalid argument"
# define NOMEM			"Error: Cannot allocate memory"
# define SEMOPEN		"Error: Cannot initialize and open a named semaphore"
# define SEMWAIT		"Error: Cannot lock a semaphore"
# define PCREATE		"Error: Cannot create a new thread"
# define PDETACH		"Error: Cannot detach a thread"
# define GETTIME		"Error: Cannot get date and time"

# define TRUE			1
# define FALSE			0

# define EVENT_FORK		"has taken a fork"
# define EVENT_EAT		"is eating"
# define EVENT_SLEEP	"is sleeping"
# define EVENT_THINK	"is thinking"
# define EVENT_DEAD		"is dead"

# define ONE_MILLISEC 	1000

typedef struct		s_state
{
	unsigned int	num_philo;
	uint64_t		time_die;
	uint64_t		time_eat;
	uint64_t		time_sleep;
	uint64_t		time_start_usec;
	uint64_t		time_start_sec;
	unsigned int	num_must_eat;
	unsigned int	num_finish_meal;
	unsigned int	philo_dead;
	sem_t			*sem_forks;
	sem_t			*sem_display;
}					t_state;

typedef	struct		s_data
{
	struct s_state	*state;
	struct s_philo	*philo;
}					t_data;

/*
** Function for all Philo
*/
int					parsing_manager(t_state *state);
int					data_manager(int ac, char **av, t_state *state);
int					check_argument(int ac, char **av, int *prog_arg);
int					error_status(char *message);
int64_t				ft_atoi64(const char *str);
uint64_t			ft_atou64(const char *str);

#endif
