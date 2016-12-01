#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

void dump(list<string> &l)
{
	list<string>::iterator iter = l.begin();

	while (iter != l.end())
	{
		cout << *iter << endl;
		iter++;
	}
}

class Word
{
private:
	string word;
public:
	Word(string word)
	{
		this->word = word;
	}
	string getWord()
	{
		return this->word;
	}
};

void main()
{
	/*vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.insert(v.begin(), 40);
	v.insert(v.end(), 50);
	for (int i = 0; i < v.size(); i++)
	{
	cout << v[i] << endl;
	}

	cout << "access index at 1 : " << v.at(1) << endl;

	v.erase(v.begin());
	v.erase(v.end() - 1);

	vector<int>::iterator iter = v.begin();
	cout << "access index at 1 with iterator : " << iter[1] << endl;
	while (iter != v.end())
	{
	cout << *iter << endl;
	iter++;
	}
	*/

	/*list<string> names;
	names.insert(names.begin(), "Konkuk");
	names.insert(names.end(), "University");
	names.insert(names.end(), "SCLAB");
	names.insert(names.end(), "CSY");
	dump(names);
	cout << "===" << endl;
	names.reverse();
	dump(names);*/

	/*map<string, int> m;
	m["seoul"] = 100;
	m["daegu"] = 120;
	m["busan"] = 200;
	cout << "Train to Seoul = " << m["seoul"] << "$" << endl;
	cout << "Train to Daegu = " << m["daegu"] << "$" << endl;
	cout << "Train to Busan = " << m["busan"] << "$" << endl;*/

	map<char, list<Word>> m;
	list<Word> alist;
	list<Word> blist;

	alist.push_back(Word("apple"));
	alist.push_back(Word("avoid"));
	alist.push_back(Word("appear"));

	blist.push_back(Word("bread"));
	blist.push_back(Word("bring"));
	blist.push_back(Word("bow"));

	m['a'] = alist;
	m['b'] = blist;

	map<char, list<Word>>::iterator iter = m.begin();

	while (iter != m.end())
	{
		cout << iter->first << ":" << endl;
		list<Word> temp = iter->second;
		list<Word>::const_iterator iter_list = temp.begin();

		while (iter_list != temp.end())
		{
			Word word = *iter_list;
			cout << word.getWord() << ", ";
			iter_list++;
		}
		cout << "\n===" << endl;
		iter++;
	}

}