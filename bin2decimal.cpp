/*
bin2decimal.cpp
Erin Tan
CSCI 140 (T, Th)
Project #1 part 2
question 4.28
Visual Studio C++ 2019
10/8/19
*/

#include <iostream>
using namespace std;
int main()
{
		int binary;
		int dec = 0;
		int ctrl = 1;
		cout << "Enter a binary number: ";
		cin >> binary;
		while (binary >= 1)
		{
			dec += (binary % 10) * ctrl;
			binary /= 10;
			ctrl *= 2;
		}
		cout << "Decimal is " << dec << endl;
		system("pause");
		return 0;
}
