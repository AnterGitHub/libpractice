#include <stdio.h>
#include "../include/a.h"
#include "../include/b.h"

int main(int argc, char const *argv[])
{
	printf("Result is: %d - %d\n", test_add(5, 1), test_dec(667));
	return 0;
}