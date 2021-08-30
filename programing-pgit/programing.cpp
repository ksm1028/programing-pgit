#include "programing.h"

int Person::sharedMoney = 0;
void Person::addMoney(int item) {
	money += item;
}
void Person::addShared(int item) {
	sharedMoney += item;
}