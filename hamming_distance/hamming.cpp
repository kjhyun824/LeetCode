#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
	int num = x ^ y;
	int count = 0;

	while(num != 0) {
		if(num % 2 == 1) {
			count ++;
		}
		num /= 2;
	}

	return count;
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << hammingDistance(a, b) << endl;

	return 0;
}
