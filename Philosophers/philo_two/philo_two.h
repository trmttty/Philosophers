/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:08:00 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/23 02:06:34 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "philo.h"

# define MICROSEC	0
# define MILLESEC	1

typedef struct			s_philo
{
	unsigned int		id;
	unsigned int		dead;
	uint64_t			last_meal_start;
	uint64_t			timestamp;
	char				*action;
}						t_philo;

/*
** init_philo.c
*/
int				check_args(int argc, char **argv);
void			init_state(int argc, char **argv, t_state *state);
int				init_philosopher(t_philo *philo, t_state *state);
void			set_start_time(t_state *state);
uint64_t		get_duration_time(t_state *state);
int				monitor(t_state *state);
int				launch(t_philo *philo, t_state *state, t_data *data);
void			display_finish_all_meals(t_state *state);


void			philo_take_forks(t_data *data);
void			philo_eat(t_data *data);
void			philo_sleep(t_data *data);
void			philo_think(t_data *data);
void			print_timestamp(t_data *data, char *action);
void			display_all_meals_ate(t_state *state);

#endif
