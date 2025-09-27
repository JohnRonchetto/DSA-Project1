#include <catch2/catch_all.hpp>
#include <iostream>

#include "AVL.h"
#include "helpers.h"


// My name: John Ronchetto
// My UFID: 52490540


// Incorrect commands
TEST_CASE("Validate commands", "[Input]") {
	AVL tree;


	// name is empty with spaces
	REQUIRE_FALSE(verifyCommand( R"(insert "    " 12312312)", tree ));
	// name has special characters
	REQUIRE_FALSE(verifyCommand( R"(insert "John@#" 12312312)", tree ));
	// ID is 7 digits
	REQUIRE_FALSE(verifyCommand( R"(remove 1234567)", tree));
	// not an ID
	REQUIRE_FALSE(verifyCommand( R"(remove AB12)", tree));
	// misspelled search
	REQUIRE_FALSE(verifyCommand( R"(serch 12345678)", tree));
	// negative Nth gatorID
	REQUIRE_FALSE(verifyCommand( R"(removeInorder -12)", tree));


}

// Edge cases
TEST_CASE("RemoveInorder edge", "[Edge]") {

	AVL tree;
	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	tree.insert("C", "11112222");

	// unsuccessful - not enough nodes
	tree.removeInorder(3);

	std::vector<std::string> actual = tree.inorder();
	std::vector<std::string> expected = {"C", "A", "B"};

	REQUIRE(actual.size() == expected.size());
	REQUIRE(actual == expected);

}

TEST_CASE("Remove edge", "[Edge]") {

	AVL tree;
	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	tree.insert("C", "11112222");

	// unsuccessful -  does not exist
	tree.remove("99999999");

	std::vector<std::string> actual = tree.inorder();
	std::vector<std::string> expected = {"C", "A", "B"};

	REQUIRE(actual.size() == expected.size());
	REQUIRE(actual == expected);

}

TEST_CASE("Insert duplicate ID", "[Edge]") {
	AVL tree;
	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	tree.insert("C", "11112222");

	// unsuccessful - ID already exists
	tree.insert("Johnny", "12345678");

	std::vector<std::string> actual = tree.inorder();
	std::vector<std::string> expected = {"C", "A", "B"};

	REQUIRE(actual.size() == expected.size());
	REQUIRE(actual == expected);

}

// Rotations
TEST_CASE("LL case", "[rotate]") {

	// R rotate
	AVL tree;
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert("C", "34567899");
	tree.insert("B", "23456789");
	tree.insert("A", "12345678");

	std::vector<std::string> actual = tree.inorder();

	REQUIRE(expected.size() == actual.size());
	REQUIRE(expected == actual);
}

TEST_CASE("RR case", "[rotate]") {

	// L rotate
	AVL tree;
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	tree.insert("C", "34567899");

	std::vector<std::string> actual = tree.inorder();

	REQUIRE(expected.size() == actual.size());
	REQUIRE(expected == actual);
}

TEST_CASE("LR case", "[rotate]") {

	// LR rotate
	AVL tree;
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert("C", "34567899");
	tree.insert("A", "12345678");
	tree.insert("B", "23456789");

	std::vector<std::string> actual = tree.inorder();

	REQUIRE(expected.size() == actual.size());
	REQUIRE(expected == actual);
}

TEST_CASE("RL case", "[rotate]") {

	// R rotate
	AVL tree;
	std::vector<std::string> expected {"A", "B", "C"};

	tree.insert("A", "12345678");
	tree.insert("C", "34567899");
	tree.insert("B", "23456789");

	std::vector<std::string> actual = tree.inorder();

	REQUIRE(expected.size() == actual.size());
	REQUIRE(expected == actual);
}

// Deletion cases
TEST_CASE("remove - 0 child", "[remove]") {
	AVL tree;
	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	tree.insert("C", "34567890");

	// Remove A -> 0 children
	tree.remove("12345678");

	std::vector<std::string> actual = tree.inorder();
	std::vector<std::string> expected = {"B", "C"};

	REQUIRE(actual.size() == expected.size());
	REQUIRE(actual == expected);
}

TEST_CASE("remove - 1 child", "[remove]") {
	AVL tree;
	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	tree.insert("C", "34567890");
	tree.insert("D", "45678912");

	// Remove C -> 1 children
	tree.remove("34567890");

	std::vector<std::string> actual = tree.inorder();
	std::vector<std::string> expected = {"A", "B", "D"};

	REQUIRE(actual.size() == expected.size());
	REQUIRE(actual == expected);

}

TEST_CASE("remove - 2 child", "[remove]") {
	AVL tree;
	tree.insert("A", "12345678");
	tree.insert("B", "23456789");
	tree.insert("C", "34567890");

	// Remove B -> 2 children
	tree.remove("23456789");

	std::vector<std::string> actual = tree.inorder();
	std::vector<std::string> expected = {"A", "C"};

	REQUIRE(actual.size() == expected.size());
	REQUIRE(actual == expected);
}

// insert 100 remove 10 random
TEST_CASE("Insert 100, remove 10", "[InsRem]") {
	AVL tree;
	std::string name, idS;
	std::vector<std::string> expected, actual;
	std::vector<std::string> ids;

	int id = 12345678;

	for (int i = 0; i < 100; i++) {

		int repeat = (i / 26) + 1;
		char letter = 'A' + (i % 26);

		// "A","B",...,"Z","AA","BB",...
		name = "";
		for (int j = 0; j < repeat; j++) {
			name += letter;
		}

		idS = std::to_string(id + i);

		ids.push_back(idS);
		expected.push_back(name);
		tree.insert(name, idS);
	}


	// delete 10 random
	std::vector<int> removed;
	while (removed.size() < 10) {

		int randomId = id + (std::rand() % 100);

		// make sure they are unique
		if (std::find(removed.begin(), removed.end(), randomId) == removed.end()) {

			std::string idStr = std::to_string(randomId);

			auto it = std::find(ids.begin(), ids.end(), idStr);
			auto idx = std::distance(ids.begin(), it);

			// remove from tree
			tree.remove(idStr);
			ids.erase(ids.begin() + idx);
			expected.erase(expected.begin() + idx);

			removed.push_back(randomId);
		}
	}

	actual = tree.inorder();

	REQUIRE(expected.size() == actual.size());
	REQUIRE(expected == actual);
}



