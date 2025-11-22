
#include <array>
#include <iostream>
using namespace std;

const unsigned int length = 10;

// hier die Funktion 'sort' implementieren
template <typename Type>

array<Type, length> sort(array<Type, length> container){
    bool change = false;
    do{
        change = false;
        for (unsigned int i = 0; i < length -1; i++){
            if(container[i] > container[i+1]){
                Type temp = container[i+1];
                container[i+1] = container[i];
                container[i] = temp;
                change = true;
            }
        }
    }while(change == true);
    return container;
}

int main(int argc, char *argv[]) 
{
    array<int,length> int_container = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
    array<int, length> sorted_int_container = sort(int_container);

    for (size_t i = 0; i < sorted_int_container.size(); i++) {
        cout << i << ": " << sorted_int_container[i] << endl;
    }

    array<char,length> char_container = {'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f'};
    array<char, length> sorted_char_container = sort(char_container);

    for (size_t i = 0; i < sorted_char_container.size(); i++) {
        cout << i << ": " << sorted_char_container[i] << endl;
    }

    array<string,length> string_container = {"Im", "Sommer", "ist", "es", "meistens", "heiß", "und", "es", "regnet", "wenig."};
    array<string, length> sorted_string_container = sort(string_container);

    for (size_t i = 0; i < sorted_string_container.size(); i++) {
        cout << i << ": " << sorted_string_container[i] << endl;
    }
}

