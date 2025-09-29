//
//  main.cpp
//  Lab 13
//
//  Created by Nafi on 9/21/25.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int days;
    cout << "Enter number of days of rainfall data: ";
    cin >> days;

    vector<double> rainfall(days);

    // Read from file
    ifstream fin("rainfall.txt");
    if (!fin) {
        cerr << "Error: could not open rainfall.txt\n";
        return 1;
    }

    for (int i = 0; i < days && fin; i++) {
        fin >> rainfall[i];
    }
    fin.close();

    // Display raw data
    cout << "Rainfall data (" << days << " days):\n";
    for (double r : rainfall) cout << r << " ";
    cout << "\n\n";

    // Vector functions
    cout << "Size: " << rainfall.size() << endl;
    cout << "First day: " << rainfall.front() << " mm\n";
    cout << "Last day: " << rainfall.back() << " mm\n";
    cout << "Day 10 rainfall: " << rainfall.at(9) << " mm\n";

    // Total + average rainfall
    double total = accumulate(rainfall.begin(), rainfall.end(), 0.0);
    double avg = total / rainfall.size();
    cout << "Total rainfall: " << total << " mm\n";
    cout << "Average daily rainfall: " << avg << " mm\n";

    // Min and Max rainfall
    cout << "Lowest rainfall: " << *min_element(rainfall.begin(), rainfall.end()) << " mm\n";
    cout << "Highest rainfall: " << *max_element(rainfall.begin(), rainfall.end()) << " mm\n";

    // Sort rainfall values
    sort(rainfall.begin(), rainfall.end());
    cout << "\nSorted rainfall values:\n";
    for (double r : rainfall) cout << r << " ";
    cout << "\n";

    // Reverse iteration
    cout << "\nRainfall in reverse order:\n";
    for (auto it = rainfall.rbegin(); it != rainfall.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // Find rainfall of exactly 5 mm
    double searchVal = 5.0;
    auto it = find(rainfall.begin(), rainfall.end(), searchVal);
    if (it != rainfall.end())
        cout << searchVal << " mm found at index " << distance(rainfall.begin(), it) << endl;
    else
        cout << searchVal << " mm not found\n";

    // Demonstrate push_back (extra feature of vector vs array)
    rainfall.push_back(12.5); // add another value
    cout << "\nAfter push_back, new size = " << rainfall.size()
         << " (last element = " << rainfall.back() << ")\n";

    return 0;
}
