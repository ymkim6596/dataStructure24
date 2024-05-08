// 202310302 ±è¿µ¹Î

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int problem_num, student_num, word_num = 0;
	cin >> problem_num;

	for (int problem = 0; problem < problem_num; problem++) {
		cin >> student_num >> word_num;

		string* sentence = new string[word_num];
		for (int word = 0; word < word_num; word++) {
			cin >> sentence[word];
		}

		queue<string>* queue_array = new queue<string>[student_num];
		for (int student = 0; student < student_num; student++) {
			int input_num;
			cin >> input_num;
			for (int input = 0; input < input_num; input++) {
				string word;
				cin >> word;
				queue_array[student].push(word);
			}
		}

		bool is_existed = false;
		for (int word = 0; word < word_num; word++) {
			is_existed = false;
			for (int student = 0; student < student_num; student++) {
				if (sentence[word] == queue_array[student].front()) {
					queue_array[student].pop();
					is_existed = true;
				}
			}
			if (!is_existed) {
				break;
			}
		}
		cout << (is_existed ? "1" : "0") << "\n";
		delete[] queue_array;
	}
}
