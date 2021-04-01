#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int nextGreaterElement(int n) {
	vector<int> rev_elements;
	if(n < 10) return -1;

	while(n != 0) {
		rev_elements.push_back(n%10);
		n /= 10;
	}

	int curr_max = rev_elements[0];
	int target_idx = -1;
	multiset<int> ms;
	ms.insert(rev_elements[0]);

	for(int i = 1; i < rev_elements.size(); i++) {
		ms.insert(rev_elements[i]);

		if(curr_max > rev_elements[i]) {
			target_idx = i;
			break;
		}
		if(curr_max < rev_elements[i]) curr_max = rev_elements[i];
	}

	if(target_idx == -1) return -1;

	int replace_num = *ms.upper_bound(rev_elements[target_idx]);
	auto itr = ms.find(replace_num);
	ms.erase(itr);
	rev_elements[target_idx] = replace_num;

	for(auto it = ms.begin(); it != ms.end(); it++) {
		rev_elements[--target_idx] = *it;
	}

	long output = 0;
	for(int i = 0; i < rev_elements.size(); i++) {
		output += ((long) pow(10, i) * (long) rev_elements[i]);
	}

	if(output > INT32_MAX) return -1;

	return output;
}

int main() {
	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		int input;

		cin >> input;

		int output = nextGreaterElement(input);

		cout << "Case #" << i+1 << endl;
		cout << "Answer : " << output << endl;
	}
	return 0;
}
