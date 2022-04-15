// testLab22.cpp: определяет точку входа для приложения.
//

#include "testLab22.h"
#include "OfStream.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
	IO::OfStream out;
	out.open("test.txt");
	string str;
	int a;
	float b;
	cin >> str;
	cin >> a >> b;
	out << str  << a << b;
	cout << out.name();
	out.close();
	return 0;
}
