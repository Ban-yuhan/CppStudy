#include <stdio.h>	

int Add(int a, int b);	
float Div(float a, float b);

void main() 
{
	int a = 1;
	int b = 4;
	printf("Add : %d\n", Add(a, b));

	printf("Div : %f\n", Div((float)a, (float)b));

}

int Add(int a, int b)
{
	return a + b;
}

float Div(float a, float b)
{
	return a / b;
}