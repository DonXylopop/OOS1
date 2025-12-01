#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IPrinter{
public:
    virtual string info() = 0;
    virtual void print(string text) = 0;
    virtual void set_ip_address(string ip_address) = 0;
};

class Printer : public IPrinter{
    string _ip_address;
public:
    string info() override {
        return "Printer, ip: " + _ip_address;
    }
    void print(string text) override{
        cout << "Es wird tatsächlich auf Papier gedruckt: " << text << "\n";
    }
    void set_ip_address(string ip_address) override{
        _ip_address = ip_address;
    }
};

class DummyPrinter : public IPrinter{
    string _ip_address;
public:
    string info() override {
        return "Printer, ip: " + _ip_address;
    }
    void print(string text) override{
        cout << "Es wird NICHT auf Papier gedruckt: " << text << "\n";
    }
    void set_ip_address(string ip_address) override{
        _ip_address = ip_address;
    }
};

class PrintClient{
    IPrinter* _printer;
public:
    PrintClient(IPrinter* printer){
        _printer = printer;
        _printer->set_ip_address("192.168.0.100");
    }
    void set_printer(IPrinter* printer){
        _printer = printer;
    }
    void execute(){
        _printer->print("Mein Text");
    }
};

int main(){
    PrintClient client(new DummyPrinter);

    
    client.execute();

    return 0;
}