#include <stdio.h>
//함수의 선언: 함수의 이름과 내용을 컴파일러 에게 알려주는 것. 항상 컴파일러가 존재를 알아야하므로, 인클루드와 메인사이에 함수가 있어야한다.
//ㄴ함수의 정의와 선언을 나누는 방법이 있음.(추후에 다룸)
//형태(형): 모양? 그릇의 종류. 이런 종류의 여러그릇들이 있음.
void SizeofTypes()
{
	printf("Size of char: %zu byte(s)\n", sizeof(char));
	printf("Size of short: %zu byte(s)\n", sizeof(short));
	printf("Size of int: %zu byte(s)\n", sizeof(int));
	printf("Size of long: %zu byte(s)\n", sizeof(long));
	printf("Size of long long: %zu byte(s)\n", sizeof(long long));
	printf("Size of float: %zu byte(s)\n", sizeof(float));
	printf("Size of double: %zu byte(s)\n", sizeof(double));
	printf("Size of long double: %zu byte(s)\n", sizeof(long double));

	//zu : size_t 형식의 출력을 위한 서식 지정자 
}
//변수: 값을 담는 그릇. 각 종류의 그릇을 1개씩 제작하였음.
void SizeofDataValueTypes()
{
	//변수의 선언: 값을 담는 그릇을 만드는데 이름을 지정함. 여기에서 이름은 이변수에 들어갈 대표적인 것을 상징함.
	//ㄴ굳이 이름에 맞지않는 값을 넣어도되지만, 코드를 짜는 중에 혼란을 줄수있기때문에 권장하지않음.
	//예) 그러나 fPi,dPi는 값을 변경하면 안됨. 이유는 파이의 값은 정해져있기때문이다.
	//ㄴ그래서 상수라는 개념이 존제하며 변수앞에 const를 붙이면 변수의 값을 변경할수없게 만든다.
	char cChar = 'Z';
	short sShort = 2 ^ 16;
	int iInt = 200;
	long lLong = 5000L;
	long long longLong = 60000LL;
	//상수(constant): 값을 담는 그릇이지만, 값을 변경할수없는 그릇.
	const float fPi = 3.14f;
	const double dPi = 3.14159;

	//변수는 값을 담는 그릇이므로, 저장된 값을 실행중에 변경이 가능하다.
	cChar = 'z';
	sShort = 32767;
	iInt = -200;
	lLong = -5000L;
	longLong = -60000LL;

	//상수로 변경하면 컴파일러가 값을 바꾸려할때 오류를 만들어서 빌드 할 수 없게 한다. 
	//-> 물리법칙을 바꿀수없는 세계 -> 컴파일러는 신과 같음. -> 신의 법칙을 프로그래머가 설계함
	//바꿔도 되나?? 파이의 값은 바꾸면 안됨. 값이 다르다면 이세계사람임. 세상에 물리법칙이 달라 완전히 다른세계가 될수있다.
	//fPi = 000000;
	//dPi = 233213321;

	printf("Size of cChar:%c/%zu byte(s)\n", cChar, sizeof(cChar));
	printf("Size of sShort:%d/%zu byte(s)\n", sShort, sizeof(sShort));
	printf("Size of iInt:%d/%zu byte(s)\n", iInt, sizeof(iInt));
	printf("Size of lLong:%ld/%zu byte(s)\n", lLong, sizeof(lLong));
	printf("Size of longLong:%lld/%zu byte(s)\n", longLong, sizeof(longLong));

	printf("Size of fPi:%f/%zu byte(s)\n", fPi, sizeof(fPi));
	printf("Size of dPi:%lf/%zu byte(s)\n", dPi, sizeof(dPi));
}

//문자는 아스키코드로 구성되어있다. 256개의 문자표현이 가능하다.(0~255) -> 1byte
void ASCIICharacterExample()
{
	unsigned char cChar = 0; //

	//수업이 금요일은 마지막 날이니까 놀아야지 //1
	while (true)//일단 돌려	
	{
		printf("[%c]%d, ", cChar, cChar);
		cChar++;
		if (cChar >= 255) //256번이 되면 멈춰
		{
			break;
		}
	}

	//오늘 월요일이니까 수업이 있네, ~ 화,수,목,~ 오늘 금요일이니까 놀아야지. //5
	cChar = 0; //다시 0으로 초
	while (cChar < 255) //256보다 작을때까지 돌려
	{
		printf("[%c]%d, ", cChar, cChar);
		cChar++;
	}

	////256번을 붙여넣으면 너무 힘들다.
	//printf("printf: %c/%d\n", cChar, cChar);
	//cChar++;

	//printf("printf: %c/%d\n", cChar, cChar);
	//cChar++;

	//printf("printf: %c/%d\n", cChar, cChar);
	//cChar++;

	//printf("printf: %c/%d\n", cChar, cChar);
	//cChar++;

}
//문제: int형의 최대값이 몇인지 확인해보고, unsigned int형의 최대값도 확인한다.
void InitMaxTestMain()
{
	//int maxInt = 2147483647; //2^31 -1
	//unsigned int maxUInt = 4294967295; //2^32 -1
	//두 변수 모두 최대값을 넣었을때 실제 출력결과 값을 확인하여,
	//int형과 unsigned int형의 최대값이 맞는지 확인해보자.
	int maxInt = 4294967295; //2^31 -1
	unsigned int maxUInt = 4294967295; //2^32 -1

	printf("Max int: %d\n", maxInt);
	printf("Max unsigned int: %u\n", maxUInt);
}
//평균을 구하는 공식. (평균값)은 미리 (몇 개)를 받을 지 지정하고 그만큼 (입력)을 받아 합계를 구해 (평균)을 구한다. → 변수 4개 
//데이터: 입력받은값, 합계, 개수
// 
//알고리즘: 1.반복할 횟수를 입력한다.
//			2.반복문을 통해서 입력받은 횟수만큼 값을 입력받는다.
//			3.입력받은 값을 합계에서 더하여 합계에 저장한다.
//		    4.입력이 끝나면, 입력받은 합계/개수 = 평균이 나온다.
//			5.입력이 끝나면, 종료한다.

