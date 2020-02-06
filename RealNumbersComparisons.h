//==============================================================================
// Name        : RealNumbersComparisons.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (06/02/2020)
// Description : Header file of the real numbers comparisons functions
//==============================================================================

#ifndef REALNUMBERSCOMPARISONS_H
#define REALNUMBERSCOMPARISONS_H

bool equal(const double& a, const double& b, const int& precision);
bool lower(const double& a, const double& b);
bool upper(const double& a, const double& b);
const double& min(const double& a, const double& b);
const double& max(const double& a, const double& b);

#endif /* REALNUMBERSCOMPARISONS_H */
