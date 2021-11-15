/*
 * Tagged_union.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: jiado
 */

#include "Tagged_union.h"

int Tagged_union::number() const {
  if (type != Tag::number)
    throw Bad_entry{};
  return i;
}

string Tagged_union::text() const {
  if (type != Tag::text)
    throw Bad_entry{};
  return s;
}

void Tagged_union::set_number(int n) {
  if (type == Tag::text) {
    s.~string();
    type = Tag::number;
  }
  i = n;
}

void Tagged_union::set_text(const string &ss) {
  if (type == Tag::text) {
    s = ss;
  } else {
    new (&s) string(ss); // placement new: explicit construct
    type = Tag::text;
  }
}

Tagged_union &Tagged_union::operator=(
    const Tagged_union &t) { // necessary because of the string variant
  cout << "Copy assignment is called\n";
  if (type == Tag::number) {
    if (t.type == Tag::number) {
      i = t.i;
    } else {
      new (&s) string(t.s); // placement new: explicit construct
      type = t.type;
    }
  } else {
    if (t.type == Tag::number) {
      s.~string();
      i = t.i;
    } else {
      s = t.s;
    }
  }
  return *this;
}

Tagged_union::Tagged_union() {
  cout << "ctor is called\n";
  //	type = Tag::number;
  //	i = 5;
  type = Tag::text;
  new (&s) string();
}

Tagged_union::Tagged_union(const Tagged_union &t) {
  cout << "Copy ctor is called\n";

  if (t.type == Tag::number) {
    i = t.i;
  } else {
    new (&s) string(t.s); // placement new: explicit construct
  }
  type = t.type;
}

Tagged_union::~Tagged_union() {
  if (type == Tag::text)
    s.~string(); // explicit destroy
}
