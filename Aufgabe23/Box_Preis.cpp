#include <iostream>
#include <vector>

using namespace std;

class IComponent
{
public:
    virtual ~IComponent() = default;
    virtual unsigned long int get_price() const = 0;
    virtual void add(IComponent *item) = 0;
};

class Product : public IComponent
{
    unsigned long int _price = 0;
public:
    Product(unsigned long int p = 0) : _price{p}
    {

    }

    unsigned long int get_price() const override
    {
        return _price;
    }

    void add(IComponent*) override{};
};

class Box : public IComponent
{
    vector <IComponent*> _contents;
public:
    ~Box()
    {
        for(IComponent* p_item : _contents)
        {
            delete p_item;
        }
        _contents.clear();
    }

    unsigned long int get_price() const override
    {
        unsigned long int total_value = 0;
        for(IComponent* item : _contents)
        {
            total_value += item->get_price();
        }
        return total_value;
    }

    void add (IComponent* p_item) override
    {
        _contents.push_back(p_item);
    }
};


void calculate_price(IComponent *component)
{
    cout << "Preis: " << component->get_price() << endl;
}



int main(int argc, char* argv[]) {

    cout << "Preisermittlung für ein einfaches Produkt: " << endl;
    IComponent *product = new Product(10);
    calculate_price(product);
    cout << endl;

    cout << "Preisermittlung für eine verschachtelte Box: " << endl;
    IComponent *outer_box = new Box;
    IComponent *inner_box_1 = new Box;
    IComponent *product_1 = new Product(10);
    IComponent *product_2 = new Product(5);
    IComponent *product_3 = new Product(4);
    inner_box_1->add(product_1);
    inner_box_1->add(product_2);
    IComponent *inner_box_2 = new Box;
    inner_box_2->add(product_3);
    outer_box->add(inner_box_1);
    outer_box->add(inner_box_2);
    calculate_price(outer_box);
    cout << endl;
    
    cout << "Preisermittlung für eine erweiterte verschachtelte Box: " << endl;
    IComponent *product_4 = new Product(7);
    inner_box_2->add(product_4);
    calculate_price(outer_box);
    cout << endl;

    return 0;
}

