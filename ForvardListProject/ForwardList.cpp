#include "ForwardList.h"

void ForwardList::Insert(int index, int value)
{
	if (!index)
	{
		PushFront(value);
		return;
	}

	Node* nodeNew = new Node();
	nodeNew->value = value;

	if (head)
	{
		Node* nodeCurr{ head };
		for (int i = 0; i < index; i++)
			nodeCurr = nodeCurr->next;

		nodeNew->next = nodeCurr->next;
		nodeCurr->next = nodeNew;
	}
	else
	{
		head = nodeNew;
	}
	size++;
}

int ForwardList::Replace(int index)
{
	if (!index)
		return PopFront();

	Node* nodeDel;
	if (size > 1)
	{
		Node* nodeCurr{ head };
		for (int i = 0; i < index; i++)
			nodeCurr = nodeCurr->next;

		nodeDel = nodeCurr->next;
		nodeCurr->next = nodeDel->next;
	}
	else
	{
		nodeDel = head;
		head = nullptr;
	}
	
	int value = nodeDel->value;
	delete nodeDel;

	size--;
	return value;
}
