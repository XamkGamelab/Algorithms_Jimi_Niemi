#include <iostream>

unsigned long long ackermann(unsigned long long m, unsigned long long n)
{
	if (m == 0)
		return n + 1;                               
	if (n == 0)
		return ackermann(m - 1, 1);                   
	return ackermann(m - 1, ackermann(m, n - 1));     
}

int main()
{
	std::cout << "A(2,2) = " << ackermann(2, 2) << "\n";
	return 0;
}
