#include <gnuplot-iostream.h>
#include <gsl/gsl_poly.h>
#include <iostream>

int main()
{
    // Set up Gnuplot
    Gnuplot gp;
    gp << "set xrange [-10:10]\n";
    gp << "set yrange [-100:100]\n";
    gp << "set xlabel \"x\"\n";
    gp << "set ylabel \"y\"\n";
    gp << "set title \"Random Polynomial\"\n";

    // Generate random polynomial coefficients
    int degree = 5;
    double coefficients[degree + 1];
    gsl_rng* r = gsl_rng_alloc(gsl_rng_default);
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = gsl_ran_gaussian(r, 1.0);
    }

    // Compute the y values for the polynomial
    int n = 1000;
    double x[n], y[n];
    for (int i = 0; i < n; i++) {
        x[i] = -10.0 + i * 20.0 / (n - 1);
        gsl_poly_eval(&coefficients[0], degree + 1, x[i], &y[i]);
    }

    // Plot the polynomial
    gp << "plot '-' with lines\n";
    for (int i = 0; i < n; i++) {
        gp << x[i] << " " << y[i] << "\n";
    }
    gp << "e\n";

    return 0;
}