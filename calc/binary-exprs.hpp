#pragma once


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

  virtual int evaluate() const;
};

/// Represents the expressions 0, 1, 2, ..., n.
struct Int : Expr
{
  Int(int n)
    : val(n)
  { }
  
  int val;
};

enum Op {
  AddOp,
  SubOp,
  MulOp,
  DivOp,
};

/// Represents e1 @ e2 where @ is one of the ops above.
struct Binary : Expr
{
  Binary(Op op, Expr* e1, Expr* e2)
    : op(op), e1(e1), e2(e2)
  { }

  Op op;
  Expr* e1; 
  Expr* e2;
};

// You don't need most derived classes.

// /// Represents the expressions e1 + e2.
// struct Add : Binary
// {
//   Add(Expr* e1, Expr* e)
//     : Binary(AddOp, e1, e2)
//   { }
// };

// /// Represents the expressions e1 - e2.
// struct Sub : Binary
// {
//   using Binary::Binary;
// };

// /// Represents the expressions e1 * e2.
// struct Mul : Binary
// {
//   using Binary::Binary;
// };

// /// Represents the expressions e1 / e2.
// struct Div : Binary
// {
//   using Binary::Binary;
// };

/// Represents the expressions -e1.
struct Neg : Expr
{
  Neg(Expr* e)
    : e1(e)
  { }

  Expr* e1;
};


