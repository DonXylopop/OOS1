#include<string>
#include<iostream>
using namespace std;

class Engine 
{
public:
    void start() 
    {
        cout << "Engine started" << endl;
    }
};

class Radio 
{
    string _channel;
public:
    void start()
    {
        cout << "Radio started" << endl;
    }
    void set_channel(string channel) 
    {
        _channel = channel;
        cout << "Channel set to " << channel
        << "." << endl;
    }
};

class Climatisation 
{
    int _temperature;
public:
    void start() 
    {
        cout << "Climatisation started" << endl;
    }
    void set_temperature(int temperature) 
    {
        _temperature = temperature;
        cout << "Temperature set to "
        << _temperature << "." << endl;
    }

};

class Headlights
{
public:
    void turn_on() 
    {
        cout << "Headlights on" << endl;
    }
};

class Car
{
    Engine engine;
    Radio radio;
    Climatisation climatisation;
    Headlights headlights;
public:
    void turn_ignition_key_on()
    {
        headlights.turn_on();
        engine.start();
        radio.start();
        radio.set_channel("SWR3");
        climatisation.start();
        climatisation.set_temperature(20);
    }
};


int main(int argc, char *argv[])
{
// Consuming facade.
    Car car;
    car.turn_ignition_key_on();
    return 0;
}