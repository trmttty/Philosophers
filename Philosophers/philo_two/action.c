/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:13:25 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 00:38:09 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		philo_take_fork(t_data *data, t_philo *philo)
{
	sem_wait(philo->sem_forks);
	sem_wait(philo->sem_forks);
	sem_wait(philo->sem_display);
	display_manager(data, philo, EVENT_FORK);
	display_manager(data, philo, EVENT_FORK);
	sem_post(philo->sem_display);
}

void		philo_eat(t_data *s, t_philo *philo)
{
	sem_wait(philo->sem_display);
	display_manager(s, philo, EVENT_EAT);
	sem_post(philo->sem_display);
	philo->last_meal = get_time(s->state->t_start_usec, s->state->t_start_sec);
	usleep(s->state->t_eat * ONE_MILLISEC);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
}

void		philo_sleep(t_data *data, t_philo *philo)
{
	sem_wait(philo->sem_display);
	display_manager(data, philo, EVENT_SLEEP);
	sem_post(philo->sem_display);
	usleep(data->state->t_sleep * ONE_MILLISEC);
}

void		philo_think(t_data *data, t_philo *philo)
{
	sem_wait(philo->sem_display);
	display_manager(data, philo, EVENT_THINK);
	sem_post(philo->sem_display);
}
