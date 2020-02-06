#include <iomanip>
#include <sstream>

bool equal(const double& a, const double& b, const int& precision)
{
    std::stringstream sa, sb;
    sa << std::scientific << std::setprecision(precision) << a;
    sb << std::scientific << std::setprecision(precision) << b;
    return (sa.str() == sb.str());
}

bool lower(const double& a, const double& b)
{
    return (a < b);
}

bool upper(const double& a, const double& b)
{
    return (a > b);
}

const double& min(const double& a, const double& b)
{
    return (lower(a, b) ? a : b);
}

const double& max(const double& a, const double& b)
{
    return (upper(a, b) ? a : b);
}
