#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

void matrixInit(vector< vector<int> >& matrix, int numRows, int numCols) {
	matrix.resize(numRows, vector<int>(numCols));

	int i, j;
	for (i = 0; i < numRows; ++i) {
		for (j = 0; j < numCols; ++j) {
			matrix[i][j] = i*j;
		}
	}
}

struct TokenFreq {
	string token;
	int freq;
};

bool isTokenInFreqVec(string token, const vector<TokenFreq>&  tfVec) {
	bool b = 0;
	unsigned int i;
	for (i = 0; i < tfVec.size(); ++i) {
		if (tfVec.at(i).token == token) {
			b = 1;
			break;
		}
	}
	return b;
}

void stringToLower(string& str) {
	for(int i=0; i<str.size();++i)
   str[i] = tolower(str[i]);
}

void getTokenFreqVec(string& istr, vector<TokenFreq>&  tfVec) {
	stringstream ss(istr);
	string token;
	unsigned int i = 0;

	while (getline(ss, token, ' ')) {
		stringToLower(token);
		if(!token.empty()){
			if (tfVec.empty()) {
				TokenFreq tf = { token, 1 };
				tfVec.push_back(tf);
			} else if (isTokenInFreqVec(token, tfVec)) {
				for (i = 0; i < tfVec.size(); ++i) {
					if (tfVec.at(i).token == token) {
						tfVec.at(i).freq = (tfVec.at(i).freq + 1);
					}
				}
			} else {
				TokenFreq tf = { token, 1 };
				tfVec.push_back(tf);
			}
			//cout << token << '\n';
		}
	}
}

void selectionSort(vector<TokenFreq>& tokFreqVector) {
	unsigned int i, j, minIndex;
	TokenFreq temp;
	for (i = 0; i < (tokFreqVector.size()-1); i++) {
		minIndex = i;
		for (j = i + 1; j < tokFreqVector.size(); j++){
			if (tokFreqVector.at(j).freq < tokFreqVector.at(minIndex).freq)
				minIndex = j;
			}
		if (minIndex != i) {
			temp = tokFreqVector.at(i);
			tokFreqVector.at(i) = tokFreqVector.at(minIndex);
			tokFreqVector.at(minIndex) = temp;
		}
	}
}

void insertionSort(vector<TokenFreq>& tokFreqVector) {
	unsigned int i, j;
	TokenFreq temp;
	for (i = 1; i < tokFreqVector.size(); i++) {
		j = i;
		while (j > 0 && tokFreqVector.at(j - 1).freq < tokFreqVector.at(j).freq) {
			temp = tokFreqVector.at(j);
			tokFreqVector.at(j) = tokFreqVector.at(j-1);
			tokFreqVector.at(j-1) = temp;
			j--;
		}
	}
}

int main()
{
	//PART 1
	vector< vector<int> > matrix;
	int numRows = 3;
	int numCols = 4;
	matrixInit(matrix, numRows, numCols);

	//PART 2
	string s = "Writing   in C or C++ is    like running a chain   saw with all the safety guards removed. In C++, reinvention is    its own reward.";
	vector<TokenFreq> vec;
	getTokenFreqVec(s, vec);
	unsigned int j = 0;
	while (j < vec.size()) {
		std::cout << j << "\t" << vec.at(j).token << "\t" << vec.at(j).freq << '\n';
		++j;
	}
	// selectionSort(vec);
	// insertionSort(vec);
    return 0;
}
