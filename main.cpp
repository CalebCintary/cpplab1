#include <iostream>
#include <cmath>
#include <string>

double f(double x);
double y(double x);

int main() {
    //Inputing programm mode
    int usercase = 0;
    std::cin >> usercase;
    //Setting cout flags
    std::cout.setf(std::ios::right);
    std::cout.setf(std::ios::showpos);
    std::cout.fill('.');
    std::cout.width(8);
    std::cout.precision(3);
    //Exercise isn't consist information about creation any kind of menu.
    //So, here is program without cycling and screen cleaning
    switch (usercase) { //Select programm mode
        case 1: {
            double x = 0;
            std::cin >> x;
            std::cout << f(x);
            break;
        }

        case 2: {
            double x1, x2 = 0;
            std::cin >> x1 >> x2;
            x1 = f(x1);
            x2 = f(x2);
            if (x2 > x1) { x1 = x2; }
            std::cout << x1;
            break;
        }
        case 3: {
            double x1, x2, d = 0;
            std::cin >> x1 >> x2 >> d;
            while ((x1 += d) < x2) {
                std::cout << "f(" << x1 << ") = " << f(x1) << std::endl;
            }
            break;
        }
        case 4: {
            system("pause");
            exit(0);
        }

        default: //Exercise haven't defined what should be if usermode is incorrect.
            throw std::runtime_error("Wrong case");
    }
    
    system("pause");
    return 0;
}

double f(double x) {
    if (x < -10.0) {
        return y(-10.0);
    }
    if ((x >= -10.0) && (x <= 10.0)) {
        return y(x);
    }
    if (x > 10.0) {
        return y(10.0);
    }
    throw std::runtime_error("something wrong");
}

double y(double x) {
    return ((2.0 + x) / pow((2.0 + exp(-1.0 * x)), 1.0 / 3.0));
}

