/*
Erin Tan
CSCI 140 T, Th
10/24/19
Visual Studio 2019
Project #2 question #2
bigintmath.cpp */

#include <iostream>
#include <algorithm> 
#include <vector>
#include <array>
#include <string>
using namespace std;

string multiply(string num1, string num2) {
	int sign = 1;
	if (num1[0] == '-') {
		sign = sign * (-1);
		num1.erase(num1.begin());
	}
	if (num2[0] == '-') {
		sign = sign * (-1);
		num2.erase(num2.begin());
	}
	int n1 = num1.size();
	int n2 = num2.size();
	if (n1 == 0 || n2 == 0) {
		return "0";
	}
	vector<int> result(n1 + n2, 0);
	int i1 = 0;
	int i2 = 0;
	for (int i = n1 - 1; i >= 0; i--)
	{
		int rem = 0;
		int n1 = num1[i] - '0';
		i2 = 0;
		for (int j = n2 - 1; j >= 0; j--)
		{

			int n2 = num2[j] - '0';
			int sum = n1 * n2 + result[i1 + i2] + rem;
			rem = sum / 10;
			result[i1 + i2] = sum % 10;
			i2++;
		}
		if (rem > 0) {
			result[i1 + i2] += rem;
		}
		i1++;
	}
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0) {
		i--;
	}
	if (i == -1) {
		return "0";
	}
	string s = "";
	while (i >= 0) {
		s += to_string(result[i--]);
	}
	if (sign == -1) {
		s.insert(s.begin(), '-');
	}
	return s;
}

string add(string a, string b) {
	vector<int> result;
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;
	for (i, j; i > -1; i--, j--) {
		int sum = (a[i] - '0');
		if (j > -1) {
			sum += (b[j] - '0');
		}
		sum += carry;
		result.push_back(sum % 10);
		carry = sum / 10;
	}
	while (j > -1) {
		int sum = b[j] - '0';
		sum += carry;
		result.push_back(sum % 10);
		j--;
		carry = sum / 10;
	}
	if (carry!= 0)result.push_back(carry);
	reverse(result.begin(), result.end());
	string str = "";
	for (int i = 0; i < result.size(); i++)str += (result[i] + '0');
	return str;
}

int main()
{
	string A = "99999999999999999999";
	string B = "2";
	cout << "Adding A, B: " << add(A, B) << endl;
	cout << "Multiplying A, B: " << multiply(A, B) << endl;
	string M = "12345654321";
	string N = "111";
	cout << "Adding M, N: " << add(M, N) << endl;
	cout << "Multiplying M, N: " << multiply(M, N) << endl;
	string m = "9991111111111994444444444";
	string n = "332222222222335555555555";
	cout << "Adding m, n: " << add(m, n) << endl;
	cout << "Multiplying m, n: " << multiply(m, n) << endl;
	string X = "99999999991111111111888888888822222222225555555555";
	string Y = "22222222228888888888444444444477777777776666666666";
	cout << "Adding X, Y: " << add(X, Y) << endl;
	cout << "Multiplying X, Y: " << multiply(X, Y) << endl;
	system("PAUSE");
	return 0;
}