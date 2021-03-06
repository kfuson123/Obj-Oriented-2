#include "calc2.hpp"

void
EvalVisitor::visit(Int* e) {
  ret = e->val;
}

void
EvalVisitor::visit(Add* e) {
  EvalVisitor v1;
  e->e1->accept(v1);

  EvalVisitor v2;
  e->e2->accept(v2);

  ret = v1.ret + v2.ret;
}

void
EvalVisitor::visit(Sub* e) {
  EvalVisitor v1;
  e->e1->accept(v1);

  EvalVisitor v2;
  e->e2->accept(v2);

  ret = v1.ret - v2.ret;
}

void
EvalVisitor::visit(Mul* e) {
  EvalVisitor v1;
  e->e1->accept(v1);

  EvalVisitor v2;
  e->e2->accept(v2);

  ret = v1.ret * v2.ret;
}

void
EvalVisitor::visit(Div* e) {
  EvalVisitor v1;
  e->e1->accept(v1);

  EvalVisitor v2;
  e->e2->accept(v2);

  ret = v1.ret / v2.ret;
}


int eval(Expr* e) {
  struct V : Visitor {
    int ret;
    void visit(Int* n) override { ret = n->val; }
    void visit(Add* a) override { ret = eval(a->e1) + eval(a->e2); }
    void visit(Sub* s) override { ret = eval(s->e1) - eval(s->e2); }
    void visit(Mul* m) override { ret = eval(m->e1) * eval(m->e2); }
    void visit(Div* d) override { ret = eval(d->e1) / eval(d->e2); }
  };
  V vis;
  e->accept(vis);
  return vis.ret;
}

