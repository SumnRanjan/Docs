#include <iostream>
using namespace std;

int isSingleDigit(int n, int count)
{
    int r = 0;
    while (n)
    {
        r = r * 10 + n % 10;
        n = n / 10;
    }

    if (r < 10)
    {
        count++;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int t;
        cin >> t;
        int count = 0;

        if (t < 10)
            cout << t << endl;

        else
        {
            count = 9;
            for (int i = 10; i <= t; i++)
            {
                if (i % 10 == 0)
                count = isSingleDigit(i, count);
            }
            cout << count << endl;
        }
    }

    return 0;
}