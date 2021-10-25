#include <iostream>
#include "quetype.h"
#include "quetype.cpp"
using namespace std;

int minCoins(int coins[], int n, int total)
{
    if (total == 0)
        return 0;

    int result = 2147483647;

    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= total)
        {
            int sub_result = minCoins(coins, n, total - coins[i]);
            if (sub_result != 2147483647 && sub_result + 1 < result)
                result = sub_result + 1;
        }
    }
    return result;
}

int main()
{
    int n = 0, total = 0;
    cout << "Enter the minimum number of coins: " << endl;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cout << "Input the coins: " << endl;
        cin >> coins[i];
    }
    cout << "Input the Value of Money: " << endl;
    cin >> total;
    cout << "Minimum coins required is:  " << minCoins(coins, n, total);
    return 0;
}





