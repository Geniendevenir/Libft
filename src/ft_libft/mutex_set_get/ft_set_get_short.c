/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_get_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:40:00 by allan             #+#    #+#             */
/*   Updated: 2024/10/17 17:16:33 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_short(pthread_mutex_t *mutex, short *dest, short value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

short	get_short(pthread_mutex_t *mutex, short *value)
{
	short	get;

	pthread_mutex_lock(mutex);
	get = *value;
	pthread_mutex_unlock(mutex);
	return (get);
}

void	set_u_short(pthread_mutex_t *mutex,
		unsigned short *dest, unsigned short value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

unsigned short	get_u_short(pthread_mutex_t *mutex, unsigned short *value)
{
	unsigned short	get;

	pthread_mutex_lock(mutex);
	get = *value;
	pthread_mutex_unlock(mutex);
	return (get);
}
