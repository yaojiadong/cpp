#pragma once

#include <iostream>
template <typename T, typename R, typename E> class Euler_tour {

protected:
  struct Result {
    R left_result;
    R right_result;
    R final_result;
  };
  using Pos = typename T::Position;

public:
  // void initialize(const T &t) { tree = &t; } // not needed

protected:
  R template_euler_tour(const Pos &p) const {
    Result r = init_result();
    if (p.is_external()) {
      visit_external(p, r);
    } else {
      visit_left(p, r);
      r.left_result = template_euler_tour(p.left());
      visit_below(p, r);
      r.right_result = template_euler_tour(p.right());
      visit_right(p, r);
    }
    return result(r);
  }
  Result init_result() const { return Result(); }
  virtual void visit_external(const Pos &p, Result &r) const {}
  virtual void visit_left(const Pos &p, Result &r) const {}
  virtual void visit_below(const Pos &p, Result &r) const {}
  virtual void visit_right(const Pos &p, Result &r) const {}
  R result(const Result &r) const { return r.final_result; }

protected:
  // const T *tree = nullptr; //not needed, since it is not used.
};

/* The third type E must have some additional functionalities as needed in two
 * member functions. We created a Element type to accomplish it.*/
template <typename T, typename R, typename E>
class Evaluate_expression : public Euler_tour<T, R, E> {

protected:
  using typename Euler_tour<T, R, E>::Result;
  using typename Euler_tour<T, R, E>::Pos;
  // need define value() for the element
  virtual void visit_external(const Pos &p, Result &r) const override {
    r.final_result = (*p).value();
  }
  // need define operation() for the element
  virtual void visit_right(const Pos &p, Result &r) const override {
    r.final_result = (*p).operation(r.left_result, r.right_result);
  }

public:
  void execute(const T &t) {
    // initialize(t);
    message("The evaluated result is ", this->template_euler_tour(t.root()));
  }
};

/* The only requirement for the element is that it has operator<<() defined.*/
template <typename T, typename R, typename E>
class Print_exression : public Euler_tour<T, R, E> {
protected:
  using typename Euler_tour<T, R, E>::Result;
  using typename Euler_tour<T, R, E>::Pos;

public:
  void execute(const T &t) {
    // initialize(t);
    this->template_euler_tour(t.root());
  }

  virtual void visit_external(const Pos &p, Result &r) const override {
    std::cout << *p; // need define operator<< for the element
  }
  virtual void visit_left(const Pos &p, Result &r) const override {
    std::cout << "(";
  }
  virtual void visit_below(const Pos &p, Result &r) const override {
    std::cout << *p; // need define operator<< for the element
  }
  virtual void visit_right(const Pos &p, Result &r) const override {
    std::cout << ")";
  }
};