#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> factorials;

string getPermutation(int n, int k) {
  factorials.clear();
  int fact = 1;
  vector<int> nums;
  for(int i = 1; i <= n-1; i++) {
    nums.push_back(i);
    factorials.push_back(fact * i);
    fact *= i;
  }
  nums.push_back(n);

  int target = k - 1;
  int loc = n - 1;
  vector<int> output;

  while(true) {
    if(loc == 0) {
      output.push_back(nums[0]);
      nums.clear();
      break;
    }

    int idx = target / factorials[loc - 1];
    target = target % factorials[loc - 1];
    output.push_back(nums[idx]);
    nums.erase(nums.begin() + idx);
    loc--;
  }

  stringstream ss;
  for(int i = 0; i < output.size(); i++) {
    ss << output[i];
  }


  return ss.str();
}

int main() {
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    int n, k;
    cin >> n >> k;

    cout << "Case #" << i+1 << endl;
    cout << getPermutation(n, k) << endl;
  }

  return 0;
}