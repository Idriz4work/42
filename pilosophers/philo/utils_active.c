/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_active.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:23:52 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/19 12:24:33 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// number of the left neighbor of philosopher i,
// N is added for the case when  i - 1 is negative
size_t	left(size_t i, int n)
{
	return ((i - 1 + n) % n);
}

// number of the right neighbor of the philosopher i,
size_t	right(size_t i, int n)
{
	return ((i + 1) % n);
}

//
int	is_alive(t_philo *philo, size_t i)
{
	int	result;

	result = EXIT_SUCCESS;
	pthread_mutex_lock(&philo->dead_lock);
	if (philo->phil[i].state == IS_DEAD)
		result = EXIT_FAILURE;
	pthread_mutex_unlock(&philo->dead_lock);
	if (result == EXIT_FAILURE)
		endtimes(i, philo);
	return (result);
}

// checks if the number of eating cycles was reached
int	check_dinner(t_philo *philosopher)
{
	if (philosopher->dinner_count == philosopher->dinner_number)
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
