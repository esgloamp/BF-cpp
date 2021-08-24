#include <cstdio>
#include <iostream>
#include <string>

struct Node {
	struct Node *next;
	struct Node *prev;
	char value;

	Node() : next(NULL), prev(NULL), value(0)
	{}
};

int main() {
	Node *curr = new Node;
	std::string o = ",+++.";
	for (int i = 0; i < o.length(); ++i) {
		if (o[i] == '+') {
			curr->value++;
		}
		else if (o[i] == '-') {
			curr->value++;
		} 
		else if (o[i] == '>') {
			if (curr->next == NULL) {
				Node *node = new Node;
				curr->next = node;
				node->prev = curr;
				curr = node;
			} else {
				curr = curr->next;
			}
		}
		else if (o[i] == '<') {
			if (curr->prev == NULL) {
				printf("there is no place\n");
				break;
			}
			curr = curr->prev;
		}
		else if (o[i] == ',') {
			std::cin >> curr->value;
		}
		else if (o[i] == '.') {
			std::cout << curr->value;
		}
		else if (o[i] == ']') {
			if (curr->value == 0) {
				continue;
			}
			bool existing = false;
			int t = i;
			while (curr->prev != NULL) {
				curr = curr->prev;				
				t--;
				if (curr->value == '[') {
					existing = true;
					break;
				}
			}
			if (!existing) {
				printf("expected a '[' near %d\n", i);
				return -1;
			}
			i = t + 1;
		}
		else if (o[i] == '[') {
			if (curr->value == 0) {
				bool existing = false;
				int t = i;
				while (curr->next != NULL) {
					curr = curr->next;
					t++;
					if (curr->value == ']') {
						if (curr->next == NULL) {
							printf("program exit with 0\n");
							return 0;
						}
						curr = curr->next;
						existing = true;
						break;
					}
				}
				if (!existing) {
					printf("expected a ']' near %d\n", t);
					return -1;
				}
				i = t + 1;
			}
		}
	}


	return 0;
}