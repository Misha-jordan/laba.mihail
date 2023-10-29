#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

float getAverage(const std::vector<int>& grades) {
    float sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

float getMedian(std::vector<int> grades) {
    std::sort(grades.begin(), grades.end());
    int size = grades.size();
    if (size % 2 == 0) {
        return (grades[size / 2 - 1] + grades[size / 2]) / 2.0;
    }
    else {
        return grades[size / 2];
    }
}

std::vector<int> getMode(const std::vector<int>& grades) {
    std::unordered_map<int, int> countMap;
    int maxCount = 0;
    for (int grade : grades) {
        countMap[grade]++;
        maxCount = std::max(maxCount, countMap[grade]);
    }
    std::vector<int> modeGrades;
    for (auto it = countMap.begin(); it != countMap.end(); ++it) {
        if (it->second == maxCount) {
            modeGrades.push_back(it->first);
        }
    }
    return modeGrades;
}

int main() {

    setlocale(LC_ALL, "ru");
    std::vector<std::string> names = { "Анна", "Виктор", "Настя", "София", "Дмитрий", "Илья", "Арина", "Кирилл", "Кристина", "Роман" };
    std::vector<int> grades = { 99, 76, 86, 95, 88, 84, 82, 75, 70, 73 };

    for (size_t i = 0; i < names.size(); i++) {
        std::cout << names[i] << ": " << grades[i] << std::endl;
    }

    std::cout << "Grades list:\n";
    for (int grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;

    float average = getAverage(grades);
    std::cout << "Average: " << average << std::endl;

    float median = getMedian(grades);
    std::cout << "Median: " << median << std::endl;

    std::vector<int> modeGrades = getMode(grades);
    std::cout << "Mode: ";
    for (int grade : modeGrades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;

    return 0;
}
