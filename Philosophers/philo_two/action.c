/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:13:25 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/27 11:51:35 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		philo_take_forks(t_data *data)
{
	uint64_t	current_time;

	sem_wait(data->state->sem_forks);
	current_time = get_duration_time(data->state);
	sem_wait(data->state->sem_display);
	print_timestamp(data, current_time, ACTION_FORK);
	sem_post(data->state->sem_display);
	current_time = get_duration_time(data->state);
	sem_wait(data->state->sem_display);
	print_timestamp(data, current_time, ACTION_FORK);
	sem_post(data->state->sem_display);
}

void		philo_eat(t_data *data)
{
	uint64_t	current_time;

	current_time = get_duration_time(data->state);
	data->philo->last_meal_start = current_time;
	sem_wait(data->state->sem_display);
	print_timestamp(data, current_time, ACTION_EAT);
	sem_post(data->state->sem_display);
	usleep(data->state->time_eat * 1000);
	sem_post(data->state->sem_forks);
	data->philo->meal_count++;
	if (data->philo->meal_count == data->state->num_must_eat)
		data->state->num_finish_meal++;
	if (data->state->num_finish_meal >= data->state->num_philo)
	{
		sem_wait(data->state->sem_display);
		display_finish_all_meals(data->state);
		sem_post(data->state->sem_stop);
	}
}

void		philo_sleep(t_data *data)
{
	uint64_t	current_time;

	current_time = get_duration_time(data->state);
	sem_wait(data->state->sem_display);
	print_timestamp(data, current_time, ACTION_SLEEP);
	sem_post(data->state->sem_display);
	usleep(data->state->time_sleep * 1000);
}

void		philo_think(t_data *data)
{
	uint64_t	current_time;

	current_time = get_duration_time(data->state);
	sem_wait(data->state->sem_display);
	print_timestamp(data, current_time, ACTION_THINK);
	sem_post(data->state->sem_display);
}
