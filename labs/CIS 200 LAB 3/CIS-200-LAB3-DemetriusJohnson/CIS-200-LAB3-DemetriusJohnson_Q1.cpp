/*
    *Author: Demetrius Johnson
    *Creation Date: 29 Sept. 2020
    *Modification Date: 7 Oct. 2020
    *Purpose: Practice using the VIS STUD debugger
*/

// CIS-200-LAB3-DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
using namespace std;

class Data
{
public:
    Data()
    {
        _values.push_back(1);
        _values.push_back(2);
    }
    int getSum()
    {
        int total = -1;
        for (vector<int>::iterator itr = _values.begin(), end = _values.end(); itr != end; ++itr)
        {
            total += *itr;
        }
        return total;
    }
    int getCount() { return _values.size(); }
private:
    vector<int> _values;
};

double compute_average(int sum, int count)
{
    return sum / (double)count;
}

int main()
{
    Data d;

    cout << compute_average(d.getSum(), d.getCount()) << endl;
    return 0;
}
