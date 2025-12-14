
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
	double d = 1.234;
	cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++)
	{
		cout << right << setw(3) << noshowbase << dec << k;
		cout << setw(4) << showbase << oct << k;
    	cout << setw(5) << nouppercase << hex << k ;
		cout << " " << setw(7) << noshowbase << setfill('+') << left << string(k % 5 + 1, '*')  << " ";
		cout << setfill(' ') << showpos << internal << fixed << setprecision(3) << setw(9) << d;
		cout << scientific << noshowpos << right << uppercase << setw(11) << d;
		d = d*-2;
		
		cout << endl;
	}
	return 0;
}

