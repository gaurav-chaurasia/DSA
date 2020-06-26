#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int count = 0;
	   string str;
	   cin >> str;
	   for (int i = 1; i < str.size(); ) {
    	   if (str.at(i) != str.at(i-1)) {
    	       count++;
    	       i += 2;
    	       continue;
    	   }
    	   i++;
	   }
	   cout << count << endl;
	}
	return 0;
}
