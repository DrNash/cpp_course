#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <string>
#include <cstring>
#include <iterator>

using namespace std;

typedef deque<string> File;

int main(int argc, char **argv) {

	File someFile;

	string buffer;

	while(getline(cin, buffer)) {
		istringstream ss(buffer);
		copy(istream_iterator<string>(ss), istream_iterator<string>(), back_inserter<File>(someFile));
	}

	cout << "File contents with non-const iterator:\n";
	for(File::iterator it = someFile.begin(); it < someFile.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	cout << "File contents with const iterator:\n";
	for(File::const_iterator it = someFile.begin(); it < someFile.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	cout << "Reversed File contents with non-const forward iterators:\n";
	for(File::iterator it = --someFile.end(); it >= someFile.begin(); --it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	cout << "Reversed File contents with const forward iterators:\n";
	for(File::const_iterator it = --someFile.end(); it >= someFile.begin(); --it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	cout << "Reversed File contents with non-const reverse iterators:\n";
	for(File::reverse_iterator it = someFile.rbegin(); it < someFile.rend(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	cout << "Reversed File contents with const reverse iterators:\n";
	for(File::const_reverse_iterator it = someFile.rbegin(); it < someFile.rend(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	cout << "Write every other word reversed\n";
	for(File::const_iterator it = someFile.begin(); it < someFile.end(); it+=2) {
		for(string::const_reverse_iterator sit = (*it).rbegin(); sit < (*it).rend(); ++sit) {
			cout << *sit;
		}
		cout << " ";
	}
	cout << "\n\n";

	File::const_iterator rit = --someFile.end();
	cout << "Write alternating front/back words till middle\n";
	for(File::const_iterator it = someFile.begin();	it <= rit; ++it, --rit) {
		if(it == rit) { cout << *it; } else {
			cout << *it << " " << *rit << " ";
		}
	}
	cout << "\n\n";

	cout << "Using old school cstrings\n";
	char **old_school_array;
	old_school_array = new char*[someFile.size()];
	for(int i = 0; i < someFile.size(); ++i) {
		old_school_array[i] = new char[someFile[i].size()+1];
		strcpy(old_school_array[i], someFile[i].c_str());
	}

	cout << "With non-const char pointers\n";
	for(int i = 0; i < someFile.size(); ++i) {
		for(char * c = old_school_array[i]; *c != '\0'; ++c) {
			cout << *c;
		}
		cout << " ";
	}
	cout << "\n\n";

	cout << "With const char pointers\n";
	for(int i = 0; i < someFile.size(); ++i) {
		for(const char * c = old_school_array[i]; *c != '\0'; ++c) {
			cout << *c;
		}
		cout << " ";
	}
	cout << "\n\n";

	cout << "In reverse with non-const char pointers\n";
	for(int i = (someFile.size())-1; i >=0; --i) {
		for(char * c = old_school_array[i]; *c != '\0'; ++c) {
			cout << *c;
		}
		cout << " ";
	}
	cout << "\n\n";

	cout << "In reverse with const char pointers\n";
	for(int i = (someFile.size())-1; i >=0; --i) {
		for(const char * c = old_school_array[i]; *c != '\0'; ++c) {
			cout << *c;
		}
		cout << " ";
	}
	cout << "\n\n";

	//clean up dynamically allocated stuff
	for(int i = 0; i < someFile.size(); ++i) {
		delete [] old_school_array[i];
	}
	delete [] old_school_array;
}