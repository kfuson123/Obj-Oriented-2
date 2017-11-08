#pragma once

#include <stdexcept>
#include <iostream>


/// An expression is defined by the following set.
///
/// e ::= 0 | 1 | 2 | ... | n -- integers
///       e1 + e2             -- addition
///       e1 - e2             -- subtraction
///       e1 * e2             -- multiplication
///       e1 / e2             -- division
///       -e1                 -- negation
///
/// This is the base class of all supported expressions.
struct Expr
{
  virtual ~Expr() = default;

  // Prints the expression.
  virtual void print(std::ostream& os) const = 0;

  // Returns the value of an expression.
  virtual int evaluate() const = 0;

  // Performs a single-step reduction, producing a new expression.
  // For example, here is a sequence of reductions.
  //
  // (5 * 2) + (3 * 4) -- original
  // 10 + (3 * 4)      -- after 1 reduce()
  // 10 + 12           -- after 2 reduce()s
  // 22                -- after 3 reduce()s
  virtual Expr* reduce() const = 0;

  // Returns true if this is a value (i.e., fully reduced).
  // This returns false by default. Authors of derived must
  // override this to return true if their class is in fact
  // a value.
  //
  // This lets me extend the hierarchy non-intrusively. I
  // don't have to modify this class to add new values.
  virtual bool is_value() const {
    
    const Int* p = dynamic_cast<const Int*>(this);

    return false;
  }

  virtual void to_java(std::ostream& os) const = 0;

  // // As an alternative...
  // //
  // // Adding a new value means that we to modify this definition
  // // each time we add a new value class.
  // //
  // // This also invokes a special case. Normally, prefer to write
  // // operations in terms of the interface. Write algorithms in
  // // terms of static types.
  // bool is_value() const {
  //   // const Expr* this = ...
  //   const Int* p = dynamic_cast<const Int*>(this):    
  //   return p;

  //   // const Real* q = dynamic_cast<const Real*>(this):    
  //   // return p || q;
  // }
};

/// Represents the expressions 0, 1, 2, ..., n.
struct Int : Expr
{
  Int(int n)
    : val(n)
  { }

  void print(std::ostream& os) const override {
    os << val;
  }

  /// The value of n is n.
  int evaluate() const override { 
    return val; 
  }

  Expr* reduce() const override { 
    throw std::runtime_error("already reduced");
  }

  bool is_value() const override { return true; }
  
  int val;
};

/// Represents the set of expressions e1 @ e2 where @
/// is one of the operators +, -, *, /. The kind of
/// operator is determined by a derived class.
///
/// In our previous implementation, the members and
/// constructor appeared in each of the derived classes.
/// Because they all shared common properties and methods,
/// we *factored* or *lift* the common parts into a new 
/// base class: this one.
struct Binary : Expr
{
  Binary(Expr* e1, Expr* e2)
    : e1(e1), e2(e2)
  { }

  ~Binary() override {
    delete e1;
    delete e2;
  }

  static void print_enclosed(std::ostream& os, const Expr *e)
  {
    os << '('; 
    e->print(os); 
    os << ')';
  }
  // Don't need to do this just make the expr function return false.
  // bool is_value() const override { return false; }

  Expr* e1; 
  Expr* e2;
};

/// Represents the expressions e1 + e2.
struct Add : Binary
{
  using Binary::Binary;

  void print(std::ostream& os) const override {
    print_enclosed(os, e1);
    os << " + ";
    print_enclosed(os, e2);
  }

  // The value of e1 + e2 is the sum of the value of e1 and e2.
  int evaluate() const override {
    return e1->evaluate() + e2->evaluate();
  }

  /// Reduces e1 + e2. 
  Expr* reduce() const override {
    if (e1->is_value()) {
      if (e2->is_value()) // v1 + v2
        return new Int(evaluate());

      // v1 + e2
      return new Add(e1, e2->reduce());
    }

    // e1 + e2
    return new Add(e1->reduce(), e2);
  }
};

/// Represents the expressions e1 - e2.
struct Sub : Binary
{
  using Binary::Binary;

  void print(std::ostream& os) const override {
    print_enclosed(os, e1);
    os << " - ";
    print_enclosed(os, e2);
  }

  int evaluate() const override {
    return e1->evaluate() - e2->evaluate();
  }

  /// Reduces e1 - e2. 
  Expr* reduce() const override {
    if (e1->is_value()) {
      if (e2->is_value()) // v1 - v2
        return new Int(evaluate());

      // v1 - e2
      return new Sub(e1, e2->reduce());
    }

    // e1 - e2
    return new Sub(e1->reduce(), e2);
  }
};

/// Represents the expressions e1 * e2.
struct Mul : Binary
{
  using Binary::Binary;

  void print(std::ostream& os) const override {
    print_enclosed(os, e1);
    os << " * ";
    print_enclosed(os, e2);
  }

  int evaluate() const override {
    return e1->evaluate() * e2->evaluate();
  }

  /// Reduces e1 * e2. 
  Expr* reduce() const override {
    if (e1->is_value()) {
      if (e2->is_value()) // v1 * v2
        return new Int(evaluate());

      // v1 * e2
      return new Mul(e1, e2->reduce());
    }

    // e1 * e2
    return new Mul(e1->reduce(), e2);
  }
};

/// Represents the expressions e1 / e2.
struct Div : Binary
{
  using Binary::Binary;
  
  void print(std::ostream& os) const override {
    print_enclosed(os, e1);
    os << " / ";
    print_enclosed(os, e2);
  }

  /// Returns the value of e1 / e2 unless e2 == 0.
  int evaluate() const override {
    int d = e2->evaluate();
    if (d == 0)
      throw std::runtime_error("division by 0");
    return e1->evaluate() / d;
  }

  /// Reduces e1 / e2. 
  Expr* reduce() const override {
    if (e1->is_value()) {
      if (e2->is_value()) // v1 / v2
        return new Int(evaluate());

      // v1 / e2
      return new Div(e1, e2->reduce());
    }

    // e1 / e2
    return new Div(e1->reduce(), e2);
  }
};

/// Represents the expressions -e1.
struct Neg : Expr
{
  Neg(Expr* e)
    : e1(e)
  { }

  ~Neg() override {
    delete e1;
  }

  void print(std::ostream& os) const override {
  }

  int evaluate() const override {
    return -e1->evaluate();
  }

  Expr* reduce() const override {
    throw std::logic_error("not implemented");
  }

  Expr* e1;
};
