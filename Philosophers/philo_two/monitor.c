/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 14:03:19 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			delete_philosophers(t_state *state, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	(void)state;
	(void)philo;
	// while (i < state->n_philo)
	// {
	// 	if (pthread_detach(philo[i].thread))
	// 		return (error_status(PDETACH));
	// 	i++;
	// }
	return (0);
}

int			monitor(t_philo *philo, t_state *state)
{
	if (state->n_must_eat)
	{
		while (!state->philo_dead && (state->finish_meal_count < state->n_philo))
			usleep(1000);
		if (!state->philo_dead)
		{
			if (sem_wait(philo->sem_display))
				return (error_status(SEMWAIT));
			display_finish_all_meals(state);
		}
		if (delete_philosophers(state, philo))
			return (1);
	}
	else
	{
		while (!state->philo_dead)
			usleep(1000);
		if (delete_philosophers(state, philo))
			return (1);
	}
	return (0);
}
