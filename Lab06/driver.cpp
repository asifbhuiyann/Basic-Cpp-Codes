#include<iostream>
#include "unsortedtype.cpp"
using namespace std;

int main(){
    UnsortedType<int> l1,l2;           // made the two list l1 and l2
    int m,n;
    cout<<"\nInput: ";
    cin>>m;
    for(int i=0;i<m;i++){            // take the inputs in both list
        int x;
        cin>>x;
        l1.InsertItem(x);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        l2.InsertItem(x);
    }

     // please note that insert item function inserts the new node in first position always, so data inserted in ascending
     // will be present their in descending order actually, for ex the first node of l1 will contain data 40 (for the given input)
     // so in order to store data ascending in final list, we need to insert in descending order

    UnsortedType<int> finalList;            // now made a final list to store both in ascending order
    int num1,num2;                        // initialized two variables item1 and item2, item1 will contain data of l1 and item 2 contain l2
    int length1=0,length2=0;                      // len1 and len2 are to take record of how many value is still to be inserted in both list at any point

    l1.GetNextItem(num1);                    // get the first item of both list, as they will be the greatest so the max among these need to be inserted first to get final ascending
    l2.GetNextItem(num2);
    while(length1<l1.LengthIs() && length2<l2.LengthIs()){  // keep adding untill any one of l1 or l2 finishes
        if (num1>num2){                      // if item1 is greater than add this and increase the counter of len1
            finalList.InsertItem(num1);
            length1++;
            if (length1<l1.LengthIs())                // if len1 is less than length of l1 that means there are remaining elements in l1 so get the next element
                l1.GetNextItem(num1);


        }else{                                  // do same if item2 is greater
            finalList.InsertItem(num2);
            length2++;
            if (length2<l2.LengthIs())
                l2.GetNextItem(num2);

        }

    }


    while (length1<l1.LengthIs()){                 // if l1 is remaining then add all the elements of l1 to final
        finalList.InsertItem(num1);
            length1++;
            if (length1<l1.LengthIs())
                l1.GetNextItem(num1);
    }

    while (length2<l2.LengthIs()){                     // if l2 is remaining then add all its element to final, please note that only one while loop will be executed among these two
        finalList.InsertItem(num2);
            length2++;
            if (length2<l2.LengthIs())
                l2.GetNextItem(num2);
    }

    int num;
    int i =0;

    cout<<"\nOutput: ";
    while (i<finalList.LengthIs()){               // now print the final list
        finalList.GetNextItem(num);
        cout<<num<<" ";
        i++;
    }

    cout<<endl<<endl;

    return 0;
}

