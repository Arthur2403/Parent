#include <iostream>
#include <cstring>
#include <algorithm>
#include "String.h"
#include "ByteString.h"

using namespace std;

void ByteString::setString(const char* newString) override {
    int count = 0;
    while (newString[count] != '\0') {
        if (newString[count] != '0' && newString[count] != '1') {
            this->eraseString();
            break;
        }
        count++;
    }
    String::setString(newString);
}
char* ByteString::subtractBinary(const char* a, const char* b) {

    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = std::max(lenA, lenB);

    char* result = new char[maxLen + 1];
    result[maxLen] = '\0';

    int borrow = 0;
    int i = lenA - 1, j = lenB - 1, k = maxLen - 1;

    while (k >= 0) {

        int bitA = (i >= 0) ? a[i--] - '0' : 0;
        int bitB = (j >= 0) ? b[j--] - '0' : 0;

        int diff = bitA - bitB - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result[k--] = diff + '0';
    }


    int start = 0;
    while (start < maxLen - 1 && result[start] == '0') {
        start++;
    }

    char* trimmedResult = new char[maxLen - start + 1];
    strcpy(trimmedResult, result + start);
    delete[] result;

    return trimmedResult;
}
char* ByteStrin::addBinary(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = std::max(lenA, lenB);

    char* result = new char[maxLen + 2]; 
    result[maxLen + 1] = '\0';

    int carry = 0; 
    int i = lenA - 1, j = lenB - 1, k = maxLen;

    while (k >= 0) {
        int bitA = (i >= 0) ? a[i--] - '0' : 0;
        int bitB = (j >= 0) ? b[j--] - '0' : 0;
        int sum = bitA + bitB + carry;
        carry = sum / 2;
        result[k--] = (sum % 2) + '0';
    }

    if (carry == 1) {
        result[0] = '1';
        return result;
    }
    else {
        char* trimmedResult = new char[maxLen + 1];
        strcpy(trimmedResult, result + 1);
        delete[] result;
        return trimmedResult;
    }
}
char* ByteString::addBinary(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = std::max(lenA, lenB);

    char* result = new char[maxLen + 2];
    result[maxLen + 1] = '\0';

    bool carry = false;
    int i = lenA - 1, j = lenB - 1, k = maxLen;

    while (k >= 0) {
        int bitA = (i >= 0) ? a[i--] - '0' : 0;
        int bitB = (j >= 0) ? b[j--] - '0' : 0;

        int sum = bitA + bitB + (carry ? 1 : 0);
        carry = (sum >= 2);
        result[k--] = (sum % 2) + '0';
    }

    if (carry) {
        result[0] = '1';
        return result;
    }
    else {
        char* trimmedResult = new char[maxLen + 1];
        strcpy(trimmedResult, result + 1);
        delete[] result;
        return trimmedResult;
    }
}
ByteString& ByteString::operator+=(const ByteString& other) {
    bool isNegative1 = string[0] == '1';
    bool isNegative2 = other.string[0] == '1';

    std::string num1 = std::string(string + 1);
    std::string num2 = std::string(other.string + 1);

    while (num1.size() < num2.size()) num1 = '0' + num1;
    while (num2.size() < num1.size()) num2 = '0' + num2;

    std::string result;
    bool isResultNegative = false;

    if (isNegative1 == isNegative2) {
        result = this->addBinary(num1, num2);
        isResultNegative = isNegative1;
    }
    else {
        if (num1 >= num2) {
            result = subtractBinary(num1, num2);
            isResultNegative = isNegative1;
        }
        else {
            result = subtractBinary(num2, num1);
            isResultNegative = isNegative2;
        }
    }
