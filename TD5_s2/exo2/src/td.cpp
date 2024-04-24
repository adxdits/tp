#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>
std::string random_name(size_t size) {
    std::string name {""};
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        std::string robotName { random_name(2) };
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(const std::vector<std::pair<std::string, float>>& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> repairs_map;

    for (const auto& fix : robots_fixes) {
        repairs_map[fix.first].push_back(fix.second);
    }

    return repairs_map;
}

float sum_of_vector(const std::vector<float>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0.0f);
}
int main() {
    std::vector<std::pair<std::string, float>> robots_fixes = get_robots_fix(20);
    std::unordered_map<std::string, std::vector<float>> repairs_map = robots_fixes_map(robots_fixes);

    for (const auto& pair : repairs_map) {
        std::cout << "Robot: " << pair.first << std::endl << "et le total cst: " << sum_of_vector(pair.second) << "euro." <<std::endl;
    }

    return 0;
}
