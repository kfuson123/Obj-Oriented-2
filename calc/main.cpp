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

  // 3 * (4 + 2)
  Expr* e = new Mul(
    new Int(3),
    new Add(
      new Int(4),
      new Int(2)
    )
  );

  std::cout << e << " == " << e->evaluate() << '\n';

  while (!e->is_value()) {
    e = e->reduce();
    std::cout << e << '\n';
  }

  // std::cout << e->reduce() << '\n';
  // std::cout << e->reduce()->reduce() << '\n';

  delete e;

  return 0;
}
