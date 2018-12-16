
#include <iostream>
#include <String>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
#include <iomanip>


using namespace std;

typedef map<string, vector<string>> table;
typedef pair<string, vector<string>> entry;

namespace std
{
	ostream& operator<<(ostream& os, const entry &e)
	{
		if (e.second.size() > 1)
		{
			ostream_iterator<string> out_it(os, " ");
			copy(e.second.begin(), e.second.end(), out_it);
			os << " --> " << e.second.size() << " words." << endl;

		}	
		return os;
	}
}


void loadFile(string file, table &d, int &count);

int main() {
	table t;
	int count = 0;
	loadFile("uppgift2/uppgift2.txt", t, count);

	cout << "Number of words = " << count << endl;
	cout << endl << "-- ANAGRAMS --" << endl;

	ostream_iterator<entry> out_it(cout);

	copy(t.begin(), t.end(), out_it);

	return 0;
}

void loadFile(string file, table & t, int & count)
{

	string file_name = file;
	string word = "";
	ifstream in(file_name);
	
	while (in >> word) {

		string tmp = word;
		sort(tmp.begin(), tmp.end());

		t[tmp].push_back(word);

		count++;
	}
}
