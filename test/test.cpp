#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "AVL.h"

// uncomment and replace the following with your own headers
// #include "AVL.h"

using namespace std;

TEST_CASE("Print tree", "[ex]") {
	AVL tree;
}






// you must write 5 unique, meaningful tests for credit on the testing portion of this project!
// the provided test from the template is below.

TEST_CASE("Example BST Insert", "[flag]"){
		AVL tree;
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
}
