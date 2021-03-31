#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int> > idx_map;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
  for(int i = 0; i < nums.size(); i++) {
    for(int j = i+1; j <= i+k; j++) {
      if(j >= nums.size()) break;
      long diff = ((long) nums[i]) - ((long) nums[j]);
      if(abs(diff) <= t) return true;
    }
  }

  return false;
} 

int main() {
  int T;
  cin >> T;
  for(int i = 0; i < T; i++) {
    int num, k, t;
    cin >> num >> k >> t;

    vector<int> nums;
    for(int j = 0; j < num; j++) {
      int temp;
      cin >> temp;
      nums.push_back(temp);
    }

    bool result = containsNearbyAlmostDuplicate(nums, k, t);

    cout << "Case #" << i+1 << endl;
    cout << (result ? "true" : "false") << endl;
  }

  return 0;
}
