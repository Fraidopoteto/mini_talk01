#include "minitalk.h"

void	ft_print_pid(pid_t n)
{
	char	c;

	if (n > 9)
	{
		ft_print_pid((n / 10));
		ft_print_pid((n % 10));
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

void ft_handler(int signal)
{
	static char current_char = 0;
	static int bit_count = 0;

	if (signal == SIGUSR1)
		current_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
	current_char <<= 1;
}


int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_print_pid(pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
