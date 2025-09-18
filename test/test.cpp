#include <catch2/catch_all.hpp>
#include <iostream>
#include <string>

#include "AVL.h"
#include "helpers.h"

using namespace std;

// My name: John Ronchetto
// My UFID: 52490540


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

TEST_CASE("Insert test", "[Insert]") {

	AVL tree;
	// Student s("John" , 12345678);
	vector<std::string> expected {"John"};

	tree.insert("John", "12345678");

	vector<std::string> inTree = tree.inorder();
	REQUIRE(inTree == expected);
}

TEST_CASE("LL case", "[rotate right]") {

	// R rotate
	AVL tree;
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert("C", "34567899");
	tree.insert("B", "23456789");
	tree.insert("A", "12345678");

	REQUIRE(tree.inorder() == expected);
}

TEST_CASE("RR case", "[rotate left]") {

	// L rotate
	AVL tree;
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	tree.insert("C", "34567899");

	REQUIRE(tree.inorder() == expected);
}

TEST_CASE("LR case", "[rotate right left]") {

	// LR rotate
	AVL tree;
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert("C", "34567899");
	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	REQUIRE(tree.inorder() == expected);
}

TEST_CASE("RL case", "[rotate right left]") {

	// R rotate
	AVL tree;
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert("A", "12345678");
	tree.insert("C", "34567899");
	tree.insert("B", "23456789");
	REQUIRE(tree.inorder() == expected);
}


TEST_CASE("Insert 100, remove 10", "[InsRem]") {
	AVL tree;
	std::string name;
	std::vector<std::string> expected, actual;

	int id = 12345678;

	for (int i = 0; i < 100; i++) {

		int repeat = (i / 26) + 1;
		char letter = 'A' + (i % 26);

		// "A","B",...,"Z","AA","BB",...
		name = "";
		for (int j = 0; j < repeat; j++) {
			name += letter;
		}

		id += 1;
		expected.push_back(name);
		tree.insert(name, std::to_string(id));
	}

	// delete first 10
	for (int i = 12345678; i < 12345688; i++) {
		REQUIRE(tree.remove(std::to_string(id)) == true);
		expected.erase(expected.begin());
	}

	actual = tree.inorder();

	REQUIRE(expected.size() == actual.size());
	REQUIRE(expected == actual);
}



