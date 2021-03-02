/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/03/02 10:10:17 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		monitor(t_state *state)
{
	if (state->num_must_eat)
	{
		while (!state->philo_dead && (state->num_finish_meal < state->num_philo))
			usleep(1000);
	}
	else
	{
		while (!state->philo_dead)
			usleep(1000);
	}
}
