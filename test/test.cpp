#include <catch2/catch_all.hpp>
#include <iostream>

#include "AVL.h"
#include "helpers.h"

using namespace std;

TEST_CASE("Validate commands", "[Input]") {

	// name has numbers
	REQUIRE_FALSE(verifyCommand(R"(insert john123 12345678)"));
	// name has special characters
	REQUIRE_FALSE(verifyCommand( R"(insert "John@#" 12312312)" ));
	// name is empty
	REQUIRE_FALSE(verifyCommand( R"(insert "" 34534534)" ));
	// UFID more than 8 digits
	REQUIRE_FALSE(verifyCommand( R"(insert "John" 123456789)" ) );
	// UFID less than 8 digits
	REQUIRE_FALSE(verifyCommand( R"(insert "John" 1234567)" ) );
	// UFID is empty
	REQUIRE_FALSE(verifyCommand( R"(insert "John" 1234567)" ) );

	// need to add more here
	// id missing after remove
	REQUIRE_FALSE(verifyCommand( "remove" ) );
	// name instead of id after remove
	REQUIRE_FALSE(verifyCommand( "remove john" ) );
	// name instead of inorder index after removeInorder
	REQUIRE_FALSE(verifyCommand( "removeInorder john" ) );
}

TEST_CASE("Insert Object test", "[Insert]") {

	AVL tree;
	Student s("John" , 12345678);
	vector<std::string> expected {"John"};

	tree.insert(s);

	vector<std::string> inTree = tree.inorder();
	REQUIRE(inTree == expected);
}

TEST_CASE("LL case", "[rotate right]") {

	// R rotate
	AVL tree;
	Student S1("A", 12345678);
	Student S2("B", 23456789);
	Student S3("C", 34567899);
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert(S3);
	tree.insert(S2);
	tree.insert(S1);
	REQUIRE(tree.inorder() == expected);
}

TEST_CASE("RR case", "[rotate left]") {

	// L rotate
	AVL tree;
	Student S1("A", 12345678);
	Student S2("B", 23456789);
	Student S3("C", 34567899);
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert(S1);
	tree.insert(S2);
	tree.insert(S3);
	REQUIRE(tree.inorder() == expected);
}

TEST_CASE("LR case", "[rotate right left]") {

	// LR rotate
	AVL tree;
	Student S1("A", 12345678);
	Student S2("B", 23456789);
	Student S3("C", 34567899);
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert(S3);
	tree.insert(S1);
	tree.insert(S2);
	REQUIRE(tree.inorder() == expected);
}

TEST_CASE("RL case", "[rotate right left]") {

	// R rotate
	AVL tree;
	Student S1("A", 12345678);
	Student S2("B", 23456789);
	Student S3("C", 34567899);
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert(S1);
	tree.insert(S3);
	tree.insert(S2);
	REQUIRE(tree.inorder() == expected);
}


TEST_CASE("Insert 100, remove 10", "[InsRem]") {

}





// you must write 5 unique, meaningful tests for credit on the testing portion of this project!
// the provided test from the template is below.

// TEST_CASE("Example BST Insert", "[flag]"){
// 		AVL tree;
// 		tree.insert(3);
// 		tree.insert(2);
// 		tree.insert(1);
// 		std::vector<int> actualOutput = tree.inorder();
// 		std::vector<int> expectedOutput = {1, 2, 3};
// 		REQUIRE(expectedOutput.size() == actualOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// }
