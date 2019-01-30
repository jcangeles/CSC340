#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(string str){
  int cnt = 0;
  unsigned int i;
  for(i=0; i<str.length(); ++i){
    if(!isspace(str[i]))
      cnt++;
  }
  return cnt;
}

int GetNumOfWords(string str){
  int cnt = 0;
  unsigned int i;
  for(i=0; i<str.length()-1; ++i){
    if(isspace(str[i]) && !isspace(str[i+1]))
      cnt++;
  }
  return cnt+1;   //compensates for the last word on the string
}

int FindText(string word, string str){
  int cnt = 0;
  size_t n = str.find(word);

  while(n!=string::npos){
    n=str.find(word, n+1);
      if(n) {cnt++;}
  }
  return cnt;
}

void ReplaceExclamation(string &str){
  unsigned int i = 0;
  for(i=0; i < str.length(); ++i){
    if(str.at(i) == '!'){
      str.at(i) = '.';
    }
  }
}

void ShortenSpace(string &str){
  unsigned int i;
  for(i=(str.length()-1); i>0; --i){
    if(isspace(str[i]) && isspace(str[i+1]))
      str.erase(i,1);
  }
}

char printMenu(string str){
  char input = 'a';
  cout << endl << "MENU\n"
          "c - Number of non-whitespace characters\n"
          "w - Number of words\n"
          "f - Find text\n"
          "r - Replace all !'s\n"
          "s - Shorten spaces\n"
          "q - Quit\n\n"
          "Choose an option:\n";

  cin >> input;

  return input;
}



int main(){
  string text = "";
  int counter = 0;
  string word = "";

  cout << "Enter a sample text:" << endl;
  getline(cin, text);

  cout << "\nYou entered: " << text << endl;

  for(;;) {
    switch (printMenu(text)) {
      case 'c':
        counter = GetNumOfNonWSCharacters(text);
        cout << "Number of non-whitespace characters: " << counter << endl;
        break;
      case 'w':
        counter = GetNumOfWords(text);
        cout << "Number of words: " << counter << endl;
        break;
      case 'f':
        cin.ignore();
        cout << "Enter a word or phrase to be found:" << endl;
        getline(cin,word);
        counter = FindText(word,text);
        cout << "\"" << word << "\" instances: " << counter << endl;
        break;
      case 'r':
        ReplaceExclamation(text);
        cout << "Edited text: " << text << endl;
        break;
      case 's':
        ShortenSpace(text);
        cout << "Edited text: " << text << endl;
        break;
      case 'q':
        return EXIT_SUCCESS;
      default:
        cout << "Please choose a valid option." << endl;
    }
  }


  return 0;
}
