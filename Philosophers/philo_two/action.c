/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:13:25 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/23 02:19:48 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		philo_take_forks(t_data *data)
{
	sem_wait(data->state->sem_forks);
	sem_wait(data->state->sem_display);
	print_timestamp(data, EVENT_FORK);
	sem_post(data->state->sem_display);
	sem_wait(data->state->sem_display);
	print_timestamp(data, EVENT_FORK);
	sem_post(data->state->sem_display);
}

void		philo_eat(t_data *data)
{
	data->philo->last_meal_start = get_duration_time(data->state);
	sem_wait(data->state->sem_display);
	print_timestamp(data, EVENT_EAT);
	sem_post(data->state->sem_display);
	usleep(data->state->time_eat * 1000);
	sem_post(data->state->sem_forks);
}

void		philo_sleep(t_data *data)
{
	sem_wait(data->state->sem_display);
	print_timestamp(data, EVENT_SLEEP);
	sem_post(data->state->sem_display);
	usleep(data->state->time_sleep * 1000);
}

void		philo_think(t_data *data)
{
	sem_wait(data->state->sem_display);
	print_timestamp(data, EVENT_THINK);
	sem_post(data->state->sem_display);
}
