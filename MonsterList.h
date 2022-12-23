#pragma once
#include "Monster.h"

struct MonsterList
{
	Monster* pHead{};
	Monster* pTail{};
};

Monster* CreateMonster(MonsterList& list, const char* name, const int hp);
int CountMonster(MonsterList& list);
void PrintList(MonsterList& list);
void PrintListRecursive(Monster* head);
Monster* FindMonster(MonsterList& list, const char* name);
void DeleteList(MonsterList& list);
bool DeleteMonster(MonsterList& list, const char* name);

