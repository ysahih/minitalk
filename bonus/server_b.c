/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:00:43 by ysahih            #+#    #+#             */
/*   Updated: 2023/02/21 23:00:44 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handle_sig(int signal, siginfo_t *info, void *s)
{
	static int	c_pid;
	static int	c;
	static int	i ;

	(void)s;
	if (!c_pid)
		c_pid = info->si_pid;
	if (c_pid != info->si_pid)
	{
		c = 0;
		i = 0;
		c_pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{	
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int					id;
	struct sigaction	sa;

	id = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("server's PID is : ");
	ft_putnbr(id);
	ft_putchar('\n');
	while (1)
		sleep (1);
	return (0);
}
