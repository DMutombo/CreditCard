#include "credit.h"
#include <iostream>

using namespace std;


int main() {
    long card_number;
    std::string result = "";
    int length = 0;
    long divisor = 0;
    std::string res = "";
    
    do {
        std::cout << "WELCOME TO THE CREDIT CARD VALIDATOR" << std::endl;
        std::cout << "=====================================" << std::endl;
        std::cout << "Please enter a valid credit card number: ";
        std::cin >> card_number;

        res = LuhnAlgorithm(card_number);
        std::cout << res << std::endl;
        std::cout << std::endl;
    } while (card_number > 0);
    
    return 0; 
}

std::string LuhnAlgorithm(long card_number) {
    int sum = 0;
    int last_digit = 0;
    int multiple = 0;
    long card = card_number;
    std::string result = "";
    int length = FindLength(card_number);

    while (card > 0) {
        last_digit = card % 10;
        sum = sum + last_digit;
        card = card / 100;
    }

    card = card_number / 10;
    while (card > 0) {
        last_digit = card % 10;
        multiple = 2 * last_digit;
        card = card / 100;
        sum = sum + (multiple / 10) + (multiple % 10);
    }
    sum = sum % 10;

    if (sum == 0) {
       result = DetermineCompany(card_number);
    } else {
        result = "INVALID";
    } 
    return result;
}

long GetDivisor(int length) {
    long divisor = 10;

    for (int i = 0; i < length - 2; i++) {
        divisor = divisor * 10;
    }
    return divisor;
}

int FindLength(long card_number) {
    int count = 0;

    while (card_number != 0) {
        card_number = card_number / 10;
        count++;
    }
    return count;
}

std::string DetermineCompany(long card_number) {
    long card = card_number;
    long length = FindLength(card);
    long divisor = GetDivisor(length);
    int first_digit = card / divisor;
    int  first_two = card / (divisor / 10);
    std::string company = "";

    if (first_digit == 4 && length == 16 || length == 13) {
        company = "VISA";
    } else if ((first_two == 34 || first_two == 37) && length == 15) {
        company = "AMEX";
    } else if ((50 < first_two && first_two < 56) && length == 16 ) {
        company = "MASTERCARD";
    } else {
        company = "INVALID";
    }
    return company;
}