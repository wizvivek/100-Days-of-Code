#include <iostream>
using namespace std;
int getindex(float r[], int n)
{
    float max = 0;
    int index;
    for (int i = 0; i < n; i++)
    {
        if (r[i] >= max)
        {
            max = r[i];
            index = i;
        }
    }
    r[index] = -1;
    return index;
}

float greedy_knapsack(float r[], float w[], float p[], int n, float c)
{
    int i;
    float u = c;
    int index;
    float x;
    float cp = 0;
    for (i = 0; i < n; i++)
    {
        index = getindex(r, n); // 10 60
        if (w[index] <= u)      // 20 100
        {                       // 30 120
            x = 1;
            cp = cp + (x * p[index]);

            u = u - w[index];
        }
        else
        {
            x = (float)u / w[index];

            cp = cp + (x * p[index]);

            break;
        }
    }
    return cp;
}

int main()
{
    int n;
    cout << "enter the number of objects" << endl;
    cin >> n;
    float c;
    cout << "enter the capacity of the bag" << endl;
    cin >> c;
    float w[n], p[n], r[n];
    cout << "enter the weight and price of each object" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> p[i];
    }
    for (int i = 0; i < n; i++)
        r[i] = p[i] / w[i];
    cout << "maximum profit : " << greedy_knapsack(r, w, p, n, c) << endl;
    return 0;
}
