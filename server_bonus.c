/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:04:36 by gmastroc          #+#    #+#             */
/*   Updated: 2024/04/09 16:45:19 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sighandler(int signum)
{
	static unsigned char	c;
	static int				i;

	if (signum == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa = (struct sigaction){0};
	sa.sa_handler = sighandler;
	ft_printf("Pigliati sto PID: %d\n", getpid());
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
