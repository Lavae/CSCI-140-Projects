/*
rot13-encrypt.cpp
Erin Tan
CSCI 140 (T, Th)
Project #1 part 2
question 21.7
Visual Studio C++ 2019
10 / 8 / 19
*/

#include <iostream>
using namespace std;

string key(string msg){
	int count = 0;
	string msgspc = "";
	unsigned char ch = '0';
	while (count <= msg.length()){
		ch = msg[count];
		//if lowercase
		if (islower(ch)){
			ch += 13;
			if (ch > 'z'){
				ch -= 26;
			}
		}
		//if uppercase
		if (isupper(ch)){
			ch += 13;
			if (ch > 'Z'){
				ch -= 26;
			}
		}
		//add to str
		msgspc += ch;
		count++;
	}
	return msgspc;
}
int main(int argc, char* argv[]){
	string test;
	string msg = "";
	cout << "Enter a string to encrypt: " << endl;
	cin >> test;

	msg = key(test);
	cout << "Tester: " << test << endl;
	cout << "Encrypt: " << msg << endl;

	msg = key(msg);
	cout << "Decrypt: " << msg << endl;
	system("pause");
	return 0;
}
