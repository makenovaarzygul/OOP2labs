// oop2labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <windows.h>

class Aeroflot {
public:
    std::string flightNumber;
    std::string departureCity;
    std::string destinationCity;
    std::string arrivalTime;
    std::string departureTime;
    std::string registrationPlace;

    Aeroflot(const std::string& number, const std::string& departure, const std::string& destination,
        const std::string& arrival, const std::string& departureTime, const std::string& regPlace)
        : flightNumber(number), departureCity(departure), destinationCity(destination),
        arrivalTime(arrival), departureTime(departureTime), registrationPlace(regPlace) {}

    void displayFlightInfo() const {
        std::cout << "| " << std::setw(12) << flightNumber << " | " << std::setw(25) << departureCity
            << " | " << std::setw(25) << destinationCity << " | " << std::setw(12) << arrivalTime
            << " | " << std::setw(16) << departureTime << " | " << std::setw(20) << registrationPlace << " |\n";
    }
};

bool compareByDestination(const Aeroflot& a, const Aeroflot& b) {
    return a.destinationCity < b.destinationCity;
}

bool compareByDestination(const Aeroflot& a, const Aeroflot& b) {
    return std::locale("ru_RU.UTF-8").name() == "C" ? a.destinationCity < b.destinationCity : a.destinationCity < b.destinationCity;
}
int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::vector<Aeroflot> flights;

    std::cout << "Введите информацию о рейсах:\n";
    for (int i = 1; i <=2; ++i) {
        std::string number, departure, destination, arrival, departureTime, regPlace;
        std::cout << "Номер рейса: ";
        std::cin >> number;
        std::cout << "Пункт отправления: ";
        std::cin >> departure;
        std::cout << "Пункт назначения: ";
        std::cin >> destination;
        std::cout << "Время прибытия: ";
        std::cin >> arrival;
        std::cout << "Время отправления: ";
        std::cin >> departureTime;
        std::cout << "Место регистрации: ";
        std::cin >> regPlace;
        flights.emplace_back(number, departure, destination, arrival, departureTime, regPlace);
    }

    std::sort(flights.begin(), flights.end(), compareByDestination);

    std::cout << "| Номер рейса  | Пункт отправления           | Пункт назначения рейса      |Время прибытия | Время отправления | Место регистрации    |\n";
    std::cout << "+--------------+-----------------------------+-----------------------------+---------------+-------------------+----------------------+\n";

    for (const auto& flight : flights) {
        flight.displayFlightInfo();
    }

    if (flights.empty()) {
        std::cout << "Нет доступных рейсов.\n";
    }

    return 0;
}


#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    string lastName;
    string birthDate;
    string phoneNumber;

    Student(const string& last, const string& birth, const string& phone)
        : lastName(last), birthDate(birth), phoneNumber(phone) {}
};

class StudentGroup {
private:
    vector<Student> students;

public:
    // Добавление студента
    void addStudent() {
        string last, birth, phone;
        cout << "Enter Last Name: ";
        cin >> last;
        cout << "Enter Birth Date: ";
        cin >> birth;
        cout << "Enter Phone Number: ";
        cin >> phone;
        students.push_back(Student(last, birth, phone));
    }

    // Удаление студента по фамилии
    void removeStudent() {
        string lastName;
        cout << "Enter Last Name to remove: ";
        cin >> lastName;
        students.erase(std::remove_if(students.begin(), students.end(),
            [&](const Student& student) { return student.lastName == lastName; }), students.end());
    }

    // Поиск студента по фамилии
    void findStudentByLastName() {
        string lastName;
        cout << "Enter Last Name to find: ";
        cin >> lastName;
        auto it = std::find_if(students.begin(), students.end(),
            [&](const Student& student) { return student.lastName == lastName; });

        if (it != students.end()) {
            cout << "Student found:\n";
            cout << "Last Name: " << it->lastName << "\tBirth Date: " << it->birthDate
                << "\tPhone Number: " << it->phoneNumber << std::endl;
        }
        else {
            cout << "Student not found.\n";
        }
    }

    // Сортировка студентов по фамилии
    void sortByLastName() {
        sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { return a.lastName < b.lastName; });
        cout << "Students sorted by Last Name.\n";
    }

    // Вывод всех студентов
    void displayAllStudents() {
        for (const auto& student : students) {
            cout << "Last Name: " << student.lastName << "\tBirth Date: " << student.birthDate
                << "\tPhone Number: " << student.phoneNumber << std::endl;
        }
    }
};

int main() {
    StudentGroup group;

    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Find Student\n";
        cout << "4. Sort Students\n";
        cout << "5. Display All Students\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            group.addStudent();
            break;

        case 2:
            group.removeStudent();
            break;

        case 3:
            group.findStudentByLastName();
            break;

        case 4:
            group.sortByLastName();
            break;

        case 5:
            group.displayAllStudents();
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}