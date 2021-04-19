#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  for(int i = m; i < m+n; i++) {
    nums1[i] = nums2[i - m];
  }

  sort(nums1.begin(),nums1.end());
  return;
}

int main() {
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    vector<int> nums1, nums2;
    int m, n;
    cin >> m;
    for(int j = 0; j < m; j++) {
      int temp;
      cin >> temp;
      nums1.push_back(temp);
    }

    cin >> n;
    for(int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      nums2.push_back(temp);
    }

    merge(nums1, m-n, nums2, n);

    cout << "Case #" << i+1 << endl;
    for(int j = 0 ; j < m; j++) {
      cout << nums1[j] << " ";
    }
    cout << endl;
  }
  return 0;
}