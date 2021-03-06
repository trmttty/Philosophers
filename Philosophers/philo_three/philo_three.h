/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:08:00 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/20 13:26:56 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "philo.h"
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>

# define MICROSEC	0
# define MILLESEC	1

typedef struct				s_philo
{
	pid_t				pid;
	sem_t				*sem_forks;
	sem_t				*sem_display;
	unsigned int		id;
	unsigned int		is_dead;
	unsigned int		last_meal;
	t_bool				life;
}							t_philo;

/*
** init_philo.c
*/
int				check_args(int ac, char **av);
void			init_data(int argc, char **argv, t_data *data);
int				init_philosopher(t_philo *philo, unsigned int n_philo);
void			get_time_start(t_data *data);
unsigned int	get_time(unsigned int start_usec, unsigned int start_sec);
void			monitor(t_data *data, t_philo *philo);
int				launch(t_stock *stock, t_data *data, t_philo *philo);
void			free_philosophers(t_data *data, t_philo *philo);
void			display_all_meals_ate(t_data *data);
void			display_manager(t_stock *s, t_philo *philo, char *event);






void						philo_take_fork(t_stock *stock, t_philo *philo);
void						philo_eat(t_stock *stock, t_philo *philo);
void						philo_sleep(t_stock *stock, t_philo *philo);
void						philo_think(t_stock *stock, t_philo *philo);
void						display_manager(t_stock *stock, t_philo *philo,
							char *event);
void						*reaper(void *stock);
void						monitor(t_data *data, t_philo *philo);
void						display_all_meals_ate(t_data *data);
void						display_manager(t_stock *s, t_philo *philo,
							char *event);

#endif
