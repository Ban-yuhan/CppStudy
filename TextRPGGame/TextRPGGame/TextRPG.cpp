#include <stdio.h>
#include <string.h>
//string : 문자열 → strcpy_s를 사용하기 위해 필요한 헤더

struct Status
{
	int id;
	enum Type
	{
		Fire,
		Water,
		Grass,
		Electric,
		Psychic,
		Normal
	} type;
	char name[50]; //charactor 배열 = 문자열
	int hp;
	int attack;
	int defense;
	int speed;
	int attack_s;
	int defense_s;
};

class Pokemon
{
	int id;
	char name[50];

	int curHp;
	int curPP;
	int lv;
	int exp;
	int maxExp;

	Status status;

public:
	Pokemon(int _id, const char* _name, Status status) 
		: id(_id), lv(1), exp(0), maxExp(100)
	{
		strcpy_s(name, _name);
		// Initialize other members as needed
		curHp = status.hp;
		this->status = status;
	}

	void AttackSkillA(Pokemon& pokemon)
	{
		pokemon.curHp -= status.attack; // Example damage
	}

	void AttackSkillB(Pokemon& pokemon)
	{
		pokemon.curHp -= status.attack; // Example damage
	}

	void AttackSkillC(Pokemon& pokemon)
	{
		pokemon.curHp -= status.attack_s; // Example damage. 특수공격 (attack_special)
	}

	void AttackSkillD(Pokemon& pokemon)
	{
		pokemon.curHp -= status.attack_s; // Example damage
	}

	bool Death()
	{
		return curHp <= 0;
	}

	void DisplayStatus()
	{
		printf("Pokemon: %s\n", name);
		printf("HP: %d\n", curHp);
		printf("Level: %d\n", lv);
		printf("EXP: %d/%d\n", exp, maxExp);
	}
};

void main()
{
	Pokemon pikachu(1, "Pikachu", { 1, Status::Electric, "Pikachu", 100, 55, 40, 90, 50, 50 });
	Pokemon bulbasaur(2, "Bulbasaur", { 2, Status::Grass, "Bulbasaur", 120, 49, 49, 45, 65, 65 });

	while (true)
	{
		if (pikachu.Death() == false)
		{
			pikachu.AttackSkillA(bulbasaur);
		}
		else
			break;

		if (bulbasaur.Death() == false)
		{
			bulbasaur.AttackSkillB(pikachu);
		}
		else
			break;

		pikachu.DisplayStatus();
		bulbasaur.DisplayStatus();
	}
	
}