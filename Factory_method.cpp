#include <iostream>
#include <string>

using namespace std;

class ITransport
{
public:
    virtual void deliver() = 0;

};

class Truck : public ITransport
{
public:
    void deliver() override
    {
        cout << "deliver by land in a box\n";
    }
};

class Ship : public ITransport
{
public:
    void deliver() override
    {
        cout << "deliver by sea in a container\n";
    }
};

class ILogistics
{
public:
    void plan_delivery() const
    {
        cout << "ILogistics: The same ILogistics's code managed to ";
        ITransport* t = create_transport();
        t->deliver();
    }
    virtual ITransport* create_transport() const = 0;
};

class RoadLogistics : public ILogistics
{
public:
    ITransport* create_transport() const override
    {
        return new Truck();
    }
};

class SeaLogistics : public ILogistics
{
public:
    ITransport* create_transport() const override
    {
        return new Ship();
    }
};



void ClientCode(const ILogistics& ILogistics) 
{
    cout << "Client: I'm not aware of the ILogistics's class, but it still works. "
    << std::endl;
    ILogistics.plan_delivery();
}
/**
* The Application picks a ILogistics's type depending on the configuration or
* environment.
*/
int main() 
{
    cout << "App: Launched with the RoadLogistics.\n";
    ILogistics* road_logistics = new RoadLogistics();
    ClientCode(*road_logistics);
    cout << std::endl;
    cout << "App: Launched with the SeaLogistics.\n";
    ILogistics* sea_logistics = new SeaLogistics();
    ClientCode(*sea_logistics);
    delete road_logistics;
    delete sea_logistics;
    return 0;
}