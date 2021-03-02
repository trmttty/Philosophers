/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:05:34 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/28 09:30:42 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		display_finish_all_meals(t_state *state)
{
	uint64_t	current_time;

	current_time = get_duration_time(state);
	printf("%llu All the philosophers have finished their %llu meals\n",
			current_time / 1000, state->num_must_eat);
}

void		print_timestamp(t_data *data, uint64_t timestamp, char *action)
{
	printf("%llu %llu %s\n", timestamp / 1000, data->philo->id, action);
}
