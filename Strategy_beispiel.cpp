#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ISortAlgorythm
{

public:
    virtual void execute(const vector<string> &data) = 0;

};

class AscendingSort : public ISortAlgorythm
{

public:
    void execute(const vector<string> &data) override
    {
        string result;
        for (string letter : data) 
        {
            result += letter;
        }
        sort(begin(result), end(result));
        cout << result << endl;; 
    }
};

class DescendingSort : public ISortAlgorythm
{

public:
    void execute(const vector<string> &data) override
    {
        string result;
        for (string letter : data) 
        {
            result += letter;
        }
        sort(begin(result), end(result));
        for (int i = 0; i < result.size() / 2; i++)
        {
            swap(result[i], result[result.size() - i - 1]);
        }
        cout << result << endl;
    }

};

class Sorter 
{
    ISortAlgorythm* _strategy;
public:
    void set_strategy(ISortAlgorythm* strategy)
    {
        _strategy = strategy;
    }

    void execute(const vector<string> &data) const 
    {
        _strategy->execute(data);
    }
};

void client_code()
{
    Sorter *sorter = new Sorter();

    cout << "Aufsteigende Sortierung." << endl;
    sorter->set_strategy(new AscendingSort);

    sorter->execute(vector<string>{"a", "e", "c", "b", "d"});

    cout << "Absteigende Sortierung." << endl;
    sorter->set_strategy(new DescendingSort);

    sorter->execute(vector<string>{"a", "e", "c", "b", "d"});
    delete sorter;
}

int main()
{
    client_code();
    
    return 0;
}