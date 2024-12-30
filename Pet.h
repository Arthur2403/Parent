#pragma once

using namespace std;

class Pet {
protected:
	string name;
	int age;
	string genus;
public:
	Pet(const string& newName = "IDK", const int newAge = 42, const string& newGenus = "Cat") {
		setName(newName);
		setAge(newAge);
		setGenus(newGenus);
	}

	string getName() const { return name; }
	void setName(const string& newName) { if (newName.size() > 0) { name = newName; } }
	string getGenus() const { return genus; }
	void setGenus(const string& newGenus) { if (newGenus.size() > 0) { genus = newGenus; } }
	int getAge() const { return age; }
	void setAge(const int newAge) { if (newAge > 0 && newAge < 1000) { age = newAge; } }
	void printPet() const { cout << "Your pet is" << genus << " at age " << age << " with name " << name; }
};

class Cat : public Pet {
protected:
	string breed;
public:
	Cat(const string& newName = "IDK", const int newAge = 42, const string& newGenus = "Cat", const string& newBreed) {
		Pet(newName, newAge, newGenus);
		setBreed(newBreed);
	}
	string getBreed() const { return breed; }
	void setBreed(const string& newBreed) { if (newBreed.size() > 0) { breed = newBreed; } }
};

class Dog : public Pet {
protected:
	string breed;
public:
	Dog(const string& newName = "IDK", const int newAge = 42, const string& newGenus = "Dog", const string& newBreed) {
		Pet(newName, newAge, newGenus);
		setBreed(newBreed);
	}
	string getBreed() const { return breed; }
	void setBreed(const string& newBreed) { if (newBreed.size() > 0) { breed = newBreed; } }
};

class Parrot : public Pet {
protected:
	string breed;
public:
	Parrot(const string& newName = "IDK", const int newAge = 42, const string& newGenus = "Parrot", const string& newBreed) {
		Pet(newName, newAge, newGenus);
		setBreed(newBreed);
	}
	string getBreed() const { return breed; }
	void setBreed(const string& newBreed) { if (newBreed.size() > 0) { breed = newBreed; } }
};