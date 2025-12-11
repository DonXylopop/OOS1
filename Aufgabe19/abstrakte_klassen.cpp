#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

class Meal {
protected:
    string _food_name;
    vector<string> _topping;
public:
    Meal(string food_name = " "): _food_name{food_name}
    {
    }
    virtual ~Meal(){};

    void virtual prepare(){
        for(unsigned int i = 0; i < _topping.size(); i++){
            cout << "- " << _topping.at(i) << "\n";
        }
    }

    void virtual add_topping(string topping){
        _topping.push_back(topping); 
    }

};

class Pizza : public Meal{
public:
    Pizza(string food_name)
    {
        _food_name = food_name;
    }

    void prepare() override{
        cout << "Pizza " << _food_name << ". Pizzaboden, belegt mit:\n";
        Meal::prepare();
    }
};

class Burger : public Meal{
public:
    Burger(string food_name)
    {
        _food_name = food_name;
    }

    void prepare() override{
        cout << _food_name << ". Brötchen mit:\n";
        Meal::prepare();
    }
};




int main(int argc, char* argv[])
{
    Pizza *mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal *hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger *hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal *cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
    for (Meal *g : menu)
    {
        g->prepare(); //*[1]
    }
    return 0;
}

 