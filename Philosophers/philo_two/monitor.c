/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 00:45:16 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		kill_philosophers(t_state *state, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < state->n_philo)
		pthread_detach(philo[i++].thread);
}

void		monitor_die(t_state *state, t_philo *philo)
{
	while (!state->philo_dead)
		usleep(ONE_MILLISEC);
	if (state->philo_dead)
		kill_philosophers(state, philo);
}

void		monitor_meals(t_state *state, t_philo *philo)
{
	while (!state->philo_dead && (state->eat_count < state->n_philo))
		usleep(ONE_MILLISEC);
	if (state->philo_dead == 1 || (state->eat_count == state->n_philo))
		kill_philosophers(state, philo);
	if (!state->philo_dead && (state->eat_count == state->n_philo))
	{
		sem_wait(philo->sem_display);
		display_all_meals_ate(state);
	}
}

void		monitor(t_state *state, t_philo *philo)
{
	if (state->meals)
		monitor_meals(state, philo);
	else
		monitor_die(state, philo);
}
