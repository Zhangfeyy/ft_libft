#include "ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf("%s, %d\n", "good", 45678);//good, 45678
	ft_printf("%s, %i\n", "good", 45678);//good, 45678
	ft_printf("%c, %i\n", 'f', 45678);//f, 45678
	ft_printf("%x, %X\n", 10, 10);//a, A
	ft_printf("%%\n");//%
}