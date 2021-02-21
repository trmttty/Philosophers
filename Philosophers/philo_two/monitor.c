/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 03:09:20 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			kill_philosophers(t_state *state, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < state->n_philo)
	{

		if (pthread_detach(philo[i].thread))
			return (error_status(PDETACH));
		i++;
	}
	return (0);
}

int			monitor_philo_dead(t_state *state, t_philo *philo)
{
	while (!state->philo_dead)
		usleep(ONE_MILLISEC);
	if (state->philo_dead)
		kill_philosophers(state, philo);
	return (0);
}

int			monitor_eat_count(t_state *state, t_philo *philo)
{
	while (!state->philo_dead && (state->eat_count < state->n_philo))
		usleep(ONE_MILLISEC);
	if (state->philo_dead == 1 || (state->eat_count == state->n_philo))
		kill_philosophers(state, philo);
	if (!state->philo_dead && (state->eat_count == state->n_philo))
	{
		if (sem_wait(philo->sem_display))
			return (error_status(SEMWAIT));
		display_all_meals_ate(state);
	}
	return (0);
}

int			monitor(t_philo *philo, t_state *state)
{
	if (state->n_must_eat)
		return (monitor_eat_count(state, philo));
	return (monitor_philo_dead(state, philo));
}
