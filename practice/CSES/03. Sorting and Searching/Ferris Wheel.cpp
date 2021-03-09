/**
 * here things to keep in mind is 
 * in each gondola at max 2 children can go 
 * and total weight should not exceed x
 * 
 * here we will keep weight of childrens into a vector
 * after sorting it we can use two pointer
 * 
 * ONE POINTER -> pointing on smallest element
 * ANOTHER POINTER -> biggest element
 * 
 * as at max two children can go in one gondola
 * **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];

	sort(p.begin(), p.end());

	int i = 0, count = 0;
	int j = n - 1;

	while (i <= j) {
		if (p[i] + p[j] <= x) {
			count++;
			i++;
			j--;
		}
		else {
			count++;
			j--;
		}
	}

	cout << count << endl;
	return 0;
}
