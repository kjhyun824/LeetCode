#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> output;

void twoSum(vector<int>& nums, int target) {
	map<int, int> idx_map;

	for(int i = 0; i < nums.size(); i++) {
		idx_map.insert(make_pair(nums[i], i));
		nums[i] = target - nums[i];
	}

	for(int i = 0; i < nums.size(); i++) {
		if(idx_map.find(nums[i]) != idx_map.end()) {
			if(i == idx_map[nums[i]]) continue;
			else {
				output.push_back(i);
				output.push_back(idx_map[nums[i]]);
				break;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++) {
		output.clear();

		int num_input;
		vector<int> input;
		int target;

		cin >> num_input;

		for(int i = 0; i < num_input; i++) {
			int temp;
			cin >> temp;
			input.push_back(temp);
		}

		cin >> target;

		twoSum(input, target);

		cout << "Case #" << i+1 << endl;
		cout << "Answer : [" << output[0] << ", " << output[1] << "]" << endl;
	}

	return 0;
}
