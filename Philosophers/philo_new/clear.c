/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 23:36:53 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/25 23:40:39 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		clear_all(t_philo *philo, t_state *state, t_data *data)
{
	sem_unlink("fork");
	sem_unlink("display");
	sem_unlink("finish_meals");
	free(philo);
	free(state);
	free(data);
}
