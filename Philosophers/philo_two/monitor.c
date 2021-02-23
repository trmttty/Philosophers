/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/23 22:39:56 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			monitor(t_state *state)
{
	if (state->num_must_eat)
	{
		while (!state->thread_error && !state->philo_dead
				&& (state->num_finish_meal < state->num_philo))
			usleep(1000);
		if (state->thread_error)
			return (1);
		if (!state->philo_dead)
		{
			if (sem_wait(state->sem_display))
				return (error_status(SEMWAIT));
			display_finish_all_meals(state);
		}
	}
	else
	{
		while (!state->thread_error && !state->philo_dead)
			usleep(1000);
		if (state->thread_error)
			return (1);
	}
	return (0);
}
