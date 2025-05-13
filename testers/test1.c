#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret1 = printf("stdouput: %d'\n", 42);
	int ret2 = ft_printf("myouput: %d'\n", 42);
	return 0;
}