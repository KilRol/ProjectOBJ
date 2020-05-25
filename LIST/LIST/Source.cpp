#include <iostream>
#include <fstream>
#include "List.h"
#include "Price.h"
using namespace std;

int main()
{
	List<Price> A;

	if (A.isEmpty())
		cout << "List is Empty" << endl << endl;
	else 
		cout << "List is not Empty" << endl << endl;

	fstream in("input.txt");

	int N;
	in >> N;

	for (int i = 0; i < N; i++)
	{
		in >> A;
	}
	
	cout << "File Reading..." << endl << A;

	if (A.isEmpty())
		cout << "List is Empty" << endl << endl;
	else
		cout << "List is not Empty" << endl << endl;


	Price g("NewProduct", "NewShop", 45);
	Price h("OldProduct", "OldShop", 3);

	A.push_back(g);
	A.push_front(h);

	cout << "Adding 2 items" << endl << A << endl;

	A.insertion_sort();

	cout << "Sort by insertion" << endl << A << endl;

	A.del(h);
	A.del(A[2]);

	cout << "Delete 2 items" << endl << A << endl;

	cout << "Item '" << g <<"' locate at " << A.search(g) + 1 << " position" << endl << A << endl;

	Price j("BB", "R", 464);

	A.insert_at_sort(j);

	cout << "Adding new item without sort" << endl << A << endl;

	A.dedup();

	cout << "Duplicate removing" << endl << A << endl;
}	