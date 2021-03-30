#include <iostream>
#include <string>
using namespace std;

string temp;
// 좌 우 체크해서 리턴
bool isValid() {
	if(temp.length() == 0) return false;

	if(temp[0] == '#') {
		if(temp.length() > 1) {
			temp = temp.substr(2, temp.length() - 2);
		} else {
			temp = "";
		}

		return true;
	} else {
		if(temp.length() > 1) {
			size_t pos = temp.find(',');
			if(pos == string::npos) return false;

			temp = temp.substr(pos + 1, temp.length() - (pos + 1));
		} else {
			return false;
		}

		if(isValid() && isValid()) {
			return true;
		} else {
			return false;
		}
	}
}

bool isValidSerialization(string preorder) {
	temp = preorder;
	return (isValid() && temp == "");
}

int main() {
	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		string input;
		cin >> input;

		bool result = isValidSerialization(input);

		cout << "Case #" << i + 1 << endl;
		cout << "Output : " <<  (result ? "true" : "false") << endl;
	}

	return 0;
}
