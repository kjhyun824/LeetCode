#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
	vector<int> output_vec;
	output_vec.push_back(nums[0]);

	for(int i = 1; i < nums.size(); i++) {
		int curr = nums[i];

		if(output_vec.back() >= curr) {
			auto itr = lower_bound(output_vec.begin(), output_vec.end(), curr);
			*itr = curr;
		} else {
			output_vec.push_back(curr);
		}
	}

	return output_vec.size();
}

int main() {
	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		int num;
		vector<int> nums;

		cin >> num;
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
