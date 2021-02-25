/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:05:34 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/25 13:35:07 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		display_finish_all_meals(t_state *state)
{
	uint64_t	current_time;

	current_time = get_duration_time(state);
	printf("%llu All the philosophers have finished at least %u meals\n",
			current_time / 1000, state->num_must_eat);
}

void		print_timestamp(t_data *data, uint64_t timestamp, char *action)
{
	printf("%llu %u %s\n", timestamp / 1000, data->philo->id, action);
}
