#pragma once
#include "Price.h"
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

	void delete_node(const int index)
	{
		if (index > 0) {
			Node<T>* to_del = get_node(index - 1);
			to_del->next = to_del->next->next;
		}
		else
			this->head = this->head->next;
		Size--;
	}

public:

	List<T>()
	{
		Size = 0;
		head = nullptr;
	}
	~List<T>() {}

	//Dobavit' v konec
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
	//Dobavit' v nachalo
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

	//Poisk po znacheniyu
	int search(T s)
	{
		int counter = 0;
		Node<T>* cur = this->head;
		while (cur)
		{
			if (cur->info == s)
			{
				return counter;
			}
			cur = cur->next;
			counter++;
		}
	}

	//Udalit' element po znacheniyu
	void del(T del, Node<T>* pos = nullptr)
	{
		Node<T>* cur = this->head;

		if (pos)
			cur = pos;

		if (this->head->info == del && !pos)
		{
			this->head = this->head->next;
			Size--;
			return;
		}
		while (cur->next != nullptr)
		{
			if (cur->next->info == del)
			{
				cur->next = cur->next->next;
				Size--;
				return;
			}
			cur = cur->next;
		}
	}

	//Udalit' duplikaty
	void dedup()
	{
		Node<T>* cur = this->head;
		while (cur)
		{
			for (int i = 0; i < this->Size; i++)
				del(cur->info, cur);
			cur = cur->next;
		}
	}

	//Metod vyvoda
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

	//Proverka na pustotu
	bool isEmpty()
	{
		return !(this->Size);
	}

	//Poluchit' indeks po znacheniyu
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

	//Vstavka v otsortirovannyj spisok
	void insert_at_sort(T value)
	{
		Node<T>* cur = this->head;
		while (cur->next != nullptr)
		{
			if (cur->info > cur->next->info)
			{
				cout << "It does not sorted!" << endl;
				return;
			}
			cur = cur->next;
		}
		insert(get_pos(value), value);
	}

	T& operator[](const int index)
	{
		return get_node(index)->info;
	}

	//Poluchit' razmer
	int getSize()
	{
		return this->Size;
	}

	Node<T>* get_node(const int index)
	{
		int counter = 0;
		Node<T>* cur = this->head;
		while (cur != nullptr)
		{
			if (counter == index)
			{
				return cur;
			}
			cur = cur->next;
			counter++;
		}
	}

	void insertion_sort()
	{
		for (int i = 1; i < Size; i++) {
			Node<T>* key = get_node(i);
			delete_node(i);
			int j = i - 1;
			while (j >= 0 && (*this)[j] > (key->info))
			{
				j = j - 1;
			}
			insert(j + 1, key->info);
		}
	}

	friend ostream& operator<<(ostream& os, const List<T> a)
	{
		Node<T>* cur = a.head;
		while (cur)
		{
			os << cur->info << endl;
			cur = cur->next;
		}
		return os;
	}

	friend istream& operator>>(istream& is, List<T>& a)
	{
		T in;	
		is >> in;
		a.push_back(in);
		return is;
	}
};

	