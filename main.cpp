#include "graphtype.h"
#include "heaptype.cpp"
#include <iostream>
using namespace std;

int main()
{
    GraphType<char>g(10);

    g.AddVertex('A');
    g.AddVertex('B');
    g.AddVertex('C');
    g.AddVertex('D');
    g.AddVertex('E');
    g.AddVertex('F');
    g.AddVertex('G');
    g.AddVertex('H');


    if(g.checkStCntd('A','H'))
        cout<<"The Graph is Strongly Connected."<<endl;
    else
        cout<<"The Graph is not Strongly Connected."<<endl;


}
