#pragma once

#include <stdexcept>
#include <iostream>


struct Expr;
struct Int;
struct Add;
struct Sub;
struct Mul;
struct Div;

struct Expr
{
  virtual ~Expr() = default;
  virtual void print(std::ostream& os) const = 0;
  virtual int evaluate() const = 0;
  virtual Expr* clone() const = 0;
};

struct Int : Expr
{
  Int(int n)
    : val(n)
  { }

  Int* clone() const override {
    return new Int(*this);
  }

  void print(std::ostream& os) const override {
    os << val;
  }

  int evaluate() const override {
    return val;
  }

  int val;
};


struct Binary : Expr
{
  Binary(const Binary& that)
    : e1(that.e1->clone()), e2(that.e2->clone())
  { }

  Binary(Expr *e1, Expr* e2)
    : e1(e1), e2(e2)
  { }

  ~Binary() override {
    delete e1;
    delete e2;
  }

  static void print_enclosed(std::ostream& os, const Expr* e) {
    os << '(';
    e->print(os);
    os << ')';
  }

  Expr* e1;
  Expr* e2;
};

struct Add : Binary
{
  using Binary::Binary;

  Add* clone() const override {
    return new Add(*this);
  }

  void print(std::ostream& os) const override {
    print_enclosed(os, e1);
    os << " + ";
    print_enclosed(os, e2);
  }

  int evaluate() const override {
    return e1->evaluate() + e2->evaluate();
  }


};

struct Sub : Binary
{
  using Binary::Binary;

  Sub* clone() const override {
    return new Sub(*this);
  }

  // Prints the expression e1 - e2.
  void print(std::ostream& os) const override {
    print_enclosed(os, e1);
    os << " - ";
    print_enclosed(os, e2);
  }

  int evaluate() const override {
    return e1->evaluate() - e2->evaluate();
  }

};

struct Mul : Binary
{
  using Binary::Binary;

  Mul* clone() const override {
    return new Mul(*this);
  }

  // Prints the expression e1 * e2.
  void print(std::ostream& os) const override {
    print_enclosed(os, e1);
    os << " * ";
    print_enclosed(os, e2);
  }

  int evaluate() const override {
    return e1->evaluate() * e2->evaluate();
  }

};

struct Div : Binary
{
  using Binary::Binary;

  Div* clone() const override {
    return new Div(*this);
  }

  void print(std::ostream& os) const override {
    print_enclosed(os, e1);
    os << " / ";
    print_enclosed(os, e2);
  }


  int evaluate() const override {
    int d = e2->evaluate();
    if (d == 0)
      throw std::runtime_error("division by zero");
    return e1->evaluate() / d;
  }

};


