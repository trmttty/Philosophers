/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:05:34 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/20 12:40:37 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		display_all_meals_ate(t_data *data)
{
	unsigned int	current_time;

	current_time = get_time(data->t_start_usec, data->t_start_sec);
	printf("%10u all the meals ate\n", current_time);
}

void		display_manager(t_stock *s, t_philo *philo, char *event)
{
	unsigned int	current_time;

	current_time = get_time(s->data->t_start_usec, s->data->t_start_sec);
	printf("%10u %u %s\n", current_time, philo->id, event);
}
