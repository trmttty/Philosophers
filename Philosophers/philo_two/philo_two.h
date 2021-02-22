/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:08:00 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/22 13:55:42 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "philo.h"
# include <semaphore.h>

# define MICROSEC	0
# define MILLESEC	1

typedef struct			s_philo
{
	pthread_t			thread;
	sem_t				*sem_forks;
	sem_t				*sem_display;
	unsigned int		id;
	unsigned int		is_dead;
	unsigned int		last_meal;
	int					live;
}						t_philo;

/*
** init_philo.c
*/
int				check_args(int argc, char **argv);
void			init_state(int argc, char **argv, t_state *state);
int				init_philosopher(t_philo *philo, t_state *state);
void			set_start_time(t_state *state);
uint64_t		get_duration_time(t_state *state);
int				monitor(t_philo *philo, t_state *state);
int				launch(t_philo *philo, t_state *state, t_data *data);
void			display_finish_all_meals(t_state *state);


void			philo_take_forks(t_philo *philo, t_state *state);
void			philo_eat(t_philo *philo, t_state *state);
void			philo_sleep(t_philo *philo, t_state *state);
void			philo_think(t_philo *philo, t_state *state);
void			display_manager(t_philo *philo, t_state *state, char *event);
void			display_all_meals_ate(t_state *state);

#endif
