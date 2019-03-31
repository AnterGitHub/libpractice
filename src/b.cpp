#include<stdio.h>
#include "../include/a.h"

int test_dec(int i) {
	i = test_add(i, 0);
	return --i;
}