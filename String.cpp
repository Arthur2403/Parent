#include <iostream>
#include <cstring>
#include "String.h"

String& String::operator=(const String& newString) {
	if (this = newString) {
		return *this;
	}
	this->string = newString.string;
	return *this;
}

String& String::operator+=(const char* newChar) const {
	int newSize = strlen(this->string) + strlen(newChar) + 1;
	char* newString = new char[newSize];
	strcpy(newString, this->string);
	strcat(newString, newChar);

	delete[] this->string;
	string = newString;

	return *this;
}

String& operator+(const char* newChar) const {
	int newSize = strlen(this->string) + strlen(newChar) + 1;
	char* newString = new char[newSize];
	strcpy(newString, this->string);
	strcat(newString, newChar);

	String result(newString);
	delete[] newString;
	return result;
}

friend String& operator+(const char* newChar, const String& newString) {
	int newSize = strlen(newString.string) + strlen(newChar) + 1;
	char* resultString = new char[newSize];
	strcpy(resultString, newChar);
	strcat(resultString, newString.string);

	String result(newString);
	delete[] newString;
	return result;
}

