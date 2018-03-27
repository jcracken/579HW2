#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int calcH(std::vector<char> state) {
	unsigned int i = 0;
	unsigned int j = 0;
	int num = 0;

	for (i = 0; i < state.size(); i++) {
		if (state.at(i) == 'W') {
			for (j = i; j < state.size(); j++) {
				if (state.at(j) == 'B') {
					num++;
					break;
				}
			}
		}
	}
	return num;
}

int main(void) {

	std::string in;
	unsigned int i = 0;
	std::vector<char> state;

	std::cout << "Enter initial state: ";
	std::cin >> in;

	for (i = 0; i < in.size(); i++) {
		state.push_back(in.at(i));
	}

	return 0;
}