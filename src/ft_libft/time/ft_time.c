/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:23:07 by allan             #+#    #+#             */
/*   Updated: 2024/10/17 17:24:42 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	get_elapsed_time_microseconds(struct timeval start, struct timeval end)
{
	long	elapsed_seconds;
	long	elapsed_microseconds;

	elapsed_seconds = (end.tv_sec - start.tv_sec) * 1000000L;
	elapsed_microseconds = end.tv_usec - start.tv_usec;
	return (elapsed_seconds + elapsed_microseconds);
}

int	ft_usleep(long usec)
{
	struct timeval	start;
	struct timeval	current;
	long			elapsed;
	long			rem;

	if (usec < 0)
		return (write(2, ERR_USEC, ft_strlen(ERR_USEC)), ERROR);
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&current, NULL);
		elapsed = get_elapsed_time_microseconds(start, current);
		rem = usec - elapsed;
		if (rem <= 0)
			break ;
		if (rem > 1000)
			usleep(rem / 2);
		else
			usleep(200);
	}
	return (0);
}

long	get_time(t_time_unit time_unit)
{
	struct timeval	timestamp;

	if (gettimeofday(&timestamp, NULL) == ERROR)
		return (error_msg(ERR_GET_TIME), -1);
	if (time_unit == SECOND)
		return (timestamp.tv_sec + (timestamp.tv_usec / 1000000L));
	else if (time_unit == MILLISECOND)
		return ((timestamp.tv_sec * 1000L) + (timestamp.tv_usec / 1000L));
	else if (time_unit == MICROSECOND)
		return ((timestamp.tv_sec * 1000000L) + timestamp.tv_usec);
	else
		return (error_msg(ERR_TIME_UNIT), -1);
}

long	print_time(long start)
{
	long			curr;
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	curr = (timestamp.tv_sec * 1000L) + (timestamp.tv_usec / 1000L);
	return (curr - start);
}
