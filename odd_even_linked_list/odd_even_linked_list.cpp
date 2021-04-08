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
	if(head == nullptr) return nullptr;

	ListNode *odds = nullptr;
	ListNode *evens = nullptr;
	ListNode *odd_head = nullptr, *even_head = nullptr;

	ListNode* curr = head;
	int idx = 1;
	do {
		if(idx % 2 != 0) { // Odd
			if(odds == nullptr) {
				odds = new ListNode(curr->val);
				odd_head = odds;
			} else {
				odds->next = new ListNode(curr->val);
				odds = odds->next;
			}
		} else { // Even
			if(evens == nullptr) {
				evens = new ListNode(curr->val);
				even_head = evens;
			} else {
				evens->next = new ListNode(curr->val);
				evens = evens->next;
			}
		}

		idx++;
		curr = curr->next;
	} while(curr != nullptr);

	if(even_head)
		odds->next = even_head;

	return odd_head;
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

		cout << "Case #" << i+1 << endl;
		printList(head);
	}

	return 0;
}