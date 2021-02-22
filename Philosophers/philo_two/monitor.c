/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 17:21:59 by ttarumot         ###   ########.fr       */
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

int			monitor(t_state *state)
{
	if (state->num_must_eat)
	{
		while (!state->philo_dead && (state->num_finish_meal< state->num_philo))
			usleep(1000);
		if (!state->philo_dead)
		{
			if (sem_wait(state->sem_display))
				return (error_status(SEMWAIT));
			display_finish_all_meals(state);
		}
	}
	else
	{
		while (!state->philo_dead)
			usleep(1000);
	}
	return (0);
}
