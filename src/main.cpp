#include <iostream>
#include <sstream>
#include <string>

#include "AVL.h"

// for now just virifyCommand() header
#include "helpers.h"
using namespace std;


// probably have more like a verify command -> 3 arguments
string verifyNextWord(istringstream& in) {

	string word;
	in >> word;

	// not good -> use regex!
	if (word.length() > 20) {
		return "";
	}

	// make sure that each character is valid: a-z, A-Z, or 0-9
	for (char c : word) {
		if (!isalpha(c) && !isdigit(c)) {
			return "";
		}
	}

	return word;
}


int main(){

	AVL tree;

	tree.insert("Alice", "12345678");
	tree.insert("Bob",   "22345678");
	tree.insert("Carol", "32345678");
	tree.insert("Dave",  "42345678");
	tree.insert("Eve",   "52345678");

	tree.remove("32345678");

	tree.printInorder();

	// // read line of input
	// string line;
	// cout << "Enter valid words: " << endl;
	// getline(cin, line);
	//
	// // create input stram form line
	// istringstream in(line);
	//
	// // verify that each word is valid
	// while (in) {
	// 	string word = verifyNextWord(in);
	// 	if (word == "") {
	// 		cout << "Unsuccessful input." << endl;
	// 	} else {
	// 		cout << word << endl;
	// 	}
	// }
	//
	// // read up to the next quotation mark
	// //string next;
	// //getline(in, next, '"');

	return 0;
}
