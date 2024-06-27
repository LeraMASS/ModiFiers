#include <iostream>
#include <string>
#include "House.hpp" 


//Статические методы
class Student {
private: //приватное поле
	size_t id;
	static size_t students_number;
	std::string name;
	static std::string group;//статическое поле класса
	static const time_t max_age = 55;
	time_t age;
public://публичное поле
	Student() : Student("", 0) {}
	Student(std::string name, time_t age) {
		this->name = name;
		setAge(age);
		id = ++students_number;
	}//конструктор

	Student(const Student& other) : Student(other.name, other.age) {
	}

	std::string getName() const { return name; }//get принимает
	void setName(std::string name) { this->name = name; }//set устанавливает название 
	
	static std::string getGroup() { return group; }//статические методы не могу быть константными
	static void setGroup(std::string group) { Student::group = group; }//this(-)
	
	time_t getAge() const { return age; }//нельзя сделать статическими
	void setAge(time_t age) {//нельзя сделать статическими
		if (age >= 0 && age <= max_age)
			this->age = age;
		else
			this->age = 0;
	}

	size_t getId() const { return id; }// const убирает ошибку в main
	static size_t getStudentsNumber() { return students_number; }

};

std::string Student::group = "BV311"; // обьявление static (::)-преднадлежность к пространству имен класса
size_t Student::students_number = 0;


//конструкторы и деструкторы не могут быть статическими, не могут быть костантами 


int main() {
	setlocale(LC_ALL, "Russian");
	


	
	//Модификации членов класса
	//std::cout << Student::group << std::endl;
	Student s1("Tomas Gob", 20), s2("For Smit", 30);
	std::cout << s1.getGroup() << std::endl;
	std::cout << s2.getGroup() << std::endl;
	Student::setGroup("VBV311");
	std::cout << s1.getGroup() << std::endl;
	std::cout << s2.getGroup() << std::endl;
	std::cout << Student::getGroup() << std::endl;

	const Student s3("Nikita Rogov", 25);
	//s3.setName("Valy");// ОШИБКА!!!
	std::cout << s3.getName() << std::endl;
	s3.setGroup("BV311");
	std::cout << s3.getGroup() << std::endl;
	std::cout << s3.getId() << std::endl;
	//Задача1
	House h1("Frunze", 60, 2);
	h1.appFlat(1, 1);
	h1.appFlat(1, 1);
	h1.printFlat(1);





	return 0;
}