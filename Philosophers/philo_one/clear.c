/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 23:36:53 by ttarumot          #+#    #+#             */
/*   Updated: 2021/03/02 10:07:41 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		clear_all(t_philo *philo, t_state *state, t_data *data)
{
	uint64_t	i;

	pthread_mutex_destroy(state->m_display);
	i = 0;
	while (i++ < state->num_philo)
		pthread_mutex_init(&state->m_forks[i], NULL);
	free(state->m_display);
	free(state->m_forks);
	free(philo);
	free(state);
	free(data);
}
