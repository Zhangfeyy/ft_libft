#include <stdio.h>
int main()
{
	// printf("%d, %s", "test", 12); //Seg Fault
	// printf("%");//NULL
	// printf("rty%d");//rty2036896(garbage)
	// printf("%o");//rty2036896(garbage)
	printf("%d",   45600876);//itoa
}
