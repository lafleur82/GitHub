#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define wrap_in_quotes(x) #x
#define wrap_it_up(a) wrap_in_quotes(a)

#define stick_it_together(x, y) x##y
#define concatonate_stuff(a, b) stick_it_together(a,b)

#define bufsize 64

int main()
{
	//variables
	char myArr[bufsize] = wrap_it_up(concatonate_stuff(Race, car));
	//char myArr[bufsize] = wrap_in_quotes(stick_it_together(Race, car));

	printf("%s\n", myArr);
	return 0;
}