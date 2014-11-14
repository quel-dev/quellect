#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    Node(){}
    virtual const string& getname() const {
      return name;
    }
  protected:
    name;
};

class Derive :public Node {
  public:
    Derive(){}
    virtual const string& getname() const;
  protected:
};

int main (){
  Node* node = new Derive();
  cout<<node->getname();
  return 0; 
}
