#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;
using std::stringstream;
using std::min;

Dictionary::Dictionary() {
	string line;
	ifstream inputFile("/Users/carltidelius/Downloads/EDAF50-master/EDAF50/lab2/words");
	if (inputFile.is_open()){
		while(getline(inputFile, line)){
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			dict.insert(line);
		}
	}else {
		cout << "Unable to open file";
	}
}


bool Dictionary::contains(const string& word) const {
	auto c = dict.find(word);
	if(c != dict.end()){
		return true;
	}
	return false;
}


vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
