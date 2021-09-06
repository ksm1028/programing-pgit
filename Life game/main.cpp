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
	cout << "�Ҷ�ī�� ���� ����Ͽ� ü���� 4 �����߽��ϴ�." << endl;
	life += 4;
	iop--;
}
else {
	cout << "�Ҷ�ī�� �ñر⸦ �̹� ����ϼ̽��ϴ�." << endl;
}
}
void Game::heal() {
	static int jkl = 5;
	if(jkl != 0){
	cout << "ü���� ȸ���˴ϴ�." << endl;
	life++;
	Sleep(500);
	jkl--;
	}
	else {
		cout << "�Ҷ�ī�� ���ǿ��� ȸ����ų �� �����ϴ�." << endl;
	}

}
int Game::Die() {
	if (life < 0) {
		cout << "����� �׾����ϴ�." << endl	;
		return 1;
	}
	return 0;
}
double Game::Damage() {
	double damaged = 0;

	if (energy > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "�������� " << damaged << " �����Ͽ� " << energy << " �� �Ǿ����ϴ�.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << endl << endl;

		}
		return energy;
	}
}
Game::Game()
{
	cout << "�������� " << energy << " �̸�, ������ " << life << "�� ĳ���Ͱ� ����������ϴ�.\n";
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
			cout << "����� �׾����ϴ�." << endl << "�����ϼ̽��ϴ�." << endl;
			break;
		}
	}
	return 0;
}