/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client _bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:15:42 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/09 16:44:37 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sig_killer(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		s_pid;
	char	*octet;

	i = 0;
	if (argc != 3)
	{
		ft_printf("You did something wrong...\n");
		return (1);
	}
	s_pid = ft_atoi(argv[1]);
	if (s_pid <= 0)
	{
		ft_printf("What about the PID");
		return (1);
	}
	octet = argv[2];
	while (*octet)
	{
		sig_killer(s_pid, *octet);
		octet++;
	}
	sig_killer (s_pid, '\0');
	return (0);
}
