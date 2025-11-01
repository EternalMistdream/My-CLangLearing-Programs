#include<stdio.h>


int main() {
	for (int time = 1; time <= 100; time++)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= i; j++) {
				printf("%02d * %02d = %02d    ", i, j, i * j);
			}
			printf("\n");
		}
		for (int i = 8; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++) {
				printf("%02d * %02d = %02d    ", i, j, i * j);
			}
			printf("\n");
		}	
		printf("\n");

	}
	return 0;
}