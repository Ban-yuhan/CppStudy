#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <Windows.h>

using namespace std;

// 상태 데이터 구조체
struct Status {
    int id;
    enum Type { Fire, Water, Grass, Electric, Psychic, Normal };
    Type type;
    string name; // char[] 대신 string 사용
    int hp;
    int attack;
    int defense;
    int speed;
    int attack_s;
    int defense_s;
};

class Pokemon {
private:
    int id;
    string name;
    int curHp;
    int lv;
    int exp;
    int maxExp;

public:
    Status status; // 전투 계산을 위해 public 유지

    // 초기화 리스트 사용 및 디폴트 매개변수
    Pokemon(int _id = 0, const string& _name = "null", Status _status = {})
        : id(_id), name(_name), lv(1), exp(0), maxExp(100), status(_status) {
        curHp = status.hp;
        cout << "[생성] " << name << " (위치: " << this << ")" << endl;
    }

    // 복사 생성자 방지 (의도치 않은 메모리 할당 방지)
    Pokemon(const Pokemon& other) = default;

    ~Pokemon() {
        cout << "[소멸] " << name << endl;
    }

    // 포인터를 통해 원본 포켓몬을 공격
    void Attack(Pokemon* target) {
        if (!target) return;
        cout << name << "의 공격! " << target->GetName() << "에게 " << status.attack << "의 데미지!" << endl;
        target->SetHp(target->GetHp() - status.attack);
    }

    bool IsDead() const { return curHp <= 0; }

    // Getter / Setter
    string GetName() const { return name; }
    int GetHp() const { return curHp; }
    void SetHp(int val) { curHp = (val < 0) ? 0 : val; }

    void DisplayStatus() const {
        cout << "[" << name << "] HP: " << curHp << "/" << status.hp
            << " | LV: " << lv << " | EXP: " << exp << "/" << maxExp << endl;
    }
};

class Trainer {
private:
    int id;
    string name;
    Pokemon* pokemons[5]; // 포켓몬 포인터 배열 (가방)

public:
    Trainer(int _id, const string& _name) : id(_id), name(_name) {
        for (int i = 0; i < 5; ++i) pokemons[i] = nullptr;
    }

    // 원본 포켓몬의 주소값을 저장 (복사 X)
    void CatchPokemon(int idx, Pokemon* pokemon) {
        if (idx >= 0 && idx < 5) {
            pokemons[idx] = pokemon;
            cout << name << " 트레이너가 " << pokemon->GetName() << "을(를) " << idx << "번 칸에 넣었습니다." << endl;
        }
    }

    Pokemon* ThrowPokemon(int idx) {
        if (idx >= 0 && idx < 5) return pokemons[idx];
        return nullptr;
    }
};

// 전투 로직 (참조자가 아닌 포인터로 전달받음)
void BattleMain(Pokemon* myPok, Pokemon* wildPok) {
    if (!myPok || !wildPok) return;

    cout << "\n================= 전투 시작 ================" << endl;

    while (true) {
        cout << "\n--------------------------------------------" << endl;
        myPok->DisplayStatus();
        wildPok->DisplayStatus();
        cout << "--------------------------------------------" << endl;

        // 내 포켓몬 턴
        int choice;
        cout << myPok->GetName() << "의 행동 선택 (1.공격): ";
        cin >> choice;

        if (choice == 1) {
            myPok->Attack(wildPok);
        }

        if (wildPok->IsDead()) {
            cout << wildPok->GetName() << "가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);

        // 야생 포켓몬 턴
        cout << "\n[야생 포켓몬의 턴]" << endl;
        wildPok->Attack(myPok);

        if (myPok->IsDead()) {
            cout << myPok->GetName() << "가 쓰러졌습니다... 패배!" << endl;
            break;
        }

        Sleep(500);
    }
}

int main() {
    // 1. 원본 포켓몬 생성 (딱 3마리만 메모리에 존재)
    Pokemon pika(1, "피카츄", { 1, Status::Electric, "피카츄", 100, 55, 40, 90, 50, 50 });
    Pokemon bulba(2, "이상해씨", { 2, Status::Grass, "이상해씨", 120, 49, 49, 45, 65, 65 });
    Pokemon pairi(3, "파이리", { 3, Status::Fire, "파이리", 110, 52, 43, 65, 60, 50 });

    // 2. 트레이너 생성 및 포인터로 가방에 넣기
    Trainer red(0, "지우");
    red.CatchPokemon(0, &pika);   // 주소 전달
    red.CatchPokemon(1, &bulba);
    red.CatchPokemon(2, &pairi);

    // 3. 가방에서 포인터 꺼내기
    Pokemon* myPokemon = red.ThrowPokemon(0); // 피카츄의 주소
    Pokemon* wildPokemon = red.ThrowPokemon(2); // 파이리의 주소

    // 4. 전투 진행
    BattleMain(myPokemon, wildPokemon);

    return 0;
}