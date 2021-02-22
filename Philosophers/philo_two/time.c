/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:41:46 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 10:27:43 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			set_start_time(t_state *state)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
    state->t_start_usec = current_time.tv_usec;
    state->t_start_sec = current_time.tv_sec;
}

uint64_t		get_duration_time(t_state *state)
{
	struct timeval	current_time;
	uint64_t		sec;
	uint64_t		usec;

	gettimeofday(&current_time, NULL);
	sec = current_time.tv_sec - state->t_start_sec;
	usec = current_time.tv_usec - state->t_start_usec;
	return ((sec * 1000000 + usec) / 1000);
}
