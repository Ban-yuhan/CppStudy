#include <iostream>
#include <string>

using namespace std;

//객체지향 프로그래밍(OOP - Object Oriented Programming)
//추상화 : 실제 대상을 관찰하여 클래스를 제작하는 과정


//추상화할 대상 : RPG 게임 캐릭터 → 변경되는 수치(스테이터스 창) : HP, MP, 공격력, 방어력 etc… → 변수


class RPGPlayer 
{
	//멤버변수 : 클래스에서 선언된(클래스 안에 있는) 변수 
	int hp; 
	int mp;
	int atk;

	//멤버함수(동작 : 동작의 결과로 인해 변수가 변경되기 때문에 동작이라고도 부름) : 멤버의 변수에 접근하여 값을 변경하는 클래스 내부의 함수
	void Attack(RPGPlayer player)
	{
		player.Damaged(atk);
		player.mp--;
	}
	
	void Damaged(int enemyAtk)
	{
		hp -= enemyAtk;
	}

	bool Death()
	{
		return (hp <= 0);
	}
};

//TV나 관찰하고 싶은 무언가의 속성과 동작을 구분해 추상화하기
//관찰 대상 : 오디오 인터페이스
//속성 : 연결(마이크) : bool , 연결(PC/기기) : bool, 마이크볼륨 : float, 오디오볼륨 : float, Gain : float, Reverb : float, Headphones : float, 
//		NoiseReducer : int, VoiceChanger : int, DirectMonitor : int, SideChain : int, RGB : int, 작동저장 : bool
//동작 : 마이크 페이더 조작 : 마이크 볼륨조절, 오디오페이드 조작 : 오디오 볼륨조절, Gain 다이얼 조작 : Gain 조절, Reverb 다이얼 조작 : Reverb 조절, Headphones다이얼 조작 : Headphones 조절
//		NoiseReducer 버튼 조작 : 0, 1, 2단계 조절, VoiceChanger 버튼 조작 : 0~4단계 조절, DirectMonitor 켜기/끄기, SideChain 켜기/끄기, RGB 버튼 : 0~4단계조절, 작동저장 : 특정작동저장
class()
{
	enum E_RGB {R, G, B, P, RainBow};
	bool m_isMicConnect;
	bool m_isSysConnect;

}

//속성(변경되는 것) : 색상 : 문자열, 속도 : float, 기어 : int, 시동 : bool, 연료 : float, 문 : bool배열(문 개수가 여러개), 우측 방향지시등 : bool, 좌측 방향지시등 : bool → on/off가 되거나, 수치로 표현되는 것
//동작 : 브레이크 : 속도를 감소, 엑셀 : 속도를 증가, 기어변경 : 기어를 변경, 시동(키 꽂기) : , 연료 채우기 , 문여닫기, 방향지시등 켜기/끄기, 우/좌측 방향지시등 켜기/끄기
class Car
{
	//m_ : 멤버변수라는 의미
	string m_strColor;
	float m_fSpeed;

	enum E_GEAR { P, N, D, R };
	E_GEAR m_eGear;

	bool m_isOn;
	float m_fFuel;

	enum E_DOOR { FL, FR, BL, BR, BACK, MAX };
	bool door[E_DOOR::MAX];

	bool rightSignal;
	bool leftSignal;


	void SetColor(string color)
	{

	}

	void Break()
	{

	}

	void Accel()
	{

	}

	void SetGear(float value)
	{

	}

	void RightSignal()
	{

	}

	void LeftSignal()
	{

	}

	void EmergencySignal(bool on)
	{

	}
};