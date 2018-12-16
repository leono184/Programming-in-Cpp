#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <iostream>
#include <iterator>

using namespace std;

typedef std::map<std::string, int> dictionary;
typedef std::pair<std::string, int> entry;

void display(const entry& e);
void loadFile(string file, dictionary &d, int &count);
bool compare(const entry &e1, const entry &e2);
bool format(char c);

namespace std {
	ostream& operator<<(ostream& os, const entry& e)
	{
		return os << left << setw(12) << e.first << " " << e.second << endl;
	}
}


int main(){
	
	int count = 0;
	dictionary d;
	loadFile("uppgift1/uppgift1.txt", d, count);

	ofstream os("test.txt");

	cout << "Number of words in the file = " << count << endl;
	cout << "Number unique  words in the file = " << d.size() << endl << endl;
	cout << endl << "Frequency table sorted alphabetically ..." << endl << endl;

	ostream_iterator<entry> out_it(cout);

	copy(d.begin(), d.end(), out_it);

	cout << endl << "Frequency table sorted by frequence ..." << endl << endl;

	vector<entry> dVector(d.size());

	copy(d.begin(), d.end(), dVector.begin());

	sort(dVector.begin(), dVector.end(), compare);

	copy(dVector.begin(), dVector.end(), out_it);

	return 0;
}

void loadFile(string file, dictionary &d, int &count) {

	string file_name = file;
	string word = "";
	ifstream in(file_name);

	while (in >> word >> ws) {

		transform(word.begin(), word.end(), word.begin(), ::tolower);

		string tmp = "";
		//tmp.reserve(word.size());

		copy_if(word.begin(), word.end(), back_inserter(tmp), format);

		d[tmp]++;
		count++;
	}
}
bool format(char c) {

	string p = ".,!?:\"();";

	if (find(p.begin(), p.end(), c) != p.end())
		return false;
	return true;
}

bool compare(const entry &e1, const entry &e2)
{
	return (e1.second > e2.second);
}
void display(const entry& e) {

	cout << setw(12) << left << e.first << " " << e.second << endl;
}