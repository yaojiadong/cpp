#pragma once

#include <string>
class Singleton {

public:
  ~Singleton() { std::cout << "Destructor\n"; }

  // delete copy ctor
  Singleton(Singleton &) = delete;

  // delete copy assignment operator
  Singleton &operator=(const Singleton &) = delete;

  static Singleton &getInstance() {
    static Singleton singleton;
    return singleton;
  }

  void setString(const std::string s) { str = s; }

  std::string getString() { return str; }

private:
  // private ctor
  Singleton(const std::string &s = "Hello\n") : str{s} {
    std::cout << "Constructor\n";
  }

private:
  std::string str;
};
