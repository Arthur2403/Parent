#pragma once

using namespace std;

class ByteString : public String {
public:
	ByteString() {
		String("00101010");
		setString("00101010");
	}
	ByteString(char* newString) {
		String(newString);
		setString(newString);
	}
	ByteString(ByteString& newString) {
		String(newString.string);
		setString(newString.string);
	}
	~ByteString() override {
		delete[] string;
		String::~String();
	}

	void setString(const char* newString) override;
	void invertString() { if (string[0] = 0) { string[0] = 1; return; } string[0] = 0; return; }
	char* subtractBinary(const char* a, const char* b);
	char* addBinary(const char* a, const char* b);
	ByteString& operator+=(const ByteString& other);
}