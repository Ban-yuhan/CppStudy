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
class AudioInterface
{
	int RGB[4];

	string m_strColor;

	bool m_isMicConnect;
	bool m_isSysConnect;
	float m_Gain;
	float m_Reverb;
	float m_Headphones;
	int m_NoiseReducer;
	int m_VoiceChanger;
	bool m_isDirectMonitor;
	bool m_isSideChain;

	enum E_SavedSetting { Setting1, Setting2, Setting3, Setting4, Max };
	bool savedSetting[E_SavedSetting::Max];

	void ChangeColor()
	{

	}

	void MicFade()
	{

	}

	void SysFade()
	{

	}

	void Gain()
	{

	}

	void Reverb()
	{

	}

	void Headphones()
	{

	}

	void NoiseReducer()
	{

	}

	void VoiceChanger()
	{

	}

	void DirectMonitor()
	{

	}

	void SideChain()
	{

	}

	void SaveSetting()
	{

	}

};

//속성(변경되는 것) : 색상 : 문자열, 속도 : float, 기어 : int, 시동 : bool, 연료 : float, 문 : bool배열(문 개수가 여러개), 우측 방향지시등 : bool, 좌측 방향지시등 : bool → on/off가 되거나, 수치로 표현되는 것
//동작 : 브레이크 : 속도를 감소, 엑셀 : 속도를 증가, 기어변경 : 기어를 변경, 시동(키 꽂기) : , 연료 채우기 , 문여닫기, 방향지시등 켜기/끄기, 우/좌측 방향지시등 켜기/끄기
class CCar
{
	//m_ : 멤버변수라는 의미
	string m_strColor; //색상이 외부에 의해 변경되면 불법(물품훼손) → private 선언
	float m_fSpeed; //속도가 

public:
	enum E_GEAR { P, N, D, R };
	enum E_DOOR { FL, FR, BL, BR, BACK, MAX };
private:
	
	E_GEAR m_eGear;

	bool m_bEngineOn;
	float m_fFuel;
		
	bool door[E_DOOR::MAX] = { false };

	bool rightSignal;
	bool leftSignal;
	bool emergencySignal;

	
	public: //이 선언 아래쪽의 모든 내용은 public(C++문법)
		

	//생성자 객체 생성시에 초기값을 지정해주는 함수.
	//생성자는 public이 아니면 객체를 생성할 수 없다.
	CCar(string color = "gray")
	{
		m_strColor = color;
		m_fSpeed = 0;
		m_eGear = E_GEAR::N;
		m_bEngineOn = false;
		m_fFuel = 0;
		rightSignal = false;
		leftSignal = false;
		emergencySignal = false;
	}


	//인터페이스 : 조작을 위한 스위치 / 버튼 / 함수호출
	void SetColor(string color)
	{
		m_strColor = color;
	}

	void OnEngine(bool on)
	{
		m_bEngineOn = on;
	}

	void OpenDoor(E_DOOR e_door, bool on)
	{
		door[e_door] = on;
	}

	void Break()
	{
		m_fSpeed--;
	}

	void Accel()
	{
		m_fSpeed++;
	}

	void AddFuel(float value)
	{
		m_fFuel += value;
	}

	void SetGear(E_GEAR gear)
	{
		m_eGear = gear;
	}

	void RightSignal(bool on)
	{
		rightSignal = on;
	}

	bool GetRightSign()
	{
		return rightSignal;
	}

	void LeftSignal(bool on)
	{
		leftSignal = on;
	}

	bool GetLeftSign()
	{
		return leftSignal;
	}

	void EmergencySignal(bool on)
	{
		bool OriginRSign = GetRightSign();
		bool OriginLSign = GetLeftSign();
		if (on)
		{
			emergencySignal = true;
			rightSignal = true;
			leftSignal = true;
		}
		else
		{
			emergencySignal = false;
			rightSignal = OriginRSign;
			leftSignal = OriginLSign;
		}
	}

	void Display()
	{
		cout << "===========Color : ["<<this<<"] " << m_strColor <<"=========== " << endl;
		cout << "Speed :" << m_fSpeed << endl;
		cout << "Gear : " << m_eGear << endl;
		cout << "EngineOn : " << m_bEngineOn << endl;
		cout << "Fuel : " << m_fFuel << endl;
		for (int i = 0; i < E_DOOR::MAX; i++)
		{
			cout << "Door[" << i << "] : " << door[i]<< "\n" << endl;
		}
		cout << "RightSign : " << rightSignal << endl;
		cout << "LeftSign : " << leftSignal << endl;
		cout << "EmergencySign : " << emergencySignal << endl;
		
		
	}
};


int main()
{
	CCar cCar("red"); //빨간색 자동차를 주문서를 넣었음. → 매개변수를 넣음

	cCar.OpenDoor(CCar::FL, true); //문을 열고 탑승
	cCar.OpenDoor(CCar::FL, false); //탑승 후 문을 닫음
	cCar.Display(); //계기판이 켜짐
	cCar.OnEngine(true); // 시동 걸기
	
	cCar.SetGear(CCar::D); //기어를 D로 변경
	cCar.Accel(); //엑셀 밟기

	cCar.Break();
	cCar.SetGear(CCar::P);
	cCar.OnEngine(false);
		
	

	CCar arrCar[3]; //= { CCar{"greed"}, CCar{"blue"}, CCar{"yellow" } }; 기본생성자를 gray로 해주었기 때문에 생성자 지정을 해주지 않아도 기본생성자로 생성.

	for (int i = 0; i < 3; ++i)
	{
		arrCar[i].Display();
	}
	return 0;
}