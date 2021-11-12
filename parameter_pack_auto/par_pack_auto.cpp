/*
 * par_pack_auto.cpp
 *
 *  Created on: Jan 20, 2021
 *      Author: jiadong
 */

/* non-type template parameters of class type
 * only available with '-std=c++2a' or '-std=gnu++2a'
 */

#include <iostream>

using namespace std;

/*********************single parameter template*******************************/

/*
 * non-type template parameter.
 * template parameter is not a type but a value.
 * type is deduced on the template arguments, not function arguments
 * */
template <auto seq> struct my_integer_sequence {
  using type = decltype(seq);
  void fun(type arg) { cout << seq + arg << endl; }
};

/*
 * Non-type template parameter,
 * Arg is an object and Arg() can be called.
 * */
template <auto Arg> void single_par_auto() {
  Arg(); // when  auto Arg, Arg is value, Arg() is OK
}

/*
 * Non-type template parameter,
 * Arg is an object and Arg() can be called.
 * */
template <auto Arg> void single_par_auto_primitive() {
  // Arg(); // when  auto Arg, Arg is value, Arg() is OK
}

/*
 * typed template parameter
 * args is an object of type Arg. args() can be called.
 * */
template <class Arg> void single_par_typed(Arg args) { args(); }

/*********************template parameter pack*******************************/

/*
 * non-type template parameter pack expansion with auto.
 * template parameter is not a type but a value.
 * type is deduced on the template arguments, not function arguments
 * */
template <auto Arg, auto... Args> void doPrint1() {
  cout << Arg;
  ((cout << "," << Args), ...);
  cout << '\n';
}

/*
 * IMPORTANT: non-type template parameter pack expansion with auto.
 * Arg is an object. Iterate over the parameter pack to execute all the objects.
 * */
template <auto Arg, auto... Args> void doPrint2() {
  Arg();
  (Args(), ...); //(e op ...), where e is Arg(), folder operator is "," and ...
                 // is parameter pack
}

/*
 * IMPORTANT!!!
 * The same as doPrint2().
 * Compare it with exe_in_one_fun(T t, Rest... rest) with typed template
 * parameter
 * */
template <auto... Args> void doPrint3() { (Args(), ...); }

/*
 * typed parameter pack expansion without recursion
 * In c++17 using fold expressions:
 * type is deduced on the function arguments
 */

template <typename Arg, typename... Args>
void doPrint(std::ostream &out, Arg &&arg, Args &&...args) {
  out << std::forward<Arg>(arg);
  ((out << ',' << std::forward<Args>(args)), ...);
}

/*
 * IMPORTANT: A non-const reference parameter, such as an int&,
 * can only refer to an "lvalue," which is a named variable.
 * Without const, function call will pass int rvalue to Arg& arg,
 * Arg is deduced to int& and arg is lvalue
 *
 * Another solution seen above, use rvalue
 * */
template <typename Arg, typename... Args>
void doPrint(std::ostream &out, const Arg &arg, Args &&...args) {
  out << arg;
  ((out << ',' << args), ...);
}

/*
 * typed parameter pack expansion recursive execution
 */
template <class T> void exe(T t) { t(); }

template <class T, class... Rest> void exe(T t, Rest... rest) {
  exe(t);
  exe(rest...);
}

/*
 * typed parameter pack can be executed in one function. c++17
 * constexpr if: code that is instantiated depending on a compile-time
 * condition. Without constexpr, the sizeof... is not evaluated at compile time
 * It is possible that size 0 of the parameter pack could be passed to the
 * function, but no matching function found. So it has to be evaluated at
 * compile time.
 * */
template <class T, class... Rest> void exe_in_one_fun(T t, Rest... rest) {
  t();
  if constexpr (sizeof...(rest) > 0) { // operator: sizeof...
    exe_in_one_fun(rest...);
  }
}

class print1 {

public:
  void operator()() { cout << "printing 1..." << endl; }
};

class print2 {

public:
  void operator()() { cout << "printing 2..." << endl; }
};

/*
 * iterate over initializer list
 * */

template <class T> void init_list_iterate(std::initializer_list<T> list) {
  for (auto a : list) {
    a();
  }
}

void test_par_pack_auto() {

  /*********************single parameter
   * template*******************************/

  auto p = []() { cout << "printing lambda p..." << endl; };
  auto q = []() { cout << "printing lambda q..." << endl; };

  // testing non-type template parameter
  auto seq2 = my_integer_sequence<1>();
  seq2.fun(5);

  // testing: the type is a class, not plain in, char...

  // non-typed parameter, p is a lambda to be executed, not plain int, char...
  // single_par_auto<p>(); // compile error in VS, but compiled with -std=c++2a
  // on Ubuntu

  // non-typed parameter, with primitive type
  single_par_auto_primitive<3>();

  // typed parameter
  single_par_typed(p);

  /*********************template parameter pack*******************************/

  // testing non-typed parameter pack expansion
  doPrint1<1, 2, 'a'>(); // string literals cannot be used in this context

  // same compile error as single_par_auto<p>(); but compiled with -std=c++2a on
  // Ubuntu
  // doPrint2<p>();

  // same compile error as single_par_auto<p>(); but compiled with -std=c++2a on
  // Ubuntu
  // doPrint3<p, q>();

  // testing typed parameter pack expansion without recursion.
  doPrint(cout, 1, "start print1", "2+2", '\n');
  // doPrint(cout,p);

  // testing the typed parameter pack expansion with recursion
  print1 pp, pp1;
  print2 pp2;
  exe(pp, pp2, p, q);
  exe_in_one_fun(pp, pp2, p, q);

  // pass to initializer list, only accepts the same type
  init_list_iterate({pp, pp1});
}
