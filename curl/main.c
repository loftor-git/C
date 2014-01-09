#include "stdio.h"
#include "lib/http.h"

int main(int argc, char const *argv[])
{
	int a,b;
	a=1;
	b=3;

	printf("%d\n", plus(a,b));
	return 0;
}