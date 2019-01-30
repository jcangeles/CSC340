#ifndef fileIOs_wordPairs_h
#define fileIOs_wordPairs_h


#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

/*
Function converts a text file with the name fnace into a list of sentences.
The list of sentences will be stored in the sentences vector in the same order
as it appears in the input file. This function returns true if it is successful;
false otherwise. Delimeters are: period: ., question mark: ? period + double
quotation mark: ." question mark + double quotation mark: ?"
*/
bool sentenceSplitter( string& fname, vector<string>& sentences);

/*
Given a list of sentences stored in the first argument sentences, this function
identifies all the all the unique word-pairs and each word-pair's frequency.
The identified (word-pair, frequency)'s will be stored into wordpariFreq_map,
which is a map of (key, value) pairs. The key of this map a word-pair and the
value is the frequency of this word-pair. This function will return true if the
mapping is successful; false otherwise.
*/
bool wordpairMapping( vector<string>& sentences, map< pair<string,string>, int> &wordpairFreq_map);


/*
 This function flips the wordpairFreq_map such that frequencies will be the keys 
 and word-pairs will be the values. A multimap will be needed as two word-pairs 
 can have the same frequency. This function will return true if the flipping is 
 successful; false otherwise.
 */
bool freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap );

/*
 This function writes the top topCnt most frequent word-pairs and botCnt least 
 frequent word-pairs to a file of the name outFname. Note that all the word-pairs 
 are already ordered in descending order of frequency. You are going to simply use 
 multimap's iterator and revserse_iterator to access the most frequent and least 
 frequent word-pairs.
 */
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt);


//helper functions
void stringToLower(string& str);



#endif
