#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

bool equals(const double& a, const double& b, const int& precision)
{
    std::stringstream sa, sb;
    sa << std::scientific << std::setprecision(precision) << a;
    sb << std::scientific << std::setprecision(precision) << b;
    return (sa.str() == sb.str());
}

int main()
{
    const double a = 1.234567890e-10;
    const double b = 1.234567891e-10;
    for (int prec = 0; prec <= 20; ++prec)
    {
        std::cout << "precision=" << prec << " equals=" << equals(a, b, prec) << std::endl;
    }
    return EXIT_SUCCESS;
}
