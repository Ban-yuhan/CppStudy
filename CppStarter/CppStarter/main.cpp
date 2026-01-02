#include <stdio.h>	

int Add(int a, int b);	
float Div(float a, float b);
void AvgCalculator();

void main() 
{
	//int a = 1;
	//int b = 4;
	//printf("Add : %d\n", Add(a, b));

	//printf("Div : %f\n", Div((float)a, (float)b));
	
	AvgCalculator();
}

int Add(int a, int b)
{
	return a + b;
}

float Div(float a, float b)
{
	return a / b;
}


//평균을 구하는 공식 
//데이터: 입력받은값, 합계, 개수

//알고리즘: 1.반복할 횟수를 입력한다.
//          2.반복문을 통해서 입력받은 횟수만큼 값을 입력받는다.
//          3.입력받은 값을 합계에서 더하여 합계에 저장한다.
//          4.입력이 끝나면, 입력받은 합계/개수 = 평균이 나온다.
//          5.입력이 끝나면, 종료한다.
void AvgCalculator()
{
	int inputValue = 0;
	int sumValue = 0;
	int countValue = 0;
	while (true)
	{
		printf("Exit Value : 9999999\n");
		scanf_s("%d", &inputValue);
		printf("Input[%d] : %d", countValue, inputValue);
		if(inputValue == 9999999)
		{
			break;
		}
		sumValue += inputValue;
		countValue++;
	}
	int avgValue = sumValue / countValue;
	printf("Avg : %d\n", avgValue);
}

void AvgCalculatorInputValueCheck()
{
	int inputValue = 0;
	int sumValue = 0;
	const int countValue = 5; //배열의 크기는 변경이 불가 → 처음부터 5로 고정하고, 변경은 불가능하도록
	int ArrayInputValues[constValue] = { 0, };
	printf("inputCount : ");
	for (int i = 0; i < constValue; i++) 
	{
		scanf_s("%d", &inputValue);
		sumValue += inputValue;
		ArrayInputValue[i] = inputValue;
		printf("input[%d] : %d Sum : %d \n", i, sumValue, inputValue)

	}
}
