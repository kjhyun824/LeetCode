#include <iostream>
#include <vector>
using namespace std;

int minSwap(vector<int>& A, vector<int>& B) {
  int num = A.size();
  vector<int> swap(num), non(num);
  swap[0] = 1;
  non[0] = 0;

  for(int i = 1; i < num; i++) {
    swap[i] = num;
    non[i] = num;

    if(A[i] > A[i-1] && B[i] > B[i-1]) {
      swap[i] = swap[i-1] + 1;
      non[i] = non[i-1];
    }

    if(A[i] > B[i-1] && B[i] > A[i-1]) {
      swap[i] = min(swap[i], non[i-1] + 1);
      non[i] = min(swap[i-1], non[i]);
    }
  }

  return min(swap[num-1], non[num-1]);
}

int main() {
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    int num;
    vector<int> A, B;

    cin >> num;

    for(int j = 0; j < num; j++) {
      int temp;
      cin >> temp;
      A.push_back(temp);
    }

    for(int j = 0; j < num; j++) {
      int temp;
      cin >> temp;
      B.push_back(temp);
    }

    cout << "Case #" << i+1 << endl;
    cout << minSwap(A,B) << endl;
  }

  return 0;
}