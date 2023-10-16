#include <iostream>
#include <cmath>
#include <cstdlib>

class FunctionCalculator {
public:
    double calculateA(double x, double y, double z, double b) {
        return  pow(abs(z), 0.2) * (3 + exp(y) - x + pow(abs(pow(y, 2) + b), 0.3)) / (1 + (pow(x, 2) * abs(y - pow(tan(z), 2))));
    }

    double calculateB(double x, double y, double z) {
        return y * (abs(pow(abs(x), 0.3) / (z + y) + pow(tan(z), 2) * (x + pow(z, 2)) / (2 * x - 1.4))) - z * exp(pow(x, 2) - y);
    }
};

class FunctionData {
public:
    double x, y, z, b;
    FunctionCalculator calculator;

    void setdata(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->b = calculator.calculateB(x, y, z);
    }

    double a() {
        return calculator.calculateA(x, y, z, b);
    }
};

int main() {
    double x = 0.48 * 9;
    double y = 0.47 * 9;
    double z = -1.32 * 9;


    FunctionCalculator calculator;
    double resultB = calculator.calculateB(x, y, z);


    double resultA = calculator.calculateA(x, y, z, resultB);


    std::cout << " b[x, y, z] = " << resultB << std::endl;
    std::cout << " a[x, y, z, b] = " << resultA << std::endl;


    FunctionData  data;
    for (double i = -1; i < 1; i += 0.2) {
        data.setdata(i, y, z);
        std::cout << "Calculation =" << i << ": " << data.a() << std::endl;
    }

    return 0;
}
