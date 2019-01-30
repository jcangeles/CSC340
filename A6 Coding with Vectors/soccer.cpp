
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void OutputRoster(vector<int> j, vector<int> r) {
	cout << "ROSTER" << endl;
	for (int i = 0; i < j.size(); ++i) {
		cout << "Player "<< i+1 <<"  -- Jersey number: " << j.at(i) << ", Rating: " << r.at(i) << endl;
	}
}

void AddPlayer(vector<int>& j, vector<int>& r) {
	int num;
	cout << "Enter another player's jersey number:" << endl;
	cin >> num;
	j.push_back(num);
	cout << "Enter another player's rating:" << endl;
	cin >> num;
	r.push_back(num);
	cout << endl;
}

void RemovePlayer(vector<int>& j, vector<int>& r) {
	int del;
	cout << "Enter a jersey number:" << endl;
	cin >> del;

	for(int i=0;i < j.size(); ++i){
		if(j.at(i)==del){
			j.erase(j.begin()+i);
			r.erase(r.begin()+i);
		}
	}

}

void UpdatePlayer(vector<int>& j, vector<int>& r) {
	int update;
	int newRating;
	cout << "Enter a jersey number:" << endl;
	cin >> update;

	for(int i=0;i < j.size(); ++i){
		if(j.at(i)==update){
			cout << "Enter a player's rating:" << endl;
			cin >> newRating;
			r.at(i) = newRating;
		}
	}
}

void RosterAboveRating(vector<int> j, vector<int> r) {
	int ratingGiven;
	cout << "Enter a rating:" << endl;
	cin >> ratingGiven;
	cout << endl << "ABOVE " << ratingGiven << endl;
	for(int i=0;i < r.size(); ++i){
		if(r.at(i) > ratingGiven){
			cout << "Player " << i+1 <<" -- Jersey number: " << j.at(i)<< ", Rating: " << r.at(i) << endl;
		}
	}
}

char printMenu(string str) {
	char input = 'z';
	cout << endl << "MENU\n"
		"a - Add player\n"
		"d - Remove player\n"
		"u - Update player rating\n"
		"r - Output players above a rating\n"
		"o - Output roster\n"
		"q - Quit\n\n"
		"Choose an option:\n";

	cin >> input;

	return input;
}



int main() {
	int num;
	string text = "";
	vector<int> jersey;
	vector<int> rating;
	for (int i = 1; i <= 5; ++i) {
		cout << "Enter player " << i << "'s jersey number:" << endl;
		cin >> num;
		jersey.push_back(num);
		cout << "Enter player " << i << "'s rating:" << endl;
		cin >> num;
		rating.push_back(num);
		cout << endl;
	}
	OutputRoster(jersey, rating);
	// cout << "ROSTER" << endl;
	// for (int i = i; i < jersey.size(); ++i) {
	// 	cout << "Player "<< i+1 <<"  -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << endl;
	// }

	for (;;) {
		switch (printMenu(text)) {
		case 'o':
			OutputRoster(jersey, rating);
			break;
		case 'a':
			AddPlayer(jersey, rating);
			break;
		case 'd':
			RemovePlayer(jersey, rating);
			break;
		case 'u':
			UpdatePlayer(jersey, rating);
			break;
		case 'r':
			RosterAboveRating(jersey, rating);
			break;
		case 'q':
			return EXIT_SUCCESS;
		default:
			cout << "Please choose a valid option." << endl;
		}
	}


	return 0;
}
