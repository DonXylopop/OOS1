
#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

// Hier Exception implementieren
class OutOfStock_E : public exception
{
    string _message;
public:
    OutOfStock_E(string key, size_t requested_amount, size_t stocked_amount)
    {
        _message = "Es sind " + to_string(stocked_amount) + " Artikel vom Typ " + key + " verfügbar. "
                   + "Es können nicht " + to_string(requested_amount) + " Artikel verkauft werden.";
    }

    virtual const char* what() const noexcept override
    {
        return _message.c_str();
    }
};


// Hier Interface implementieren 
class ISubscriber 
{

public:
    virtual void update(string s) = 0;
};

// Hier Klassen Customer und GoldCustomer implementieren
class Customer : public ISubscriber
{
    int _customer_id;
public:
    static int _customer_id_generator;

    Customer()
    {
        _customer_id = ++ _customer_id_generator;
    }

    void update(string s) override
    {
        cout << "Customer " << _customer_id << ": " << s << "\n";
    }
};

class GoldCustomer : public ISubscriber
{
    int _customer_id;
public:
    static int _customer_id_generator;

    GoldCustomer()
    {
        _customer_id = ++ _customer_id_generator;
    }

    void update(string s) override
    {
        cout << "GoldCustomer " << _customer_id << ": " << s << "\n";
    }
};


class Store
{
    list<ISubscriber *> _subscribers;
    map<string, unsigned int> _product_availability{{"iPhone", 0}, {"Galaxy", 5}};
public:
    void subscribe(ISubscriber* sub)
    {
        _subscribers.push_back(sub);
    }

    void unsubscribe(ISubscriber* unsub)
    {
        _subscribers.remove(unsub);
    }

    void notify_subscribers(string key, bool is_available)
    {
        string msg;
        if(is_available)
        {
            msg = "neue Nachricht verfügbar --> Neue Artikel vom Typ " + key +" verfügbar.";
        }else if(!is_available)
        {
            msg = "neue Nachricht verfügbar --> Artikel vom Typ " + key + " nicht mehr verfügbar";
        }

        for (ISubscriber* sub : _subscribers)
        {
            sub->update(msg);
        }
    }

    void update_availability(string key, size_t amount, bool sold = false)
    {
        cout << "Vorrätige Artikel vom Typ " << key << ": " << _product_availability[key] << "\n";
    
        if(!sold)
        {
            cout << "Ausgelieferte ";
            _product_availability[key] += amount;
        }else
        {
            cout << "Verkaufte ";
            _product_availability[key] -= amount;
        }
        cout << "Artikel vom Typ " << key << ": " << amount << "\n";

        cout << "Neuer Bestand: " << _product_availability[key] << "\n";
    }

    void deliver_products(string key, size_t amount)
    {
        bool notify = false;

        if(0 == _product_availability[key])
        {
            notify = true;
        }

        update_availability(key, amount, false);

        if(notify)
        {
            notify_subscribers(key, notify);
        }
    }

    void sell_products(string key, size_t amount)
    {
        if(amount > _product_availability[key])
        {
            throw OutOfStock_E(key, amount, _product_availability[key]);
        }

        update_availability(key, amount, true);

        if(0 == _product_availability[key])
        {
            notify_subscribers(key, false);
        }
    }


};


int Customer::_customer_id_generator = 100;
int GoldCustomer::_customer_id_generator = 0;

void manage_store()
{
    try
    {
        Store *store = new Store;
        ISubscriber *customer_1 = new Customer();
        store->subscribe(customer_1);
        ISubscriber *customer_2 = new GoldCustomer();
        store->subscribe(customer_2);
        ISubscriber *customer_3 = new GoldCustomer();
        store->subscribe(customer_3);
        store->deliver_products("iPhone", 5);
        store->unsubscribe(customer_3);
        store->sell_products("iPhone", 3);
        ISubscriber *customer_4 = new Customer();
        store->subscribe(customer_4);
        store->deliver_products("iPhone", 5);
        store->sell_products("iPhone", 7);
        store->unsubscribe(customer_1);
        ISubscriber *customer_5 = new GoldCustomer();
        store->subscribe(customer_5);
        store->deliver_products("iPhone", 15);
        store->sell_products("Galaxy", 8);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Ein unbekannter Fehler ist aufgetreten." << endl;
    }
}

int main(int argc, char *argv[])
{
    manage_store();
    return 0;
}

