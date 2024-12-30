#pragma once

using namespace std;

class String {
protected:
	char* string;
public:
	String() {
		setString("ABC");
	}
	String(const char* newString) {
		setString(newString);
	}
	String(const String& newString) {
		setString(newString.string);
	}
	virtual ~String() {
		delete[] string;
	}

	const char* getString() const { return string; }
	virtual void setString(const char* newString) { if (newString != nullptr) { delete[] string; string = new char[strlen(newString)]; strcpy(string, newString); } }

	void printString() const { cout << "Your string: " << *string << "\n"; }

	int getLenght() const { return strlen(string); }

	void eraseString() { char* newString = new char[1]; newString[0] = '\0'; string = newString; }

	virtual String& operator=(const String& newString);

	virtual String& operator+=(const char* newChar) const;
	String& operator+(const char* newChar) const;
	friend String& operator+(const char* newChar, const String& newString);
	bool operator==(const String& newString) { return this->string == newString.string; }
	bool operator!=(const String& newString) { return this->string != newString.string; }
};