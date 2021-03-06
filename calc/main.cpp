#include "calc.hpp"

#include <iostream>

std::ostream&
operator<<(std::ostream& os, const Expr* e)
{
  e->print(os);
  return os;
}

int
main() {
  // (5 / 2) * (4 + 2)
  Expr* e = new Mul(
    new Div(new Int(5), new Int(2)),
    new Add(new Int(4), new Int(2))
  );

  std::cout << e << " == " << e->evaluate() << '\n';


  delete e;
}
