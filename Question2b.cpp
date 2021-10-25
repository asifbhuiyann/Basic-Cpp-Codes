#include <iostream>
#include <queue>
using namespace std;
void rotateq(queue<int>&q,int cnt)
{
    for(int i=0; i<cnt; i++)
    {
        int x= q.front();
        q.pop();
        q.push(x);
    }

}

int main()
{
    queue<int>q;
    q.push(1);
    q.push(3);
    q.push(4);
    q.push(2);
    q.push(7);
    q.push(9);
    int count;
    cout<<"Enter Count:"<<endl;
    cin>>count;

    rotateq(q,count);

    int size=q.size();
    for(int i=0; i<size; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
