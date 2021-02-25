/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:08:00 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/25 22:10:23 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <limits.h>
# include "./libft/libft.h"

# define TRUE					1
# define FALSE					0

# define EXIT_PHILO_DEAD		10
# define EXIT_FINISH_MEALS		11

# define INVAL			"Error: Invalid argument"
# define NOMEM			"Error: Cannot allocate memory"
# define SEMOPEN		"Error: Cannot initialize and open a named semaphore"
# define SEMWAIT		"Error: Cannot lock a semaphore"
# define PCREATE		"Error: Cannot create a new thread"
# define PDETACH		"Error: Cannot detach a thread"
# define FORK			"Error: Create a new process"

# define EVENT_FORK		"has taken a fork"
# define EVENT_EAT		"is eating"
# define EVENT_SLEEP	"is sleeping"
# define EVENT_THINK	"is thinking"
# define EVENT_DEAD		"is dead"

typedef struct		s_philo
{
	pid_t			pid;
	int				id;
	int				dead;
	uint64_t		last_meal_start;
	uint64_t		timestamp;
	char			*action;
}					t_philo;

typedef struct		s_state
{
	uint64_t		num_philo;
	uint64_t		time_die;
	uint64_t		time_eat;
	uint64_t		time_sleep;
	uint64_t		time_start_usec;
	uint64_t		time_start_sec;
	uint64_t		num_must_eat;
	uint64_t		num_finish_meal;
	int				philo_dead;
	int				thread_error;
	sem_t			*sem_forks;
	sem_t			*sem_display;
	sem_t			*sem_finish_meals;
}					t_state;

typedef	struct		s_data
{
	struct s_state	*state;
	struct s_philo	*philo;
}					t_data;

/*
** action.c
*/
void				philo_take_forks(t_data *data);
void				philo_eat(t_data *data);
void				philo_sleep(t_data *data);
void				philo_think(t_data *data);

/*
** display.c
*/
void				print_timestamp(t_data *data, uint64_t stamp, char *action);
void				display_finish_all_meals(t_state *state);

/*
** exit.c
*/
int					error_status(char *message);
void				error_exit(t_state *state, char *message);
void				exit_status(char *message);

/*
** init.c
*/
void				init_state(int argc, char **argv, t_state *state);
void				init_philosopher(t_philo *philo, t_state *state);

/*
** launch.c
*/
void				launch(t_philo *philo, t_state *state, t_data *data);

/*
** monitor.c
*/
void				monitor(t_philo *philo, t_state *state, t_data *data);
void				delete_philosophers(t_philo *philo, t_state *state);

/*
** time.c
*/
void				set_start_time(t_state *state);
uint64_t			get_duration_time(t_state *state);

/*
** utils.c
*/
int					check_args(int argc, char **argv);
int					is_uint(const char *str);
int64_t				ft_atoi64(const char *str);
uint64_t			ft_atou64(const char *str);

#endif
