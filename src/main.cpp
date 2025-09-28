#include <iostream>
#include <limits>

#include "AVL.h"
#include "helpers.h"


int main(){
	AVL tree;

	int N;
	if (!(std::cin >> N)) {
		return 0;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i < N; ++i) {
		std::string line;
		if (!std::getline(std::cin, line)) {
			break;
		}

		if (!verifyCommand(line, tree)) {
			std::cout << "unsuccessful" << std::endl;
		}
	}

	return 0;
}