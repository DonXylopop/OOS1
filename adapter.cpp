#include <iostream>
using namespace std;

class IAnimal
{
public:
    virtual void make_sound() const = 0;
};

class Dog : public IAnimal
{
public:
    void make_sound() const override
    {
        cout << "Wau" << endl;
    }
};

class ExternalSnake
{
public:
    void make_noise() const
    {
        cout << "Zisch" << endl;
    }
};

class Snake : public IAnimal
{
    ExternalSnake e_snake;
public:
    void make_sound() const override
    {
        e_snake.make_noise();
    }
};

int main()
{
    IAnimal* p_dog = new Dog();
    p_dog->make_sound();

    IAnimal* p_snake = new Snake();
    p_snake->make_sound();
}