#include "sortedType.cpp"
#include "timeStamp.h"
#include"sortedtype.h"

using namespace std;

int main()
{


    SortedType <timeStamp> tl;
    int ts, tm, th;
    cout << "Enter five timeStamps: " << endl;
    for(int i=0; i<5; i++)
    {
        cin >> ts >> tm >> th;
        tl.InsertItem(timeStamp(ts, tm, th));
    }

    tl.ResetList();

    timeStamp delST(25, 36, 17);
    tl.DeleteItem(delST);

    tl.ResetList();
    timeStamp tempST;
    for(int i=0; i<tl.LengthIs(); i++)
    {
        tl.GetNextItem(tempST);
        tempST.printTS();
        cout << endl;
    }
    return 0;
}
