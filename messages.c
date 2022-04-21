#include "minitalk.h"

void	error_msg_pid(void)
{
	ft_printf("**************************\n");
	ft_printf("******** PID ERROR *******\n");
	ft_printf("**************************\n");
}

void	error_msg_arg(void)
{
	ft_printf("**************************\n");
	ft_printf("**** INVALID ARGUMENT ****\n");
	ft_printf("**************************\n");
	ft_printf("** Correct format: *******\n");
	ft_printf("** ./client [PID] [MSG] **\n");
	ft_printf("**************************\n");
}
