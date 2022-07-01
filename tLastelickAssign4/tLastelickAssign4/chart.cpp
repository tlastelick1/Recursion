#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

void hyphen(int n)
{
    if (n > 0)
    {  
        cout << "-";
        hyphen(n-1);
    }
    return;
}
void chart (int list[], int lowerIndex, const int higherIndex)
{
    if (lowerIndex == higherIndex)
    {
        return;
    }
    else
    {
        cout << list[lowerIndex] << " ";
        hyphen(list[lowerIndex]);
        cout << endl;
        chart(list, lowerIndex+1, higherIndex);
    }
        
    return;    




}

int main()
{
    const int SIZE = 5;
    int values[SIZE]={10,21,16,13,30};
    //hyphen(3);
    chart(values, 0, SIZE);

    return 0;
}
