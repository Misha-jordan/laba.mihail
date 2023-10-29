
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// Функция для расчета среднего значения оценок
double calculateMean(const std::vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

// Функция для расчета медианы оценок
double calculateMedian(const std::vector<int>& grades) {
    std::vector<int> sortedGrades = grades;
    std::sort(sortedGrades.begin(), sortedGrades.end());
    if (grades.size() % 2 == 0) {
        int middleIndex1 = grades.size() / 2 - 1;
        int middleIndex2 = grades.size() / 2;
        return static_cast<double>(sortedGrades[middleIndex1] + sortedGrades[middleIndex2]) / 2;
    }
    else {
        int middleIndex = grades.size() / 2;
        return sortedGrades[middleIndex];
    }
}

// Функция для расчета моды оценок
std::vector<int> calculateMode(const std::vector<int>& grades) {
    std::map<int, int> gradeCount;
    int maxCount = 0;
    for (int grade : grades) {
        gradeCount[grade]++;
        maxCount = std::max(maxCount, gradeCount[grade]);
    }
    std::vector<int> modeGrades;
    for (const auto& pair : gradeCount) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }
    return modeGrades;
}

int main() {
    setlocale(LC_ALL, "ru");

    std::vector<std::string> names = { "Анна", "Виктор", "Настя", "София", "Дмитрий", "Илья", "Арина", "Кирилл", "Кристина", "Роман"};
    std::vector<int> grades = { 99, 76, 86, 95, 88, 84, 82, 75, 70, 73 };

    // Вывод списка имен и оценок
    for (size_t i = 0; i < names.size(); i++) {
        std::cout << names[i] << ": " << grades[i] << std::endl;
    }

    // Расчет и вывод среднего значения оценок
    double mean = calculateMean(grades);
    std::cout << "Mean: " << mean << std::endl;

    // Расчет и вывод медианы оценок
    double median = calculateMedian(grades);
    std::cout << "Median: " << median << std::endl;

    // Расчет и вывод моды оценок
    std::vector<int> modeGrades = calculateMode(grades);
    std::cout << "Mode: ";
    for (int grade : modeGrades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;

    // Вывод списка имен, оценка которых соответствует моде
    std::cout << "Names corresponding to mode: ";
    for (size_t i = 0; i < grades.size(); i++) {
        if (std::find(modeGrades.begin(), modeGrades.end(), grades[i]) != modeGrades.end()) {
            std::cout << names[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

