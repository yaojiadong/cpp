/*
 * Entry.h
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#ifndef UNION_ENTRY_H_
#define UNION_ENTRY_H_

#include <string>
#include <iostream>
using namespace std;

class Tagged_union{
public:
	struct Bad_entry{void what(){cout << "Bad Entry\n";}}; //used for exception

	string name;

	Tagged_union();
	~Tagged_union();
	Tagged_union& operator=(const Tagged_union&);  //copy assignment
	Tagged_union(const Tagged_union&);				//copy ctor

	int number() const;
	string text() const;

	void set_number(int n);
	void set_text(const string&);

private:
	enum class Tag{number, text};
	Tag type;
	union { //anonymous
		int i;
		string s;
	};

};


#endif /* UNION_ENTRY_H_ */
