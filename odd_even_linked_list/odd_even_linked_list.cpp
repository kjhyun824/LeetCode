#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
	if(head == nullptr || head->next == nullptr) return head;

	ListNode* curr = head->next;
	ListNode* updator = head->next;
	vector<int> even_list;
	int idx = 2;

	do {
		if(idx % 2 != 0) { // Odd
			updator->val = curr->val;
			updator = updator->next;
		} else { // Even
			even_list.push_back(curr->val);
		}

		idx++;
		curr = curr->next;
	} while (curr != nullptr);

	for(int i = 0; i < even_list.size(); i++) {
		updator->val = even_list[i];
		updator = updator->next;
	}

	return head;
}

void printList(ListNode* head) {
	if(head == nullptr) {
		cout << "None" << endl;
		return;
	}

	ListNode* curr = head;
	do {
		cout << curr->val << " ";
		curr = curr->next;
	} while(curr != nullptr);
	cout << endl;
}

int main() {
	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		int num;
		cin >> num;
		ListNode *head = nullptr, *curr = nullptr;

		for(int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			if(curr == nullptr) {
				curr = new ListNode(temp);
				head = curr;
			} else {
				curr->next = new ListNode(temp);
				curr = curr->next;
			}
		}

		head = oddEvenList(head);
		cout << "Case #" << i+1 << endl;
		printList(head);
	}

	return 0;
}