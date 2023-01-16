#ifndef CREDIT_H_
#define CREDIT_H_

#include <string>


std::string DetermineCompany(long card_number);
long GetDivisor(int length);
std::string LuhnAlgorithm(long card_number);
int FindLength(long card_number);

#endif