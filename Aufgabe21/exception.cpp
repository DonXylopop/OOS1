
#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
class MyException : public exception 
{
    // HIER
    string _file_name;
    int _line_of_error;
    string _error_message;
    string _full_message;
public:
    MyException(string file, int line, string message) : _file_name{file}, _line_of_error{line}, _error_message{message}
    {
        _full_message = "Fehler '" +_error_message + "' aufgetreten in Datei " + _file_name + ", Zeile: " 
            + to_string(_line_of_error) +".";
    };

    virtual const char* what()
    {
        return _full_message.c_str();
    }

};

// Eigene Exceptionklasse "ElefantMeetsMouse"
// abgeleitet von MyException
class ElefantMeetsMouse : public MyException 
{// HIER {
    // HIER
public:
    ElefantMeetsMouse(string file, int line) : MyException(file, line - 15, "Elefant trifft auf Maus")
    {

    }

};

// Klasse der Tiere
class Animal
{
    // Name des Tiers
    string _name;

public:
    // Konstruktor
    Animal()
    {
        cout << "Bitte Namen des Tieres eingeben: ";
        cin >> _name;
    };

    virtual ~Animal(){}

    // virtuelle print-Funktion
    virtual void print(bool nl = true) const
    {
        cout << _name;
        if (nl)
        {
            cout << endl;
        }
    }

    virtual string is_animal() const = 0;

    virtual Animal *clone() const = 0;
};

// Klasse "Elefant"
// abgeleitet von Animal
class Elefant : public Animal
{
public:
    Elefant() : Animal()
    {

    };

    string is_animal() const override
    {
        return "Elefant";
    }

    Elefant *clone() const override
    {
        return new Elefant(*this);
    }
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger : public Animal
{
public:
    Tiger() : Animal()
    {

    };

    string is_animal() const override
    {
        return "Tiger";
    }

    Tiger *clone() const override
    {
        return new Tiger(*this);
    }
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse : public Animal
{
public:
    Mouse() : Animal()
    {

    };

    string is_animal() const override
    {
        return "Mouse";
    }

    Mouse *clone() const override
    {
        return new Mouse(*this);
    }
};

class Zoo
{
    // Name des Zoos
    string _name;
    // Die Tiere werden in einem Vektor gespeichert
    vector<Animal *> animals;

public:
    // Konstruktor
    Zoo()
    {
        // Name zuweisen
        cout << "Bitte Name des Zoos eingeben: ";
        cin >> _name;
        // Wenn der String kuerzer als 4 Zeichen ist,
        // dann MyException werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        // HIER
        if(_name.size() < 4)
        {
            throw MyException(__FILE__, __LINE__, "Zooname zu kurz");
        }
        // Ansonsten, den 5. Buchstaben des Namens gross machen
        else 
        {
            _name.at(4) = toupper(_name.at(4));
        }

    }

    ~Zoo()
    {
        for(Animal *animal : animals)
        {
            delete animal;
        }
    }

    // Ein Tier dem Zoo hinzufuegen
    void add_animal(const Animal &animal)
    {
        // Wenn ein Elefant nach einer Maus eingefuegt wird, oder anders herum
        // dann Ausnahme werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        // HIER
        bool new_animal_is_elefant = (animal.is_animal() == "Elefant");
        bool new_animal_is_mouse = (animal.is_animal() == "Mouse");

        if(!animals.empty())
        {
            bool last_animal_is_elefant = (animals.back()->is_animal() == "Elefant");
            bool last_animal_is_mouse = (animals.back()->is_animal() == "Mouse");
            if((new_animal_is_elefant && last_animal_is_mouse) || (new_animal_is_mouse && last_animal_is_elefant))
            {
                throw ElefantMeetsMouse(__FILE__, __LINE__);
            }

        }
        Animal *new_animal = animal.clone();
        animals.push_back(new_animal);
        

    }
    // Alle Zootiere ausgeben
    void print() const
    {
        // HIER
        for(long unsigned int i=0; i < animals.size() ;i++)
        {
            animals.at(i)->print(true);
        }
    }
};

int main(int argc, char *argv[])
{
    char choice;
    string name;

    // Ausnahmepruefung aktivieren
    // HIER
    try{

        Zoo zoo;
        do
        {
            cout << endl
                 << "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                Elefant elefant = Elefant();
                zoo.add_animal(elefant);
                break;
            }
            case '2':
            {
                Tiger tiger = Tiger();
                zoo.add_animal(tiger);
                break;
            }
            case '3':
            {
                Mouse mouse = Mouse();
                zoo.add_animal(mouse);
                break;
            }
            case 'e':
                break;
            default:
                // Einen String als Ausnahme werfen
                // HIER
                throw string("Fehlerhafte Eingabe!");
               
            }

            cout << endl;
            zoo.print();
        } while (choice != 'e');
    }
    // Ausnahmen auffangen
    // Speziellste Ausnahme auffangen und ausgeben
    catch (ElefantMeetsMouse &e)
    {
        cout << e.what() << endl;
    }
    // MyException auffangen und ausgeben
    // HIER
    catch (MyException &e)
    {
        cout << e.what() << endl;
    }

    // Alle anderen Standardausnahmen auffangen und ausgeben
    // HIER
    catch (const exception &e)
    {
        cout << "Standardausnahme: " << e.what() << endl;
    }

    // Alle Strings auffangen und ausgeben
    // HIER
    catch (string &s)
    {
        cout << s << endl; 
    }

    // Alle anderen Ausnahmen auffangen
    // HIER
    catch (...)
    {
        cout << "Unbekannter FEHLER aufgetreten!" << endl;
    }
    
    return 0;
}

