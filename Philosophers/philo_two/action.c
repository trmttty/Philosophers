/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:13:25 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 13:43:19 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		philo_take_forks(t_philo *philo, t_state *state)
{
	sem_wait(philo->sem_forks);
	sem_wait(philo->sem_forks);
	sem_wait(philo->sem_display);
	display_manager(philo, state, EVENT_FORK);
	display_manager(philo, state, EVENT_FORK);
	sem_post(philo->sem_display);
}

void		philo_eat(t_philo *philo, t_state *state)
{
	sem_wait(philo->sem_display);
	display_manager(philo, state, EVENT_EAT);
	sem_post(philo->sem_display);
	philo->last_meal = get_duration_time(state);
	usleep(state->t_eat * 1000);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
}

void		philo_sleep(t_philo *philo, t_state *state)
{
	sem_wait(philo->sem_display);
	display_manager(philo, state, EVENT_SLEEP);
	sem_post(philo->sem_display);
	usleep(state->t_sleep * 1000);
}

void		philo_think(t_philo *philo, t_state *state)
{
	sem_wait(philo->sem_display);
	display_manager(philo, state, EVENT_THINK);
	sem_post(philo->sem_display);
}
