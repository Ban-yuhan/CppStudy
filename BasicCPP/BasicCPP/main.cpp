#define _CRT_SECURE_NO_WARNINGS
//주석: 없는 문장으로 취급함(코드를 컴파일러가 처리하지않음.)
//헤더파일: 다른 파일의 내용을 포함하는 파일
#include <stdio.h> //표준입출력 헤더파일을 포함하다.
//포함하다 //standard input output 헤더파일
//함수: 특정기능을 만들어 재활용하는데 사용함.
int Add(int a, int b) 
{
	return a + b;
}

int Sub(int a, int b) 
{
	return a - b;
}
//나누기, 곱하기 함수도 만들어보자. *,/ , mutip, div
int Div(int a, int b)
{
	return a / b;
}
//void FunctionTestMain() //함수정의
//{
//	printf("FuctionTest!");
//	printf("Add: %d\n", Add(3, 5));
//	printf("Sub: %d\n", Sub(10, 4));
//}

void FunctionTestMain(int a, int b) //매개변수를 정의해서 외부에 값을 변경해서 넣을수있다.
{
	printf("FuctionTest!");
	printf("Add: %d\n", Add(a, b));
	printf("Sub: %d\n", Sub(a, b));
	//나누기, 곱하기 함수도 사용하고 결과를 출력해보자.
	printf("Div: %d\n", Div(a, b));
}
//사용자로부터 두 숫자를 입력받아 사칙연산을 수행하는 프로그램 만들기
void FunctionCalcultorMain()
{
	int a = 0, b = 0 , c = 0;
	char op = '_';
	//scanf_s("%d %c %d", &a, &op, &b); // 10 + 20
	scanf("%d %c %d", &a, &op, &b); // &a: a라는 그릇의 주소를 가져와라.
	
	//if (op == '+')
	//	c = Add(a, b);
	//else if(op == '-')
	//	c = Sub(a, b);
	//else if (op == '*')
	//	c = Div(a,b);
	//else if (op == '/')
	//	;
	//else
	//	printf("Unknown operator: %c\n", op);

	switch (op)
	{
	case '+':
		c = Add(a, b);
		break;
	case '-':
		c = Sub(a, b);
		break;
	case '*':
		//c = a * b;
		break;
	case '/':
		c = Div(a, b);
		break;
	}

	printf("%d %c %d = %d\n", a, op, b, c);
}


//main은 무엇인가? //어쩠든 없으면안됨(프로그램의 시작점(시작하는 위치))
//main이 없습니다.(error LNK2019: main"int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) 함수에서 참조되는 확인할 수 없는 외부 기호)
int main() //빌드 및 실행: ctrl + F5
{	
	FunctionTestMain(200,150); //합수호출: 함수내에 모든 기능을 실행함.
	FunctionCalcultorMain();
	//print function("문장")//문장 출력기능
	//소거법: 어떤것을 제거하여 필요성을 확인하는 과정 -> 설명하는 기능이 실제로 어떤 결과를 만드는지 실행하며 확인한다.
	printf("Hello, World!\n");//\n: 줄바꿈 문자(new line) //;(세미콜론): 문장의 끝을 나타냄.	
	//e0020: 빨간줄뜨는 것을 모름(식별자를 찾을 수 없음.)

	//내 이니셜을 화면에 출력해보자.
	printf("khg\n");


	//1+1 을 계산하는 프로그램을 만들기
	printf("1 + 1 = %d\n", 1 + 1); //%d: 정수형식지정자

	//35+99를 계산하는 프로그램을 만들기
	

	//프로그램이 맞나요? 적어도 숫자는 바꿔넣어야지 프로그램이라고 불러도 되지않을까?
	//사용자로부터 두 숫자를 입력받아 더하는 프로그램을 만들어보자.
	//그릇: 그릇에 밥이나 반찬 국이든 무엇이든 담을 수있다. //밥,반찬,국 -> 데이터
	//변수: 데이터를 무엇이든 담는 그릇
	//a,b: 변수의 이름(사용자가 변경가능함)
	int a = 35;//error C4700: 초기화되지 않은 'a' 지역 변수를 사용했습니다.
	int b = 99;
	printf("a + b = %d\n", a + b); //%d(decimal:십진법): 정수형식지정자
	//a와 b를 화면에서 확인하려면 어떻게 해야할까?
	printf("%d + %d = %d\n", a, b, a + b);//%d -> a, %d -> b, %d -> a + b //각 %d는 뒤에 나오는 '그릇'들과 대응된다.
	//a와 b를 더한 값을 c에 넣어서 출력해보자.
	//c라는 그릇을 만들어 a에 데이터와 b의 데이터를 더한 값(데이터)를 넣는다.
	int c = a + b; //c라는 그릇을 만들고 a와 b를 더한 값을 넣어라.
	printf("c = %d\n", c);
	printf("%d + %d = %d\n", a, b, c);//넣고나서 모든변수의 값을 출력하여, 내가 의도한 것대로 작동되었는지 확인한다. //출력을  하여 내가 의도한 결과가 나왔는지 확인하기위해
	//error C2086: 'int c': 재정의: 또 c라는 밥그릇 만들려고함. 만들지마. //데이터에서는 덮어씌어지기때문에 국밥을 만들수없다. 
	//a와 b를 빼보자(계산된 결과가 정상적인지 출력하여 확인하여라)

	c = a - b; //c라는 그릇에 a에서 b를 뺀 값을 넣어라.
	printf("%d - %d = %d\n", a, b, c);
	return 0; //F9: 프레이킹포인트
}