#include<iostream>
using namespace std;

// Interface
class IAnimal 
{
public:
    virtual void make_sound () const = 0;
};

// Implementierung
class Dog: public IAnimal 
{
public:
    void make_sound() const override 
    {
        cout << "Wau" << endl;
    }
};

class ProxyDog : public IAnimal
{
    Dog _dog;

public:
    void make_sound() const override
    {
        if(check())
        {
            _dog.make_sound();
        }
    }

    bool check() const
    {
        cout << "Überprüfung\n";
        return true;
    }
};

int main() 
{
IAnimal* p_dog = new ProxyDog();
p_dog->make_sound();

return 0;
}