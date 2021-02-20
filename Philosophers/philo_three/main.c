/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/20 12:40:59 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;
	t_stock		*stock;

	if (check_args(argc, argv))
		return (1);
	if (!(data = ft_calloc(1, sizeof(t_data))))
		return (1);
	init_data(argc, argv, data);
	if (!(philo = ft_calloc(data->n_philo, sizeof(t_philo))))
		return (1);
	if (init_philosopher(philo, data->n_philo))
		return (1);
	if (!(stock = ft_calloc(data->n_philo + 1, sizeof(t_stock))))
		return (0);
	launch(stock, data, philo);
	monitor(data, philo);
	free(philo);
	free(data);
	free(stock);
	return (0);
}
