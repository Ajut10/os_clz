#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001 // Tolerance for convergence
#define MAX_ITER 100   // Maximum number of iterations

// Define the differential equation
double f(double x, double y, double y_prime) {
    return 6 * x; // y'' = 6x
}

// Runge-Kutta 4th order method for solving first-order ODE
double rungeKutta(double x0, double y0, double h, double x_target) {
    double k1, k2, k3, k4;
    double y = y0;

    while (x0 < x_target) {
        k1 = h * f(x0, y, 0);
        k2 = h * f(x0 + h / 2, y + k1 / 2, 0);
        k3 = h * f(x0 + h / 2, y + k2 / 2, 0);
        k4 = h * f(x0 + h, y + k3, 0);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 += h;
    }

    return y;
}

// Shooting method
double shootingMethod(double x0, double x1, double y0, double y1) {
    double x_mid, y_mid;
    double epsilon = EPSILON;
    int max_iter = MAX_ITER;

    while (max_iter--) {
        x_mid = (x0 + x1) / 2;
        y_mid = rungeKutta(x0, y0, epsilon, x_mid);
        if (fabs(y_mid - y1) < epsilon)
            break;
        if (y_mid < y1)
            x0 = x_mid;
        else
            x1 = x_mid;
    }

    return x_mid;
}

int main() {
    double x0 = 1, y0 = 2; // Initial condition y(1) = 2
    double x1 = 2, y1 = 9; // Boundary condition y(2) = 9

    double x = shootingMethod(x0, x1, y0, y1);
    printf("Value of x for y(2) = 9 is approximately: %.4f\n", x);

    return 0;
}

