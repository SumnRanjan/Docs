#include <iostream>
#include <vector> // Include vector header
using namespace std;

bool rev(int n)
{
    int r = 0;
    while (n)
    {
        r = r * 10 + n % 10;
        n = n / 10;
    }

    return r < 10; // Simplified return statement
}

int main()
{
    int n;
    cin >> n;

    vector<int> results; // Vector to store results

    while (n--)
    {
        int t;
        cin >> t;
        int count = 0;

        for (int i = 1; i <= t; i++)
        {
            if (rev(i))
            {
                count++;
            }
        }
        results.push_back(count); // Store the count in the vector
    }

    // Output all results after processing all inputs
    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}
