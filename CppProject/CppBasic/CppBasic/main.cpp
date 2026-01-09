#include <iostream> //stdio와 같음 → 입력 관련 함수가 모여있는 라이브러리
#include <string>

using namespace std; //std를 생략하고 사용하기 위해 선언 → 표준 라이브러리 : 내가 만든 게 아닌 C++에서 필요한 기능을 기본적으로 제공하는 라이브러리. (표준이라는 카테고리 안에 있는 라이브러리들)
//라이브러리 : 함수가 모여있는 곳/함수들의 집합 (라이브러리 = 도서관, 함수 = 책) → 함수가 필요할 때 빌려오는 곳.

namespace C
{
	//이름을 입력하면, 출력하는 프로그램. C언어 스타일.
	void InputNameMain()
	{
		//문자열 : char을 배열로 만든 것. 문장이나 단어 표현을 위해선 문자가 2개 이상 필요하기 때문에 문자배열이 필요.
		char strName[256] = "kjw";
		char arrName[256];/* = { 'k','j','w' };*/
		arrName[0] = 'k';
		arrName[1] = 'j';
		arrName[2] = 'w';
		arrName[3] = '\0'; //null문자 : 문자열의 끝을 나타내는 특수문자. (문자열의 끝을 알려주기 위해 필요함) 이게 없으면 컴퓨터가 어떤 값을 넣을지 몰라 이상한 값을 출력할 수 있음.



		printf("arrName[%x] : %s\n", arrName, arrName); //%x : 16진수 형태로 주소값 출력
		printf("strName[%x] : %s\n", strName, strName);


		printf("whileChar[%x] : ", arrName);

		int idx = 0;
		while (arrName[idx] != '\0')
		{
			printf("%c", arrName[idx]);
			idx++;
		}
		printf("\n");

	}
}

namespace CPP
{
	void InputNameMain()
	{
		string strName = "kjw";

		const char* pStrName = strName.c_str();

		cout << "strName[" << (void*)pStrName << "]:" << strName << endl;
		cout << "whileChar[" << (void*)pStrName << "]:" << pStrName << endl;;

		int idx = 0;
		while (strName[idx] != '\0')
		{
			printf("%c", strName[idx]);
			idx++;
		}
		printf("\n");

	}
}

int main() 
{
	//C::InputNameMain();
	CPP::InputNameMain(); //같은 이름이지만 namespace가 다르기 때문에 구분 가능.

	cout << "Hello World!" << endl;

	std::cout << "KJW" << std::endl; //std를 입력해주어야 오류가 발생하지 않음 
	return 0;
}