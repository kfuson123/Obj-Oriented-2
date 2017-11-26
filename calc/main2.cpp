#include "calc.hpp"

#include <iostream>

std::ostream&
operator<<(std::ostream& os, const Expr* e)
{
  return os;
}

int
main() {
  // (5 / 2) * (4 + 2)
  Expr* e = new Mul(
    new Div(new Int(5), new Int(2)),
    new Add(new Int(4), new Int(2))
  );

  EvalVisitor v;
  e->accept(v);
  std::cout << v.ret << '\n';

  std::cout << eval(e) << '\n';
}
