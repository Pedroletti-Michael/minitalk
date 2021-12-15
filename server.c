#include "minitalk.h"

void signal_handler(int signum)
{
	static unsigned char buffer = 0;
	static int counter = 128;
	static int i = 8;

	if (signum == SIGUSR1)
	{
		buffer += counter;
		counter = counter / 2;
	}
	else if (signum == SIGUSR2)
		counter = counter / 2;
	i--;
	if (i <= 0 || counter < 1)
	{
		write(1, &buffer, 1);
		i = 8;
		counter = 128;
		buffer = 0;
	}
}

int	main()
{
	int	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while(1)
		pause();
}
