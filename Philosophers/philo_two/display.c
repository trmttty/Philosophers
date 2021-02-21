/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:05:34 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 00:38:45 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		display_all_meals_ate(t_state *state)
{
	unsigned int	current_time;

	current_time = get_time(state->t_start_usec, state->t_start_sec);
	printf("%10u all the meals ate\n", current_time);
}

void		display_manager(t_data *s, t_philo *philo, char *event)
{
	unsigned int	current_time;

	current_time = get_time(s->state->t_start_usec, s->state->t_start_sec);
	printf("%10u %u %s\n", current_time, philo->id, event);
}
