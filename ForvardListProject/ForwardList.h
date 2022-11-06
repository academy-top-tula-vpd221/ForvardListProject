#pragma once
class ForwardList
{
	struct Node
	{
		int value;
		Node* next = nullptr;
	};
	Node* head;
	int size;
public:
	ForwardList() : head{ nullptr }, size{ 0 } {}
	~ForwardList()
	{
		Node* nodeDel;
		while (head)
		{
			nodeDel = head;
			head = head->next;
			delete nodeDel;
		}
	}

	void Show();

	void PushFront(int value);
	int PopFront();
	void Insert(int index, int value);
	int Replace(int index);
};

