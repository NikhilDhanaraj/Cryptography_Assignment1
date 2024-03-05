#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char zeroChar;
    char oneChar;
    cin >> zeroChar;
    cin >> oneChar;

    string inputString;
    string binaryInput;
    cin >> inputString;

    for (int i = 0; i < inputString.length(); i++)
    {
        if (inputString[i] == zeroChar)
        {
            binaryInput += '0';
        }
        else if (inputString[i] == oneChar)
        {
            binaryInput += '1';
        }
    }

    string outputString;

    for (int i = 0; i < binaryInput.length(); i += 5)
    {
        string subString = binaryInput.substr(i, 5);
        int intValue = stoi(subString, nullptr, 2);
        if (intValue >= 0 && intValue <= 25)
        {
            char alphabet = 'A' + intValue;
            outputString += alphabet;
        }
    }

    cout << outputString;

    return 0;
}