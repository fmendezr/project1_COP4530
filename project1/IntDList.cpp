#include "IntDList.hpp"
#include <iomanip>
#include <sstream>


IntDLList::IntDLList() :  ListHead(new IntDLLNode(0))
{
    ListHead->prev = ListHead;
    ListHead->next = ListHead;
}

IntDLList::~IntDLList()
{
    while(!isEmpty()) deleteFromHead();
    
    delete ListHead;
}

void IntDLList::addToHead(int value)
{
    IntDLLNode* newNode = new IntDLLNode(value);
    newNode->prev = ListHead;
    newNode->next = ListHead->next;
    ListHead->next->prev = newNode;
    ListHead->next = newNode;
}

void IntDLList::insertInOrder(int value)
{
    if (isEmpty())
    {
        addToHead(value);
        return;
    }

    IntDLLNode* tmp = ListHead->next;
    while (tmp != ListHead && tmp->info < value)
    {
        tmp = tmp->next;
    }
    
    IntDLLNode* newNode = new IntDLLNode(value);
    newNode->next = tmp;
    newNode->prev = tmp->prev;
    newNode->prev->next = newNode;
    tmp->prev = newNode;
}

void IntDLList::addToTail(int value)
{
    IntDLLNode* newNode = new IntDLLNode(value);
    newNode->next = ListHead;
    newNode->prev = ListHead->prev;
    newNode->prev->next = newNode;
    ListHead->prev = newNode;
}

int IntDLList::deleteFromHead()
{
    
    IntDLLNode* toBeDeleted = ListHead->next;
    int info = toBeDeleted->info;

    ListHead->next = toBeDeleted->next;
    toBeDeleted->next->prev = ListHead;
    
    delete toBeDeleted;
    
    return info;
}

int IntDLList::deleteFromTail()
{
    IntDLLNode* toBeDeleted = ListHead->prev;
    int info = toBeDeleted->info;
    
    ListHead->prev = toBeDeleted->prev;
    toBeDeleted->prev->next = ListHead;
    
    delete toBeDeleted;
    
    return info;
}

void IntDLList::deleteNode(int value)
{
    IntDLLNode* toBeDeleted = ListHead->next;
    
    while(toBeDeleted->info != value)
        toBeDeleted = toBeDeleted->next;
    
    toBeDeleted->prev->next = toBeDeleted->next;
    toBeDeleted->next->prev = toBeDeleted->prev;
    
    delete toBeDeleted;
    
    return;
}

bool IntDLList::isInList(int value) const
{
    
    if (isEmpty()) return false;
    
    IntDLLNode* tmp = ListHead->next;
    
    while(tmp->info != value && tmp->next != ListHead) 
        tmp = tmp->next;
    
    return tmp->info == value;
}

string IntDLList::addToString() const
{
    
    std::stringstream ss;
    
    if (isEmpty()) return "";
    
    IntDLLNode* tmp = ListHead->next;
    
    ss << tmp->info;
    
    while (tmp != ListHead)
    {
        ss << std::setw(0) << " " << tmp->info;
        tmp = tmp->next;
    }
    
    return ss.str();
}
