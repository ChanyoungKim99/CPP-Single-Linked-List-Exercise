#include <iostream>
#include "MonsterList.h"

int main()
{
	MonsterList myList;

	CreateMonster(myList, "DEMON", 200);
	CreateMonster(myList, "SLIME", 50);
	CreateMonster(myList, "WOLF", 100);

	std::cout << CountMonster(myList) << std::endl;

	PrintList(myList);
	PrintListRecursive(myList.pHead);
	Monster* pFind = FindMonster(myList, "DEMON");
	if (pFind == nullptr)
	{
		std::cout << "NOT FOUND" << std::endl;
	}
	else
	{
		std::cout << pFind->name << " FOUND" << std::endl;
	}

	//DeleteList(myList);
	//std::cout << CountMonster(myList) << std::endl;

	DeleteMonster(myList, "SLIME");
	PrintList(myList);
	std::cout << CountMonster(myList) << std::endl;
}