#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

typedef map<string, int> StrIntMap;




void file_format(ifstream& old, ofstream& next) {
	bool space = false;
	char  in;
	while (old.get(in)) {
		if (space && in == ' ') continue;
		

		space = in == ' ';
		if (in <= 'ß' && in >= 'À') {
			in += -'À' + 'à';
		}
		else if (in != ' ' && !(in >= 'à' && in <= 'ÿ')) continue;

		next << in;
	}
}

void countWords(istream& in, StrIntMap& words) {

	string s;
	while (in >> s) {

		++words[s];

	}

}

void ss(ifstream& in, ofstream& out) {
	char  c;

	while (in.get(c)) {
		if (c == ',') c = ' ';
		out << c;
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "rus");



	ifstream old_in("text3.txt");
	ofstream new_in("text2.txt");
	ifstream a("del.txt");
	ofstream out("out.txt");
	ofstream b("del2.txt");

	file_format(old_in, new_in);
	ss(a, b);
	new_in.close();
	b.close();
	ifstream del("del2.txt");
	ifstream in("text2.txt");

	

	if (!in)
		exit(EXIT_FAILURE);
	StrIntMap w;
	countWords(in, w);

	string s;
	while (del >> s) {
		w.erase(s);
	}

	int count = 0;
	for (StrIntMap::iterator p = w.begin(); p != w.end(); ++p) {
		count++;
		out << p->first << ":" << p->second << endl;
	}

	cout << count << endl;
	in.close();
	out.close();
	old_in.close();
}