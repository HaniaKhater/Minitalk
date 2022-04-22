#include "../inc/minitalk.h"

void	assemble_char(int sig)
{
	static int	c;
	static int	i;

	i++;
	c = c << 1;
	if (sig == SIGUSR2)
		c++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0x0;
	}
}

int	main (void)
{
	int	pid;

	pid = getpid();
	if (pid < 100 && pid <= 32768)
	{
		ft_printf("PID: %d\n", pid);
		while (1)
		{
			signal(SIGUSR1, assemble_char);
			signal(SIGUSR2, assemble_char);
			pause();
		}
	}
	else
		error_msg_pid();
	return (0);
}
