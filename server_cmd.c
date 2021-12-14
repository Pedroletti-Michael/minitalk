#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum)
{
	static char buffer = 00000000;
	static int i = 0;

	if (signum == SIGUSR1)
	{
		&buffer = 1;
		buffer << 1;
		i++;
	}
	else if (signum == SIGUSR2)
	{
		buffer << 1;
		i++;
	}
	if (i == 8)
	{
		write(1, &buffer, 1);
		i = 0;
		buffer = 00000000;
	}
}

int	main()
{
	int	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while(1)
	{
		pause();
	}
}
