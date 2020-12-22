#include <iostream>
using namespace std;

#define DEB(x) cout << #x << "==>" << x << endl;
typedef long long ll;
typedef unsigned long long ull;


// fib without dp and with recursion
int fib(int num) {
        if(num <= 2) 
		return 1;

	return fib(num - 1) + fib(num - 2);
}

int main() {
	int num, choise;
	while(true) {
        cout 
			<< "\t###Please Choose operation###\t\n"
           	<< "\tTo quit enter 0\n"
     	    << "\t1) To Fib of N without dp and with recursion.\n\t";
		cin >> choise;
		switch(choise) {
			case 1: 
				cout << "\n\t";
				cin >> num;
				cout << "\tAnswer: " << fib(num) << endl << endl;
				break;
			default:
				cout << "\n\t###Quiting the Proccess...###\t\n" << endl;
				return 0;
		}

	}
    return 0;
}
