/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_programm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:46:39 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/19 12:20:29 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// makes sure that the mutexes are unlcoked before freeing
void mutexes_unlocker(t_philo *philo)
{
    int i;
    int ret;

    i = 0;
    while (i < philo->n_philo)
    {
        // Try to lock each mutex with trylock - if it succeeds, the mutex was unlocked
        // If it returns EBUSY, the mutex is already locked
        ret = pthread_mutex_trylock(&philo->chop_sticks[i]);
        if (ret == 0)
            pthread_mutex_unlock(&philo->chop_sticks[i]);
        i++;
    }

    // For the global mutexes, try the same approach
    ret = pthread_mutex_trylock(&philo->dead_lock);
    if (ret == 0)
        pthread_mutex_unlock(&philo->dead_lock);

    ret = pthread_mutex_trylock(&philo->meal_lock);
    if (ret == 0)
        pthread_mutex_unlock(&philo->meal_lock);

    ret = pthread_mutex_trylock(&philo->last_meal_lock);
    if (ret == 0)
        pthread_mutex_unlock(&philo->last_meal_lock);

    ret = pthread_mutex_trylock(&philo->print_lock);
    if (ret == 0)
        pthread_mutex_unlock(&philo->print_lock);
}

//
// int	endtimes(size_t i, t_philo *philo)
// {
// 	time_log(philo, i, 'd');
// 	pthread_mutex_lock(&philo->exit_lock);
// 	// mutexes_unlocker(philo);
// 	mutex_cleanup(philo, philo->n_philo);
// 	i = 0;
// 	while (i < philo->n_philo)
// 	{
// 		free(philo->phil[i].threads);
// 		i++;
// 	}
// 	free(philo->phil);
// 	pthread_mutex_unlock(&philo->exit_lock);
// 	return (EXIT_SUCCESS);
// }
