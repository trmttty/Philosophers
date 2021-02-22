/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:05:34 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 13:40:13 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		display_finish_all_meals(t_state *state)
{
	uint64_t	duration_time;

	duration_time = get_duration_time(state);
	printf("%10llu All the philosophers have finished their %u meals\n",
			duration_time, state->n_must_eat);
}

void		display_manager(t_philo *philo, t_state *state, char *event)
{
	uint64_t	duration_time;

	duration_time = get_duration_time(state);
	printf("%10llu %u %s\n", duration_time, philo->id, event);
}
