#include "MonsterList.h"
#include <cstring>
#include <iostream>

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* pNew = new Monster{};
    strcpy_s(pNew->name, NAME_LENGTH, name);
    pNew->hp = hp;

    if (list.pTail == nullptr)
    {
        list.pHead = pNew;
        list.pTail = pNew;
    }
    else
    {
        list.pTail->pNext = pNew;
        list.pTail = pNew;
    }
    return pNew;
}

int CountMonster(MonsterList& list)
{
    int count{};
    Monster* pElement = list.pHead;
    while (pElement != nullptr)
    {
        count++;
        pElement = pElement->pNext;
    }
    return count;
}

void PrintList(MonsterList& list)
{
    Monster* pElement = list.pHead;
    while (pElement != nullptr)
    {
        std::cout << pElement->name << " : " << pElement->hp << std::endl;
        pElement = pElement->pNext;
    }
}

void PrintListRecursive(Monster* head)              // 주의!!
{
    if (head == nullptr)
    {
        return;
    }
    std::cout << head->name << " : " << head->hp << std::endl;
    PrintListRecursive(head->pNext);
}

Monster* FindMonster(MonsterList& list, const char* name)
{
    Monster* pElement = list.pHead;
    while (pElement != nullptr)
    {
        if (strcmp(pElement->name, name) == 0)
        {
            return pElement;
        }
        pElement = pElement->pNext;
    }
    return nullptr;
}

void DeleteList(MonsterList& list)
{
    Monster* pElement = list.pHead;
    Monster* pTemp;
    while (pElement != nullptr)
    {
        pTemp = pElement->pNext;
        delete pElement;
        pElement = pTemp;
    }

    list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
    Monster* pElement = list.pHead;
    Monster* pPrev{};

    while (pElement != nullptr)
    {
        if (strcmp(pElement->name, name) == 0)
        {
            break;
        }
        pPrev = pElement;
        pElement = pElement->pNext;
    }

    if (pElement == nullptr)
    {
        return false;
    }
    else if (list.pHead == list.pTail)                  // 주의!!
    {
        list.pHead = nullptr;
        list.pTail = nullptr;
    }
    else if (pElement == list.pHead)
    {
        list.pHead = pElement->pNext;
    }
    else if (pElement == list.pTail)
    {
        pPrev->pNext = nullptr;
        list.pTail = pPrev;
    }
    else
    {
        pPrev->pNext = pElement->pNext;
    }
    delete pElement;

    return true;
}
