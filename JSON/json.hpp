#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct Value
{
  virtual ~Value() { }

  virtual void print() const = 0;
};

// Represents null
struct Null : Value
{
  Null()
  { }

  void print() const {
    std::cout << "null";
  }
};

//Represents true or false
struct Bool : Value
{
  Bool(bool b)
    : val(b)
  { }

  void print() const {
    if (val)
      std::cout << "true";
    else
      std::cout << "false";
  }

  bool val;
};

//Represents number values
struct Number : Value
{
  Number(double d)
    : val(d)
  { }

  void print() const override {
    std::cout << val;
  }

  double val;
};

/// Represents string values.
struct String : Value
{
  String(const std::string& s)
    : str(s)
  { }

  void print() const {
    std::cout << str;
  }

  std::string str;
};

/// Recursive part of data structure.
struct Array : Value
{

  Array() = default;


  Array(std::initializer_list<Value*> list)
    : vals(list)
  { }

  ~Array() override {
    for (Value* v : vals)
      delete v;
  }

  void add(Value* v) {
    vals.push_back(v);
  }

  void print() const override {
    std::cout << '[';
    for (auto iter = vals.begin(); iter != vals.end(); ++iter) {
      (*iter)->print();
      if (std::next(iter) != vals.end())
        std::cout << ", ";
    }
    std::cout << "]";
  }

  std::vector<Value*> vals;
};

struct Object : Value
{
  Object() = default;

  ~Object() {
    for (auto p : fields) {
      delete p.first;
      delete p.second;
    }
  }

  void print() const override {
    std::cout << '{';
    for (auto iter = fields.begin(); iter != fields.end(); ++iter) {
      iter->first->print();
      std::cout << " : ";
      iter->second->print();
      if (std::next(iter) != fields.end())
        std::cout << ", ";
    }
    std::cout << "}";
  }

  void add(String* k, Value* v) {
    fields.emplace(k, v);
  }
};