void AvgCalculator()
{
	int inputValue = 0; 
	int sumValue = 0; 
	int countValue = 0; 
 	printf("InputCount:");
	scanf_s("%d", &countValue); //1.반복할 횟수를 입력한다 //5
	for (int i = 0; i < countValue; i++)//2.반복문을 통해서  // 0, 5 //1, 5
	{
		scanf_s("%d", &inputValue);//100 //110 //입력받은 횟수만큼 값을 입력받는다
		sumValue += inputValue; //0+100 //100+110 //입력받은 값을 inputValue에 저장한다.
		printf("Input[%d]: %d Sum:%d\n", i, inputValue, sumValue);//0,100,100 //1,110, 210
	}
	int avgValue = sumValue / countValue; //평균을 횟수가 입력값을 모두 더한 값을 개수로 나누어 저장한다.
	printf("Sum / Avg: %d / %d\n", sumValue, avgValue);//평균값을 출력한다.
}

//평균을 구하는 공식.						
//데이터: 입력받은값, 합계, 개수
// 
//알고리즘: 1.반복할 횟수를 입력한다.
//			2.입력받은 값을 합계에서 더하여 합계에 저장한다.
//			3.입력후 값을 개수에 1증가 시킨다.
//		    4.입력이 끝나면, 입력받은 합계/개수 = 평균이 나온다.
//			5.입력이 끝나면, 종료한다.

void AvgCalculatorWithWhile()
{
	int inputValue = 0;
	int sumValue = 0;
	int countValue = 0;
	printf("Exit Value: 9999999\n");
	while (true)
	{
		scanf_s("%d", &inputValue); //입력받은 횟수만큼 값을 입력받는다
		printf("Input[%d]: %d", countValue, inputValue);
		if (inputValue == 9999999)
		{
			break;
		}
		sumValue += inputValue; //입력받은 값을 inputValue에 저장한다.
		countValue++;
	}
	int avgValue = sumValue / countValue; //평균을 횟수가 입력값을 모두 더한 값을 개수로 나누어 저장한다.
	printf("Avg: %d\n", avgValue);//평균값을 출력한다.
}
//기존의 평균값계산기에 각각 입력한 값을 저장할수있도록 변경하여라.(단, 이때 저장을 위해 반복횟수는 고정한다)
void AvgCalculatorInputValueCheck()
{
	int inputValue = 0;
	int sumValue = 0;
	const int countValue = 5; //배열의 크기는 변경이 불가능하므로 처음부터 5로고정하고, 변경은 불가능하도록 만든다(const). const로 선언하지 않으면 오류 발생.
	int ArrayInputValues[countValue] = { 0, }; //입력할 값 5개를 저장하기위해서 배열을 만든다.

	for (int i = 0; i < countValue; i++)//2.반복문을 통해서  // 0, 5 //1, 5
	{
		printf("InputValue[%d]:", i);
		scanf_s("%d", &inputValue);//100 //110 //입력받은 횟수만큼 값을 입력받는다
		sumValue += inputValue; //0+100 //100+110 //입력받은 값을 inputValue에 저장한다.
		ArrayInputValues[i] = inputValue; //0 = 100 //1 = 110 //만든 배열의 번호에 입력받은 값을 저장한다.
		printf("Input[%d]: %d Sum:%d\n", i, inputValue, sumValue);//0,100,100 //1,110, 210
	}
	int avgValue = sumValue / countValue; //평균을 횟수가 입력값을 모두 더한 값을 개수로 나누어 저장한다.
	printf("Sum / Avg: %d / %d\n", sumValue, avgValue);//평균값을 출력한다.

	int inputCheckValue = 0;

	printf("Input Values Check(Exit: 9999999):");
	while (inputCheckValue != 9999999)
	{
		//보고 싶은 횟수의 입력값을 입력하면, 저장된 입력값을 출력하여 보여준다.
		scanf_s("%d", &inputCheckValue); //0 //1
		printf("[%d]%d\n", inputCheckValue, ArrayInputValues[inputCheckValue]); //100 //110
	}
}

void main()
{
	//SizeofTypes();
	//SizeofDataValueTypes();
	//ASCIICharacterExample();
	//InitMaxTestMain();
	//AvgCalculator();
	//AvgCalculatorWithWhile();
	AvgCalculatorInputValueCheck();
}

// 배열의 특징 : 연속적으로 데이터 저정
//   123
// 1 OOO
// 2 OOO
// 3 OOO
//Display[3][3] → C++에서는 이렇게 2차원 배열을 작성
// 
//input Player1 x,y : 1, 1
//   123
// 1 XOO
// 2 OOO
// 3 OOO
// 
//input Player2 x,y : 1, 2
//   123
// 1 XZO
// 2 OOO
// 3 OOO

