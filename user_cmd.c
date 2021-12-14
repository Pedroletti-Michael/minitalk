#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	res;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * (int)res);
}

void	send_char(char a)
{
	// function who's going to send
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		int i = 0;
		while(i < strlen(argv[2]))
		{
			send_char(argv[2][i]);
			usleep(50);
			i++;
		}
	}
	else
	{
		printf("Too many argument or argument missing !");
	}
}
