#include<string>
#include<iostream>
#include<array>

using namespace std;

class Datei 
{
    array<int,5> _datei;
    size_t _position = 0;

    static Datei* _instance;

    Datei() 
    {
        for(size_t i = 0; i < 5; i++) 
        {
            _datei[i] = i;
        }
    }

public:
    int get_next_line()
    {
        return _datei[_position++];
    }

    static Datei* get_instance()
    {
        if(_instance == nullptr)
        {
            _instance = new Datei();
        }
        return _instance;
    }
};

Datei *Datei::_instance = nullptr;

int main()
{
    Datei* datei = Datei::get_instance();
    cout << datei->get_next_line() << endl;
    datei = Datei::get_instance();
    cout << datei->get_next_line() << endl;
    cout << datei->get_next_line() << endl;
    datei = Datei::get_instance();
    cout << datei->get_next_line() << endl;
    return 0;
}