#pragma once
#include <iostream>
using namespace std;

template <class T>
class List
{
private:

	template <class T>
	class Node
	{
	public:
		T info;
		Node* next;
		Node(T info = T(), Node* next = nullptr)
		{
			this->info = info;
			this->next = next;
		}
	};

	int Size;
	Node<T>* head;

public:

	List<T>()
	{
		Size = 0;
		head = nullptr;
	}
	~List<T>() {}

	void push_back(T info)
	{
		if (head == nullptr)
		{
			head = new Node<T>(info);
		}
		else
		{
			Node<T>* cur = this->head;

			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new Node<T>(info);
		}
		Size++;
	}

	void push_front(T info)
	{
		Node<T>* h = new Node<T>(info);
		h->next = this->head;
		this->head = h;
		Size++;
	}

	void insert(int pos, T info)
	{
		if (pos == 0)
			push_front(info);
		else if (pos > this->Size)
			push_back(info);
		else
		{
			Node<T>* cur = this->head;
			int counter = 0;
			while (counter != pos - 1)
			{
				cur = cur->next;
				counter++;
			}
			cur->next = new Node<T>(info, cur->next);
			Size++;
		}
	}


	Node<T>* search(T s)
	{
		Node<T>* cur = this->head;
		while (cur->next != nullptr)
		{
			if (cur->info == s)
			{
				return cur;
			}
			cur = cur->next;
		}
	}

	void del(T del, Node<T>* pos = nullptr)
	{
		Node<T>* cur = this->head;

		if (pos)
			cur = pos;

		while (cur->next != nullptr)
		{
			if (this->head->info == del && !pos)
			{
				cout << this->head->info << " has been deleted" << endl;
				this->head = this->head->next;
				Size--;
				return;
			}
			else if (cur->next->info == del)
			{
				cout << cur->next->info << " has been deleted" << endl;
				cur->next = cur->next->next;
				Size--;
				return;
			}
			cur = cur->next;
		}
	}

	void dedup()
	{
		Node<T>* cur = this->head;
		while (cur->next != nullptr)
		{
			for (int i = 0; i < this->Size; i++)
				del(cur->info, cur);
			cur = cur->next;
		}
	}

	void print()
	{
		Node<T>* cur = this->head;
		while (cur)
		{
			cout << cur->info << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	bool isEmpty()
	{
		return !(this->Size);
	}

	int get_pos(T value)
	{
		Node<T>* cur = this->head;
		int pos = 0;
		while (cur)
		{
			if (value > cur->info)
				pos++;
			cur = cur->next;
		}
		return pos;
	}

	void insert_at_sort(T value)
	{
		Node<T>* cur = this->head;
		while (cur->next != nullptr)
		{
			if (cur->info > cur->next->info)
			{
				cout << "It does not sorted! " << value << endl;
				return;
			}
			cur = cur->next;
		}
		insert(get_pos(value), value);
	}

	T& operator[](const int index)
	{
		int counter = 0;
		Node<T>* cur = this->head;
		while (cur != nullptr)
		{
			if (counter == index)
			{
				return cur->info;
			}
			cur = cur->next;
			counter++;
		}
	}
	int getSize()
	{
		return this->Size;
	}
	friend ostream& operator<<(ostream& os, const List<T> a)
	{
		Node<T>* cur = a.head;
		while (cur)
		{
			os << cur->info << " ";
			cur = cur->next;
		}
		return os;
	}
	friend istream& operator>>(istream& is, List<T>& a)
	{
		T value;
		is << value;
		a.push_back(value);
		return is;
	}
};

	