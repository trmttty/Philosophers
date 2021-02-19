/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:30:51 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/19 13:54:20 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	return (0);
}

void		free_philosophers(t_data *data, t_philo *philo)
{
	unsigned int i;

	i = 0;
	pthread_mutex_destroy(philo->m_display);
	while (i < data->n_philo)
		free(philo[i++].m_fork1);
	free(philo);
	free(data);
}
