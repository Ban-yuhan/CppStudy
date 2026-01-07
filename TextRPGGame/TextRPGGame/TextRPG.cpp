#include <stdio.h>
#include <string.h>
//string : 문자열 → strcpy_s를 사용하기 위해 필요한 헤더
#include <Windows.h>

#include <iostream>
#include <string>

using namespace std;


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
	Pokemon() {}; //디폴트 생성자
	Pokemon(int _id, const char* _name, Status status) 
		: id(_id), lv(1), exp(0), maxExp(100)
	{
		cout << this << ".Pokemon()" << endl;

		strcpy_s(name, _name);
		// Initialize other members as needed
		curHp = status.hp;
		this->status = status;
	}
	-Pokemon() //소멸자
	{
		cout << "-" << "this << ".Pokemon()" << endl;
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

class Tranner 
{
public:
	int id;
	char name[256];
	Pokemon pokemons[5] = { Pokemon(1, "Pikachu", {1, status::Electric, "Pikachu", 100, 55, 40, 90, 50, 50}) };

	Tranner(int _id, const char*strName)  //생성자
	{
		id = _id;
		strcpy(name.strName);
	}

	void CatchPokemon(int idx, Pokemon pokemon) //내가 포켓몬을 잡을 때 어느 슬롯에 넣을 지 선택하도록
	{
		pokemons[idx] = pokemon; 
	}

	Pokemon ThrowPokemon(int idx)  //idx : index → 몇 번째 포켓문인지
	{
		return pokemons[idx];
	}
};

void BattleMain(Pokemon& poke1 , Pokemon& poke2)
{

}



void main()
{
	Pokemon pikachu(1, "Pikachu", { 1, Status::Electric, "Pikachu", 100, 55, 40, 90, 50, 50 });
	Pokemon bulbasaur(2, "Bulbasaur", { 2, Status::Grass, "Bulbasaur", 120, 49, 49, 45, 65, 65 });
	Pokemon pairi(3, "pairi", { 3, Status::Grass, "pairi", 120, 49, 49, 45, 65, 65 });

	Tranner tranner(0, "Red");

	//포켓몬 획은
	tranner.CatchPokemon(0, pikachu);
	tranner.CatchPokemon(1, bulbasaur);
	tranner.CatchPokemon(2, pairi);

	int nSelectPokemon = -1;
	
	if (nSelectPokemon != -1)
	{
		printf("Select Your Pokemon:");
		scanf_s("%d", nSelectPokemon);
	}

	//포켓몬 전투
	Pokemon myPokemon = tranner.ThrowPokemon(0);
	Pokemon wiㅣdPokemon = tranner.ThrowPokemon(1);

	BattleMain(myPokemon, wildPokemon);

	/*while (true)
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
		bulbasaur.DisplayStatus();*/
	}
	
}