#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#define endl '\n'
using namespace std;

// اللهم علِّمنا ما ينفعنا، وانفعنا بما علمتنا، وزدنا علمًا.

int main() {

    cout << "Welcome, " << endl;
    cout<<"This code designed by Ahmed Nassar & Abdelrahman Diab"<<endl;
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "This program Solve the system \"3*3\" by using Jacobi & Guass Methods" << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Enter the coefficient of your system" << endl;
    double arr[3][4];
    for (auto &i: arr) {
        for (double &j: i) {
            cin >> j;
        }
    }
    double x1 = 0, x2 = 0, x3 = 0;
    vector<double> j, g;
    double v1, v2, v3;
    cout << "Enter Number of iteration: ";
    int iter;
    cin >> iter;
    select:
    cout << "\nSolution with Jacobi >> j" << endl;
    cout << "Solution with Guass >> g" << endl;
    cout << "Select choice: ";
    char choice;
    cin >> choice;
    if (choice == 'j') {
        cout << "\n\"Jacobi solution\"";
        for (int i = 0; i < iter; ++i) {
            v1 = (1 / arr[0][0]) * (arr[0][3] + ((-1 * x2) * arr[0][1]) + ((-1 * x3) * arr[0][2]));
            v2 = (1 / arr[1][1]) * (arr[1][3] + ((-1 * x1) * arr[1][0]) + ((-1 * x3) * arr[1][2]));
            v3 = (1 / arr[2][2]) * (arr[2][3] + ((-1 * x1) * arr[2][0]) + ((-1 * x2) * arr[2][1]));
            x1 = v1;
            x2 = v2;
            x3 = v3;
            j.push_back(v1);
            j.push_back(v2);
            j.push_back(v3);
        }
        int cnt = 1;
        for (int i = 0; i < j.size(); ++i) {
            if (i % 3 == 0) {
                cout << endl;
                cout << "At i = " << i / 3 << endl;
            }
            if (cnt > 3) cnt = 1;
            cout << "X" << cnt++ << " = " << j[i] << endl;
        }
    }
        // Guass method
    else if (choice == 'g') {
        cout << "\n\"Guass solution\"";
        x1 = 0, x2 = 0, x3 = 0;
        for (int i = 0; i < iter; ++i) {
            x1 = (1 / arr[0][0]) * (arr[0][3] + ((-1 * x2) * arr[0][1]) + ((-1 * x3) * arr[0][2]));
            x2 = (1 / arr[1][1]) * (arr[1][3] + ((-1 * x1) * arr[1][0]) + ((-1 * x3) * arr[1][2]));
            x3 = (1 / arr[2][2]) * (arr[2][3] + ((-1 * x1) * arr[2][0]) + ((-1 * x2) * arr[2][1]));
            g.push_back(x1);
            g.push_back(x2);
            g.push_back(x3);
        }
        int cnt = 1;
        for (int i = 0; i < g.size(); ++i) {
            if (i % 3 == 0) {
                cout << endl;
                cout << "At i = " << i / 3 << endl;
            }
            if (cnt > 3) cnt = 1;
            cout << "X" << cnt++ << " = " << g[i] << endl;
        }
    } else {
        cout << "Wrong Choice!" << endl;
        goto select;
    }
    return 0;
}