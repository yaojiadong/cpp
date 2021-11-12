#pragma once

#include <string>
class Singleton_v2 {

public:
  ~Singleton_v2() { std::cout << "Destructor\n"; }

  Singleton_v2(Singleton_v2 &) = delete;

  Singleton_v2 &operator=(const Singleton_v2 &) = delete;

  static Singleton_v2 &getInstance() {
    if (instance == nullptr) {
      instance = new Singleton_v2();
    }
    return instance;
  }

  void setString(const std::string s) { str = s; }

  std::string getString() { return str; }

private:
  Singleton_v2(const std::string &s = "Hello\n") : str{s} {
    std::cout << "Constructor\n";
  }

private:
  std::string str;
  static Singleton_v2 *instance;
};

Singleton_v2 *Singleton_v2::instance = nullptr;