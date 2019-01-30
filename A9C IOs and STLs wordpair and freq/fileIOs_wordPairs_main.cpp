#include "fileIOs_wordPairs.h"

void printMMap(multimap< int, pair<string,string> > newMMap) {
    cout << "Multimap cointains:\n";
    int counter = 0;
    for (multimap< int, pair<string,string> >::iterator it = newMMap.begin();
         it != newMMap.end(); ++it) {
        
        pair<string,string> curPair = it->second;
        string firstStr = curPair.first;
        string secondStr = curPair.second;
        int curInt = it->first;
        cout << counter << "\t(" << curInt <<", <" << firstStr << "," << secondStr << ">)" << endl;
        counter ++;
    }
}




int main(){

    //Test code to split text into sentences
    string fname = "/Users/jcangeles/OneDrive/SFSU/wordPairs/wordPairs/SteveJobsSpeech2005-full.txt";
    vector<string> sentences;
    bool worksSS = sentenceSplitter(fname,sentences);
    cout << "Sentence Splitter: " << worksSS << endl;


    //Test code to map sentences to
    map< pair<string,string>, int> wordpairFreq_map;
    bool worksWPM = wordpairMapping(sentences, wordpairFreq_map);
    cout << "WordPairMapping: " << worksWPM << endl;

    //Test code to multimap
    multimap<int, pair<string,string>> wordpairFreq_mmap;
    bool worksMMP = freqWordpairMmap(wordpairFreq_map, wordpairFreq_mmap);
    cout << "WordPairMultiMapping: " << worksMMP << endl;
    printMMap(wordpairFreq_mmap);
    
    //Test code for print to file
    string outFname = "/Users/jcangeles/OneDrive/SFSU/wordPairs/wordPairs/outFile.txt";
    printWordpairs(wordpairFreq_mmap, outFname, 10, 50);
    return 0;
}
