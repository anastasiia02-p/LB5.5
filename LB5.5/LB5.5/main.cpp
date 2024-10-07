#include <iostream>
#include <cmath>

double f(double x) {
    return sin(x) - cos(x);
}

double findRootRecursive(double a, double b, double eps, int& recursionDepth, int currentLevel = 0) {
    recursionDepth = std::max(recursionDepth, currentLevel);

    double m = (a + b) / 2;
    double fm = f(m);

    if (std::abs(fm) < eps) {
        return m;
    }

    if (f(a) * fm < 0) {
        return findRootRecursive(a, m, eps, recursionDepth, currentLevel + 1);
    }
    else {
        return findRootRecursive(m, b, eps, recursionDepth, currentLevel + 1);
    }
}

int main() {
    double a, b, eps;
    int recursionDepth = 0;

    std::cout << "start of interval  a= ";
    std::cin >> a;
    std::cout << "end of interval b= ";
    std::cin >> b;
    std::cout << "precision eps= ";
    std::cin >> eps;

    if (f(a) * f(b) >= 0) {
        std::cout << "The conditions of the dichotomy method are not met (f(a) * f(b) >= 0)." << std::endl;
    }
    else {
        double root = findRootRecursive(a, b, eps, recursionDepth);
        std::cout << "root =  " << root << std::endl;
        std::cout << "The depth of recursion: " << recursionDepth << std::endl;
    }

    return 0;
}