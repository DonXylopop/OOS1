#include <iostream>
using namespace std;

#include "Worker.h"
#include "Manager.h"

int main()
{
    Manager m("Melwin", "Lau", 1000.00);
    m.print();
    cout << "Gehalt: " << m.get_income() << endl << endl;
    Worker w("Peter", "Mueller", 15.00, 40);
    w.print();
    cout << "Lohn: " << w.get_income() << endl;
    return 0;
}