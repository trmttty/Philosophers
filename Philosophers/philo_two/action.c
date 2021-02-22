/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:13:25 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 17:08:27 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		philo_take_forks(t_philo *philo, t_state *state)
{
	sem_wait(state->sem_forks);
	sem_wait(state->sem_forks);
	sem_wait(state->sem_display);
	display_manager(philo, state, EVENT_FORK);
	display_manager(philo, state, EVENT_FORK);
	sem_post(state->sem_display);
}

void		philo_eat(t_philo *philo, t_state *state)
{
	uint64_t	current_time;

	current_time = get_duration_time(state);
	philo->last_meal_start = current_time;
	sem_wait(state->sem_display);
	display_manager(philo, state, EVENT_EAT);
	sem_post(state->sem_display);
	usleep(state->time_eat * 1000);
	sem_post(state->sem_forks);
	sem_post(state->sem_forks);
}

void		philo_sleep(t_philo *philo, t_state *state)
{
	sem_wait(state->sem_display);
	display_manager(philo, state, EVENT_SLEEP);
	sem_post(state->sem_display);
	usleep(state->time_sleep * 1000);
}

void		philo_think(t_philo *philo, t_state *state)
{
	sem_wait(state->sem_display);
	display_manager(philo, state, EVENT_THINK);
	sem_post(state->sem_display);
}
