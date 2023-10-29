
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функция для инициализации векторов
void initializeVectors(int choice, vector<string>& names, vector<int>& grades) {
    if (choice == 1) {
        // Демонстрационная инициализация на дефолтных значениях
        names = { "Анна", "Виктор", "Настя", "София", "Дмитрий", "Илья", "Арина", "Кирилл", "Кристина", "Роман" };
        grades = { 99, 76, 86, 95, 88, 84, 82, 75, 70, 73 };
    }
    else if (choice == 2) {
        // Инициализация на случайных значениях запрошенного размера
        int sampleSize;
        cout << "Введите желаемый размер выборки: ";
        cin >> sampleSize;

        for (int i = 0; i < sampleSize; i++) {
            string name;
            int grade;

            cout << "Введите имя студента: ";
            cin >> name;
            cout << "Введите оценку студента (от 0 до 100): ";
            cin >> grade;

            names.push_back(name);
            grades.push_back(grade);
        }
    }
    else if (choice == 3) {
        // Инициализация на значениях, введенных пользователем
        cout << "Введите имена и оценки студентов. Для завершения ввода введите пустую строку." << endl;

        while (true) {
            string name;
            int grade;

            cout << "Имя студента: ";
            cin >> name;

            if (name.empty()) {
                break;
            }

            cout << "Оценка студента (от 0 до 100): ";
            cin >> grade;

            names.push_back(name);
            grades.push_back(grade);
        }
    }
}

// Функция для вывода результатов анализа
void analyzeResults(const vector<string>& names, const vector<int>& grades) {
    // Выводим список студентов с их оценками
    cout << "\nСписок студентов и их оценок:" << endl;
    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i] << ": " << grades[i] << endl;
    }

    // Вычисляем среднюю оценку
    double averageGrade = 0.0;
    for (int grade : grades) {
        averageGrade += grade;
    }
    averageGrade /= grades.size();

    cout << "\nСредняя оценка: " << averageGrade << endl;

    // Определяем студентов с высокой оценкой (выше 90)
    vector<string> highGrades;
    for (size_t i = 0; i < names.size(); i++) {
        if (grades[i] > 90) {
            highGrades.push_back(names[i]);
        }
    }

    cout << "\nСтуденты с высокой оценкой:" << endl;
    if (!highGrades.empty()) {
        for (const string& name : highGrades) {
            cout << name << endl;
        }
    }
    else {
        cout << "Нет студентов с высокой оценкой." << endl;
    }
}
