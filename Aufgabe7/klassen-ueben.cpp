#include <iostream>
#include <string>

class  Customer{
    static int _s_count;
    static int _s_id_generator;
    std::string _name;
    int _age;
    std::string _location;
    double _business_done;      //Umsatz in Euro
    int _transaction_count;
    int _id;                    //Kundennummer abhängig vom generator

public:
    Customer(std::string name = "Mustermann", int age = 33, std::string location = "Muster-Stadt"):_name{name},_age{age},_location{location}
    {
        _business_done = 0.0;
        _transaction_count = 0;
        _id = ++_s_id_generator;
        _s_count++;
    }
    void do_business(double amount){
        _transaction_count++;
        _business_done += amount;
    }
    static int get_s_count(){
        return _s_count;
    }
    void print(){
        std::cout << "Kunde " << _name << " aus " << _location << " (ID = " << _id << ", " << _age << " Jahre) hatte " << _transaction_count;
        std::cout << " Transaktion(en) und " << _business_done << " Euro Umsatz\n";
    }
    ~Customer(){
        _s_count--;
    }
};

    int Customer::_s_count = 0;
    int Customer::_s_id_generator = 0;

int main(int argc, char *argv[]) {
    Customer peter = Customer("Peter", 17, "Stuttgart");
	Customer simon = Customer("Simon", 23, "Heilbronn");
    peter.~Customer();
	Customer micheal = Customer("Michael", 21, "Karlsruhe");
	Customer claudia = Customer("Claudia", 30, "Nagold");
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	simon.do_business(230);
	simon.do_business(400);
	claudia.do_business(1000);
	micheal.do_business(199);
	simon.do_business(3.99);
	simon.print();
	micheal.print();
	claudia.print();
    claudia.~Customer();
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	return 0;
}
