#include <iostream>
#include <vector>
using namespace std;

bool find132pattern(vector<int>& nums) {
  if(nums.size() < 3) return false;

  int last_num = nums[0];
  int is_inc = -1;
  bool output = false;

  for(int i = 1; i < nums.size(); i++) {
    if(nums[i] < last_num) {
      is_inc = 0;
      break;
    } else if(nums[i] > last_num) {
      is_inc = 1;
      break;
    }
  }

  if(is_inc == -1) return false; // All Same

  for(int i = 1; i < nums.size(); i++) {
    if(is_inc == 0) { // Decreasing
      if(nums[i] > last_num) is_inc = 1;
    } else { // Increasing
      if(nums[i] < last_num) { // Inc -> Dec
        output = true;
        break;
      }
    }
    last_num = nums[i];
  }

  return output;
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

    bool output = find132pattern(nums);
    cout << "Case #" << i+1 << endl;
    cout << (output ? "true" : "false") << endl;
  }

  return 0;
}