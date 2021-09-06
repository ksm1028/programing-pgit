#include <Windows.h>
#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Game {
private:
	double energy = 100;
	static int life;

public:
	Game();
	double Damage();
	int Die();
	static void heal();
	static void ult();
};
int Game::life = 10;

void Game::ult() {
static int iop = 1;
if(iop != 0){
	cout << "소라카가 궁을 사용하여 체력이 4 증가했습니다." << endl;
	life += 4;
	iop--;
}
else {
	cout << "소라카가 궁극기를 이미 사용하셨습니다." << endl;
}
}
void Game::heal() {
	static int jkl = 5;
	if(jkl != 0){
	cout << "체력이 회복됩니다." << endl;
	life++;
	Sleep(500);
	jkl--;
	}
	else {
		cout << "소라카가 딸피여서 회복시킬 수 없습니다." << endl;
	}

}
int Game::Die() {
	if (life < 0) {
		cout << "당신은 죽었습니다." << endl	;
		return 1;
	}
	return 0;
}
double Game::Damage() {
	double damaged = 0;

	if (energy > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "에너지가 " << damaged << " 감소하여 " << energy << " 이 되었습니다.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "생명이 1 감소하여 " << life << "이 되었습니다." << endl << endl;

		}
		return energy;
	}
}
Game::Game()
{
	cout << "에너지가 " << energy << " 이며, 생명이 " << life << "인 캐릭터가 만들어졌습니다.\n";
}

int main()
{
	srand((unsigned int)time(NULL));
	char play;
	Game player;
	while (1)
	{
		cin >> play;
		switch (play)
		{
			case 'a': player.Damage();
			break;

			case 'h': player.heal();
			break;

			case 'u': player.ult();
			break;
		}
		if (player.Die()) {
			cout << "당신은 죽었습니다." << endl << "수고하셨습니다." << endl;
			break;
		}
	}
	return 0;
}