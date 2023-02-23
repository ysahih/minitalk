/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:00:06 by ysahih            #+#    #+#             */
/*   Updated: 2023/02/22 18:44:46 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	str_convert(char c, int pid)
{	
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(500);
		if ((c & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	i = 0;
	if (!argv[1])
		return (0);
	pid = ft_atoi(argv[1]);
	if (!pid || pid < 0)
	{
		ft_putstr("Invalid PID\n");
		exit(0);
	}
	if (argc != 3)
	{
		ft_putstr("INVALID FORMAT!\n");
		exit(0);
	}
	if (argc == 3)
		while (argv[2][i])
			str_convert(argv[2][i++], pid);
	str_convert('\n', pid);
	return (0);
}
