#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<pair<int,int> > glob_input;
vector<int> counts;

void merge(int left, int mid, int right) {
  int num_left = mid - left + 1;
  int num_right = right - mid;

  vector<pair<int,int> > left_list, right_list;
  for(int i = 0; i < num_left; i++) {
    left_list.push_back(glob_input[i + left]);
  }

  for(int i = 0; i < num_right; i++) {
    right_list.push_back(glob_input[mid + 1 + i]);
  }

  int i= 0, j = 0, k = left;

  while(i < num_left && j < num_right) {
    if(left_list[i].second <= right_list[j].second) {
      glob_input[k++] = left_list[i++];
    } else { // Switch
      for(int left_idx = i; left_idx < left_list.size(); left_idx++) {
        counts[left_list[left_idx].first]++;
      }
      glob_input[k++] = right_list[j++];
    }
  }

  while(i < num_left) glob_input[k++] = left_list[i++];
  while(j < num_right) glob_input[k++] = right_list[j++];
}

void mergeSort(int left, int right) {
  if(left >= right) return;

  int mid = left + (right - left) / 2;

  mergeSort(left, mid);
  mergeSort(mid + 1, right);
  merge(left, mid, right);
}

vector<int> countSmaller(vector<int>& nums) {
  int left = 0, right = nums.size() - 1;

  glob_input.clear();
  counts.clear();
  for(int i = 0; i < nums.size(); i++) {
    glob_input.push_back(make_pair(i, nums[i]));
    counts.push_back(0);
  }

  mergeSort(left, right);

  return counts;
}

int main() {
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    int num;
    cin >> num;
    vector<int> inputs;

    for(int j = 0; j < num; j++) {
      int temp;
      cin >> temp;
      inputs.push_back(temp);
    }

    vector<int> output = countSmaller(inputs);
    cout << "Case #" << i+1 << endl;
    for(int j = 0; j < output.size(); j++) {
      cout << output[j] << " ";
    }
    cout << endl;
  }

  return 0;
}