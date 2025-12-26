
#define _CRT_SECURE_NO_WARNINGS

//헤더파일: 다른 파일의 내용을 포함하는 파일(이미 작성해놓은 기능의 묶음을 구현하지 않고도 사용할 수 있도록 함)
#include <stdio.h> //표준입출력 헤더파일을 포함하다.
//포함하다 //standard input output 헤더파일(printf나 scanf등 포함)


//main은 무엇인가? //운영체계가 프로그램 실행 시 가장 먼저 호출하는 함수(프로그램의 시작점(시작하는 위치).)
//main이 없습니다.(error LNK2019: main"int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) 함수에서 참조되는 확인할 수 없는 외부 기호)

int Add(int a, int b);
int Sub(int a, int b);
int Times(int a, int b);
float Div(float a, float b);
void FunctionTestMain(int a, int b);
void FunctionCalculatorMain();


int main() //빌드 및 실행: ctrl + F5
{
	FunctionCalculatorMain();

	FunctionTestMain(200, 150); //함수 호출 : 함수 내의 모든 기능을 실행

	//print function("문장")//문장 출력기능
	//소거법: 어떤것을 제거하여 필요성을 확인하는 과정 → 설명하는 기능이 실제로 어떤 결과를 만드는지 실행하며 확인한다.
	printf("Hello, World! \n");//\n: 줄바꿈 문자(new line) //;(세미콜론): 문장의 끝을 나타냄.	
	//e0020: 빨간줄뜨는 것을 모름(식별자를 찾을 수 없음.)

	//내 이니셜을 화면에 출력해보자.
	printf("KJW \n");


	//1+1 을 계산하는 프로그램을 만들기
	printf("1 + 1 = %d\n", 1 + 1); //%d: 정수형식지정자

	//35+99를 계산하는 프로그램을 만들기
	printf("35 + 99 = %d \n", 35 + 99);


	//프로그램이 맞나요? 적어도 숫자는 바꿔넣어야지 프로그램이라고 불러도 되지않을까?
	//사용자로부터 두 숫자를 입력받아 더하는 프로그램을 만들어보자.
	//그릇: 그릇에 밥이나 반찬 국이든 무엇이든 담을 수있다. //밥,반찬,국 → 데이터
	//변수: 데이터를 무엇이든 담는 그릇
	//a,b: 변수의 이름(사용자가 변경가능함)
	int a = 35;//error C4700: 초기화되지 않은 'a' 지역 변수를 사용했습니다.
	int b = 99;
	printf("a + b = %d\n", a + b); //%d(decimal:십진법): 정수형식지정자


	//a와 b를 화면에서 확인하려면 어떻게 해야할까?
	printf("%d + %d = %d\n", a, b, a + b);//%d → a, %d → b, %d → a + b //각 %d는 뒤에 나오는 '그릇'들과 대응된다.


	//a와 b를 더한 값을 c에 넣어서 출력해보자.
	//c라는 그릇을 만들어 a에 데이터와 b의 데이터를 더한 값(데이터)를 넣는다.
	int c = a + b;
	printf("%d + %d = %d \n", a, b, c); // print를 넣는 이유 : 넣고나서 모든 변수의 값을 출력하여, 내가 의도한 대로 작동되었는지 확인. 


	//a와 b를 빼보자.(계산된 결과가 정상적인지 출력하여 확인하라는 말은 생략.)
	c = a - b;
	printf("%d - %d = %d \n", a, b, c);
	//error C2086: 'int c': 재정의: 또 c라는 밥그릇 만들려고함. 만들지마. //데이터에서는 덮어씌어지기때문에 국밥을 만들수없다. 


	return 0; //F9 : breaking point. 이 포인트에서 변수가 갖는 값을 확인할 수 있음.
	//F11 : 진행할 포인트 지정
	//F10 : 지정된 포인트로부터 1줄씩 진행
}


//함수 : 특정 기능을 만들어 재활용하는데 사용
//함수의 정의 : 반환형 함수이름(파라미터)
int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Times(int a, int b)
{
	return a * b;
}

float Div(float a, float b)
{
	return a / b;
}


void FunctionTestMain(int a, int b) //매개변수(파라미터)를 정의해서 외부에 값을 변경해서 넣을 수 있다.
{
	printf("\nFunctionTest! \n\n");

	printf("a : %d \n b : %d \n\n", a, b);

	printf("Add: %d \n", Add(a, b));
	printf("Sub: %d\n", Sub(a, b));
	printf("Times: %d\n", Times(a, b));
	printf("Div: %d\n", Div(a, b));
}


//ctrl+shift+B : 전체 다시 빌드(전체를 다시 컴파일링함. 오류 수정했음에도 인식을 못하면 사용)
void FunctionCalculatorMain() //계산기(덧셈, 뺄셈, 곱셈, 나눗셈)
{
	int a, b, c;
	char op;
	printf("수식을 입력하시오 : ");
	scanf("%d %c %d", &a, &op, &b);

	if (op == '+')
	{
		printf("%d + %d = %d \n", a, b, Add(a, b));
	}
	else if (op == '-') //char형식은 ""가 아니라 '' 사용. 문자열에서만 "" 사용
	{
		printf("%d - %d = %d \n", a, b, Sub(a, b));
	}
	else if (op == '*')
	{
		printf("%d * %d = %d \n", a, b, Times(a, b));
	}
	else if (op == '/')
	{
		printf("%d / %d = %f \n", a, b, Div((float)a, (float)b));
	}

	//실수를 확인하고 싶다. → 0~1사이의 값 : 실제 물건을 나누었을 때
}



