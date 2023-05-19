#include <iostream>
#include <cmath>

using namespace std;

void roots(double a, double b, double c, double d, double* res) {
    b /= a;
    c /= a;
    d /= a;

    double Q = (3 * c - b * b) / 9;
    double R = (9 * b * c - 27 * d - 2 * b * b * b) / 54;

    double D = Q * Q * Q + R * R;

    if (D > 0) {
        double S1 = cbrt(R + sqrt(D));
        double S2 = cbrt(R - sqrt(D));

        res[0] = S1 + S2 - b / 3;
    }
    else {
        double theta = acos(-R / sqrt(-Q * Q * Q));
        const double PI = 3.1415;

        res[0] = -2 * sqrt(-Q) * cos(theta / 3) - b / 3;
        res[1] = -2 * sqrt(-Q) * cos((theta + 2 * PI) / 3) - b / 3;
        res[2] = -2 * sqrt(-Q) * cos((theta + 4 * PI) / 3) - b / 3;
    }

}

int main()
{
    double a[3] = {};

    roots(1, -9, 24, -20, a);

    for (auto& x : a) {
        cout << x << "\n";
    }
}
