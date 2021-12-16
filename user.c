#include "minitalk.h"

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

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return(i);
}

void	send_char(char a, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (a & (128 >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		int i = 0;
		while(i < ft_strlen(argv[2]))
		{
			send_char(argv[2][i], pid);
			i++;
		}
	}
	else
	{
		ft_printf("Too many argument or argument missing !");
	}
}
