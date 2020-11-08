#include <iostream>
#include <vector>
#include <string>
using namespace std;

// virtual functions are not free two run time cost
//1: addtional memory for us to store it in the V table

//2: every time we call vritual function we need to go        
//   through the table to look for what we need

class Entity {

public:

    //virtual functions will allow you to over ride them from other classes
    //Key not never aloow your constuctor or destuctor to call a vritual function bad things will happen
    virtual  std::string GetName() { return "Entity"; };
};

class Player : public Entity {

private:
    string m_name;
public:
    Player(const std::string& name) : m_name(name) {}

    // virtual function in the dervie class should have the word overide, because it makes in nicer for us to read an debug we would now know this is a overriden function derived from base class
    std::string GetName()override { return m_name; };
};

void Display(Entity* en) {

    cout << en->GetName() << endl;
}

int main() {
    std::cout << "Hello World!\n";

    Entity* e = new Entity();
    cout << e->GetName() << endl;

    Player* p = new Player("cherno");
    cout << p->GetName() << endl;

    Entity* entity = p;
    cout << e->GetName() << endl;

    Display(e);
    // if entity isnt declared vitrual then p would just Display entity and not      p's name;
    Display(p);

}