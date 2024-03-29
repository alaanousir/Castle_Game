#include "LinkedList.h"
#include <iostream>
#include "time.h"
using namespace std;


LinkedList::LinkedList()
{
	count = 0;
	Head = NULL;
}

//List is being desturcted ==> delete all items in the list
LinkedList::~LinkedList()
{
	DeleteAll();
}

/*
* Function: InsertBeg.
* Creates a new node and adds it to the beginning of a linked list.
* 
* Parameters:
*	- data : The value to be stored in the new node.
*/
void LinkedList::InsertBeg(Enemy* data)
{
	LLNode *R = new LLNode(data);
	R->setNext(Head);
	Head = R;
	count++;

}
////////////////////////////////////////////////////////////////////////
/*
* Function: DeleteAll.
* Deletes all nodes of the list.
*/
void LinkedList::DeleteAll()
{
	LLNode *P = Head;
	while (Head != NULL)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
	count = 0;
}

bool LinkedList::DeleteNode(Enemy* value)
{
	LLNode *P = Head;
	if (P->getItem() == value) {
		Head = P->getNext();
		delete P;
		P = NULL;
		count--;
		return true;
	}
	while (P != NULL) {
		if (P->getNext() !=NULL && (P->getNext())->getItem() == value) {
			LLNode *temp = P->getNext();
			LLNode *nxt = temp->getNext();
			delete temp;
			temp = NULL;
			P->setNext(nxt);
			count--;
			return true;
		}

		P = P->getNext();
	}
	return false;
}

void LinkedList::MoveAll()
{
	LLNode *P = Head;
	while (P != NULL)
	{
		P->getItem()->Move();
		P = P->getNext();
	}
}
void LinkedList::ArrayOfPtrs(Enemy*  Arr[], int& EnemyCount)
{
	int i = 0;
	LLNode *P = Head;
	while (P != NULL)
	{
		Arr[i] = P->getItem();
		P = P->getNext();
		i++;
	}
	EnemyCount = count;
}
void LinkedList::Divide(LinkedList& RegionA, LinkedList& RegionB, LinkedList& RegionC, LinkedList& RegionD) const
{
	REGION region;		//The region data stored in the enemy linked list will be stored in this variable.
	LLNode *P = Head;	//Get the pointer to the beginning of the linked list.
	Enemy* EnemyRegion; //Individual data of the linked list will be stored in this variable and updated with each while loop.
	while (P != NULL)
	{
		EnemyRegion = P->getItem();
		region = EnemyRegion->GetRegion();	//Extract the region of that the enemy is in in a variable.
			switch (region)
			{
			case A_REG:
				RegionA.InsertBeg(EnemyRegion);
				break;
			case B_REG:
				RegionB.InsertBeg(EnemyRegion);
				break;
			case C_REG:
				RegionC.InsertBeg(EnemyRegion);
				break;
			case D_REG:
				RegionD.InsertBeg(EnemyRegion);
				break;
			}
		P = P->getNext();
	}
}
void LinkedList::ToHeap(Heap& EnemyPriority) const
{
	srand(time(NULL));
	int max = 30;
	LLNode *P = Head;
	while (P!=NULL)
	{
		EnemyPriority.Enqueue((rand() % (max+ 1)), P->getItem());
		P = P->getNext();
	}
}