#include <iostream>
#include <vector>
#include <set>
using namespace std;


bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
  if(nums.size() < 2 || k == 0) return false;

  int idx = 0;
  multiset<long> ms;

  for(int i = 0; i < nums.size(); i++) {
    if(ms.size() > k) {
      ms.erase(nums[idx++]);
    }

    auto it = ms.lower_bound((long) nums[i] - (long) t);
    if(it != ms.end() && *it <= ((long) nums[i] + (long)t)) {
      return true;
    }
    ms.insert(nums[i]);
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
