#include "programing.h"

using namespace std;


int main() {
	Person han;
	han.money = 100;
	han.sharedMoney = 200;
	Person lee;
	lee.money = 150;
	lee.addMoney(200);
	lee.addShared(200);
	cout << han.money << ' ' << lee.money << endl;
	cout << han.sharedMoney << ' ' << lee.sharedMoney << endl;
}