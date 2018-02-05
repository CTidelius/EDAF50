#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;
using std::endl;
using std::cout;

Dictionary::Dictionary() {
	string line;
	ifstream inputFile("/Users/carltidelius/Downloads/EDAF50-master/EDAF50/lab2/words");
	if (inputFile.isOpen()){
		while(getLine(inputFile, line)){
			dict.insert(line);
		}
	}else {
		cout << "Unable to open file";
	}
}


bool Dictionary::contains(const string& word) const {
	if(dict.count(word) == 1){
		cout << "den hittade ordet";
		return true;
	}
	return false;
}


vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
