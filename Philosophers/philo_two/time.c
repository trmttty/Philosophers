/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:41:46 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 01:42:51 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

unsigned int	get_time(unsigned int start_usec, unsigned int start_sec)
{
	struct timeval	current_time;
	int				sec;

	gettimeofday(&current_time, NULL);
	sec = current_time.tv_sec - start_sec;
	return (((unsigned int)(sec * 1000000 + current_time.tv_usec) - start_usec)
	/ ONE_MILLISEC);
}

int		        get_start_time(t_state *state)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		return (1);
    state->t_start_usec = current_time.tv_usec;
    state->t_start_sec = current_time.tv_sec;
	return (0);
}

