#include "fileIOs_wordPairs.h"

/***********************************************************************************/
bool sentenceSplitter( string& fname, vector<string>& sentences){
    
    string fileLine;
    ifstream file;
    file.open(fname.c_str());
    
    if (file.fail()){
        cerr << "Failed to open the file: "<<fname <<endl;
        return(-1);
    }
    
    stringstream buffer;
    buffer << file.rdbuf();
    string fcontent(buffer.str());
    
    file.close();
    
    bool worked = false;
    string delim[5] = { ".\"", "?\"","?",".","\n"};
    unsigned int i, subStrIndex = 0;
    for(i = 1; i < fcontent.length(); i++){
        if(((fcontent.substr(i,2)).compare(delim[0])) == 0){
          sentences.push_back(fcontent.substr(subStrIndex,(i-subStrIndex)));
          subStrIndex = i+2;
        }
        else if(((fcontent.substr(i,2)).compare(delim[1])) == 0){
          sentences.push_back(fcontent.substr(subStrIndex,(i-subStrIndex)));
          subStrIndex = i+2;
        }
        else if(((fcontent.substr(i,1)).compare(delim[2])) == 0){
          sentences.push_back(fcontent.substr(subStrIndex,(i-subStrIndex)));
          subStrIndex = i+1;
        }
        else if(((fcontent.substr(i,1)).compare(delim[3])) == 0){
          sentences.push_back(fcontent.substr(subStrIndex,(i-subStrIndex)));
          subStrIndex = i+1;
        }
        else if(((fcontent.substr(i,1)).compare(delim[4])) == 0){
            subStrIndex = i+1;
        }
  }
    
  //removes the extra spaces on the front, if needed
  for(unsigned int j = 0; j < sentences.size(); ++j){
    if((sentences[j].front()) == ' ')
      sentences[j].erase(0,1);
  }
  if(!sentences.empty()) worked = true;
  return worked;
}

/***********************************************************************************/
bool wordpairMapping( vector<string>& sentences, map< pair<string,string>, int> &wordpairFreq_map){
    //declaration of inscoped variables
    bool worked = false;
    string token;
    pair<string,string> tempPair;
    vector<string> uniqueWords;
    
    
    for(unsigned int i = 0; i < sentences.size(); ++i){

        stringToLower(sentences[i]);
        istringstream ss(sentences[i]);
        
        //pushes all unique words into vector uniqueWords
        while(getline(ss, token, ' ')){
            if(find(uniqueWords.begin(), uniqueWords.end(), token) == uniqueWords.end())
              uniqueWords.push_back(token);
        }
        
        //sorts words lexicographically
        sort(uniqueWords.begin(), uniqueWords.end());
        unsigned int j, k;
        //make pairs and add them to map
        for(j = 0; j < uniqueWords.size(); ++j){
            for(k = (j+1); k < uniqueWords.size(); ++k){
                //cout << uniqueWords[j] << "    " << uniqueWords[k] << endl;
                tempPair = make_pair(uniqueWords[j], uniqueWords[k]);
                if(wordpairFreq_map.find(tempPair) == wordpairFreq_map.end())
                    wordpairFreq_map[tempPair] = 1;
                else
                    wordpairFreq_map[tempPair]++;
            }
        }
        uniqueWords.clear();


    }
    if(!uniqueWords.empty()) worked = true;
    return worked;
}

/***********************************************************************************/
bool freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap ){
   	bool worked = false;
    for (map< pair<string,string>, int>::iterator it = wordpairFreq_map.begin(); it != wordpairFreq_map.end(); ++it) {
        freqWordpair_mmap.insert(make_pair(it->second,it->first));
    }
    
    if(!freqWordpair_mmap.empty()) worked = true;
    return worked;
}

/***********************************************************************************/
void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt){
    ofstream outFile;
    outFile.open(outFname.c_str());
    
    
    multimap<int, pair<string, string> >::reverse_iterator topIt;
    multimap<int, pair<string, string> >::reverse_iterator topItEnd = freqWordpair_multimap.rbegin();
    advance(topItEnd, topCnt);
    for(topIt = freqWordpair_multimap.rbegin(); topIt != topItEnd; ++topIt){
        stringstream wordOne(topIt->second.first);
        stringstream wordTwo(topIt->second.second);
        int count = topIt->first;
        outFile << "<" << wordOne.str() << ", " << wordTwo.str() << ">: " << count << endl;
    }
        
        
    
    multimap<int, pair<string, string> >::iterator botIt;
    multimap<int, pair<string, string> >::iterator botItEnd = freqWordpair_multimap.begin();
    advance(botItEnd, botCnt);
    for(botIt = freqWordpair_multimap.begin(); botIt != botItEnd; ++botIt){
        stringstream wordOne(botIt->second.first);
        stringstream wordTwo(botIt->second.second);
        int count = botIt->first;
        outFile << "<" << wordOne.str() << ", " << wordTwo.str() << ">: " << count << endl;
    }
    
    outFile.close();
}






void stringToLower(string& str) {
    for(unsigned int i=0; i<str.size();++i)
        str[i] = tolower(str[i]);
}
