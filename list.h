#pragma once

class ListNode
{
public:
	int data;
	ListNode* prev;
	ListNode* next;

	ListNode(int _data = 0, ListNode* _prev = nullptr, ListNode* _next = nullptr)
		: data(_data), prev(_prev), next(_next)
	{}
};

class List
{
private:
	ListNode head;
	ListNode tail;

public:
	List()
	{
		head.next = &tail;
		tail.prev = &head;
	}

	~List()
	{
		RemoveAll();
	}

	bool Is_head(ListNode* node)
	{
		return node != nullptr && node->prev == nullptr && node->next != nullptr;
	}

	bool Is_tail(ListNode* node)
	{
		return node != nullptr && node->prev != nullptr && node->next == nullptr;
	}

	bool Is_interior(ListNode* node)
	{
		return node != nullptr && node->prev != nullptr && node->next != nullptr;
	}

	ListNode* Begin() 
	{
		return head.next;
	}

	ListNode* End()
	{
		return &tail;
	}

	ListNode* Next(ListNode* node)
	{
		if (Is_head(node) || Is_interior(node))
			return node->next;

		return nullptr;
	}

	ListNode* Prev(ListNode* node)
	{
		if (Is_tail(node) || Is_interior(node))
			return node->prev;

		return nullptr;
	}

	void PushBack(ListNode* node)
	{
		Insert(End(), node);
	}

	void PushBack(int n)
	{
		PushBack(new ListNode(n));
	}

	void PushFront(ListNode* node)
	{
		Insert(Begin(), node);
	}

	void PushFront(int n)
	{
		PushFront(new ListNode(n));
	}

	bool Insert(ListNode* before, ListNode* node)
	{
		if (!Is_interior(before) && !Is_tail(before))
			return false;
		if (node == nullptr)
			return false;

		node->prev = before->prev;
		node->next = before;
		before->prev->next = node;
		before->prev = node;

		return true;
	}

	bool Insert(ListNode* before, int n)
	{
		Insert(before, new ListNode(n));
	}

	ListNode* Remove(ListNode* node)
	{
		if (!Is_interior(node))
			return nullptr;

		node->prev->next = node->next;
		node->next->prev = node->prev;

		ListNode* ret = node->next;

		delete node;

		return ret;
	}

	void RemoveAll()
	{
		for (ListNode* node = Begin(); !Is_tail(node);)
		{			
			node = Remove(node);
		}
	}
};
