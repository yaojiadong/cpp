#pragma once
#include <iostream>

/* Note that the template parameter is the return type for arithmetic
 * evaluation. Basically it is an integer. This Element is intended to be used
 * for evaluating arithmetic expression.*/
template <typename R> class Element {
public:
  Element(std::string e = std::string{}) : element{e} {}

  Element(const Element &e) { this->element = e.element; }

  Element(Element &&e) noexcept { this->element = std::move(e.element); }

  Element &operator=(Element e) {
    std::swap(this->element, e.element);
    return *this;
  }

  R value() {
    if (!is_operator())
      return std::atoi(element.c_str());

    throw std::runtime_error("Element is an operator, has no value.");
  }

  R operator()(const R &left, const R &right) const {
    if (element.compare("+") == 0) {
      return left + right;
    }
    if (element.compare("-") == 0) {
      return left - right;
    }
    if (element.compare("*") == 0) {
      return left * right;
    }
    if (element.compare("/") == 0) {
      return left / right;
    }
    throw std::runtime_error("Element is not an operator");
  }

  R operation(const R &left, const R &right) const {
    if (element.compare("+") == 0) {
      return left + right;
    }
    if (element.compare("-") == 0) {
      return left - right;
    }
    if (element.compare("*") == 0) {
      return left * right;
    }
    if (element.compare("/") == 0) {
      return left / right;
    }
    throw std::runtime_error("Element is not an operator");
  }

  bool is_operator() const {
    if (element.size() != 1) {
      return false;
    } else {
      if (element.compare("+") == 0 || element.compare("-") == 0 ||
          element.compare("*") == 0 || element.compare("/") == 0) {
        return true;
      } else {
        return false;
      }
    }
  }

private:
  std::string element;
};