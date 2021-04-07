#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
	int output = 0;
	return output;
}

int main() {
	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		int num;
		vector<int> nums;

		for(int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			nums.push_back(temp);
		}

		int output = lengthOfLIS(nums);
		cout << "Case #" << i+1 << endl;
		cout << output << endl;
	}

	return 0;
}
