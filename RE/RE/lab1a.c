#include <stdio.h>
#include <Windows.h>

int add(x, y);

void main() {
	int a = GetTickCount();
	srand(a);
	int b = rand() & 0x0FFF;
	int c = rand() & 0x0FFF;
	a = add(b, c);
	printf("%d\n", b);

	getchar();
}

int add(x, y) {
	return x + y;
}