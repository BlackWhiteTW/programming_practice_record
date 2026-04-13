#include <bits/stdc++.h>

using namespace std;

double calcTotalCharges(int days, double dailyRate, double labCharges, double medCharges)
{
    return (days * dailyRate) + labCharges + medCharges;
}

double calcTotalCharges(double labCharges, double medCharges)
{
    return labCharges + medCharges;
}

int main()
{
    string inputLine;

    getline(cin, inputLine);

    stringstream ss(inputLine);
    vector<double> inputs;
    double temp;

    while (ss >> temp)
        inputs.push_back(temp);

    if (inputs.size() == 2)
    {
        double lab = inputs[0];
        double med = inputs[1];
        double total = calcTotalCharges(lab, med);
        cout << "=> 門診病患總費用為: $" << total << endl;
    }
    else if (inputs.size() == 4)
    {
        int days = inputs[0];
        double rate = inputs[1];
        double lab = inputs[2];
        double med = inputs[3];

        double total = calcTotalCharges(days, rate, lab, med);
        cout << "=> 住院病患總費用為: $" << total << endl;
    }
    else
    {
        cout << "ERROR" << endl;
    }

    return 0;
}