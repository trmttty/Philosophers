/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:13:25 by ttarumot          #+#    #+#             */
/*   Updated: 2021/03/02 09:56:00 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		philo_take_forks(t_data *data)
{
	uint64_t	current_time;

	pthread_mutex_lock(data->philo->m_rfork);
	current_time = get_duration_time(data->state);
	pthread_mutex_lock(data->state->m_display);
	print_timestamp(data, current_time, ACTION_FORK);
	pthread_mutex_unlock(data->state->m_display);
	pthread_mutex_lock(data->philo->m_lfork);
	current_time = get_duration_time(data->state);
	pthread_mutex_lock(data->state->m_display);
	print_timestamp(data, current_time, ACTION_FORK);
	pthread_mutex_unlock(data->state->m_display);
}

void		philo_eat(t_data *data)
{
	uint64_t	current_time;

	current_time = get_duration_time(data->state);
	data->philo->last_meal_start = current_time;
	pthread_mutex_lock(data->state->m_display);
	print_timestamp(data, current_time, ACTION_EAT);
	pthread_mutex_unlock(data->state->m_display);
	usleep(data->state->time_eat * 1000);
	pthread_mutex_unlock(data->philo->m_rfork);
	pthread_mutex_unlock(data->philo->m_lfork);
	data->philo->meal_count++;
	if (data->philo->meal_count == data->state->num_must_eat)
		data->state->num_finish_meal++;
	if (data->state->num_finish_meal >= data->state->num_philo)
	{
		pthread_mutex_lock(data->state->m_display);
		display_finish_all_meals(data->state);
	}
}

void		philo_sleep(t_data *data)
{
	uint64_t	current_time;

	current_time = get_duration_time(data->state);
	pthread_mutex_lock(data->state->m_display);
	print_timestamp(data, current_time, ACTION_SLEEP);
	pthread_mutex_unlock(data->state->m_display);
	usleep(data->state->time_sleep * 1000);
}

void		philo_think(t_data *data)
{
	uint64_t	current_time;

	current_time = get_duration_time(data->state);
	pthread_mutex_lock(data->state->m_display);
	print_timestamp(data, current_time, ACTION_THINK);
	pthread_mutex_unlock(data->state->m_display);
}
