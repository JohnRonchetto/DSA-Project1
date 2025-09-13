#include <iostream>
#include <sstream>
#include <string>

#include "AVL.h"

using namespace std;

string verifyNextWord(istringstream& in) {

	string word;
	in >> word;

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

	// read line of input
	string line;
	cout << "Enter valid words: " << endl;
	getline(cin, line);

	// create input stram form line
	istringstream in(line);

	// verify that each word is valid
	while (in) {
		string word = verifyNextWord(in);
		if (word == "") {
			cout << "Unsuccessful input." << endl;
		} else {
			cout << word << endl;
		}
	}

	// read up to the next quotation mark
	//string next;
	//getline(in, next, '"');

	return 0;
}
