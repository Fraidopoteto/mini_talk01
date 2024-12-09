#include "minitalk.h"

#include "minitalk.h"

void ft_send(pid_t pid, char *message)
{
	int i;
	int j;
	unsigned char current_char;

	i = 0;
	while (message[i])
	{
		current_char = message[i];
		j = 7 ;
		while (j >= 0)
		{
			if ((current_char >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			j--;
		}
		i++;
	}
}


int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		write(1, "Error\n", 6);
	else if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_send(pid, argv[2]);
	}
	return (0);
}
