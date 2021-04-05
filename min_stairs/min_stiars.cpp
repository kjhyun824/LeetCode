#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<int>& nodes) {
  priority_queue<pair<int,int> > pq;
  vector<int> distance(nodes.size() + 1, INT32_MAX);

  pq.push(make_pair(0, 0));
  distance[0] = 0;

  while(pq.empty() == 0) {
    int cost = -pq.top().first;
    int curr = pq.top().second;
    pq.pop();

    for(int i = 0; i < 2; i++) {
      int next = curr + i + 1;
      int next_cost = nodes[curr];

      if(distance[next] > cost + next_cost) {
        distance[next] = cost + next_cost;
        pq.push(make_pair(-distance[next], next));
      }
    }
  }

  return distance[nodes.size()];
}

int minCostClimbingStairs(vector<int>& cost) {
  int start_0 = shortestPath(cost);
  cost.erase(cost.begin());
  int start_1 = shortestPath(cost);

  return min(start_0, start_1);
}

int main() {
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    int num_elems;
    vector<int> elements;
    cin >> num_elems;

    for(int j = 0; j < num_elems; j++) {
      int temp;
      cin >> temp;
      elements.push_back(temp);
    }

    int output = minCostClimbingStairs(elements);
    cout << "Case #" << i+1 << endl;
    cout << output << endl;
  }

  return 0;
}