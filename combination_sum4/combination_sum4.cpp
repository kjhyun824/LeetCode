#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long combinationSum4(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	vector<unsigned long> count_map(target + 1, 0);
	count_map[0] = 1;

	for(int i = 0; i < count_map.size(); i++) {
		for(int j = 0; j < nums.size() && nums[j] <= i; j++) {
			count_map[i] += count_map[i - nums[j]];
		}
	}

	return count_map[target];
}

int main() {
	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		int num;
		vector<int> nums;
		int target;

		cin >> num;
		for(int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			nums.push_back(temp);
		}
		cin >> target;

		int output = combinationSum4(nums, target);

		cout << "Case #" << i+1 << endl;
		cout << output << endl;
	}

	return 0;
}
