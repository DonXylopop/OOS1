
#include <string>
#include <iostream>
using namespace std;

class Person {
	string _name;
	int _check_out_duration;
public:
	Person(string name, int check_out_duration = 0) : _name{name}, _check_out_duration{check_out_duration}
    {

    };
	int get_check_out_duration() const{
        return _check_out_duration;
    };
	void print() const{
        cout << _name << ", ";
    };
};

// Implmentierung des Konstruktors und der Methoden

class Lecturer : public Person
{
	int _examiner_id;
public:
	Lecturer(string name, int examiner_id): Person(name, 90), _examiner_id{examiner_id}
    {

    };
	void print() const{
        Person::print();
        cout << "Prüfernummer " << _examiner_id << "\n";
    };
};

// Implmentierung des Konstruktors und der Methoden

class Student : public Person
{
	int _matriculation_number;

public:
	Student(string name, int matriculation_number) : Person(name, 30), _matriculation_number{matriculation_number}
    {

    };
	void print() const{
        Person::print();
        cout << "Matrikelnummer " << _matriculation_number << "\n";
    };
};


// Implmentierung des Konstruktors und der Methoden

int main(int argc, char *argv[]) {
    Student smith = Student("smith", 12345678);
    Lecturer miller = Lecturer("miller", 98);
    smith.print();
    cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
    miller.print();
    cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}

