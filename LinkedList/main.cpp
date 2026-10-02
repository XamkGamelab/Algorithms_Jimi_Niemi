#include <iostream>
#include "LinkedList.h"

int main() 
{
	LinkedList ll;

	for (int i = 1; i < 99; i++)
	{
		ll.Insert(i);
	}

	ll.Print();

	ll.InsertEnd(100);

	ll.Print();

	ll.Find(105);

	ll.Delete(67);

	ll.Print();
}