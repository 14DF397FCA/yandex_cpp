#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

//enum class Lang {
//    DE, FR, IT
//};
//
//struct Region {
//    string std_name;
//    string parent_std_name;
//    map<Lang, string> names;
//    int64_t population;
//};

auto make_tuple_from_region(const Region &r) {
    return tie(r.std_name, r.parent_std_name, r.names, r.population);
}

bool operator<(const Region &r1, const Region &r2) {
    return make_tuple_from_region(r1) < make_tuple_from_region(r2);
}

int FindMaxRepetitionCount(const vector<Region> &regions) {
    if (regions.empty()) {
        return 0;
    }
    map<Region, unsigned> regions_num;
    for (const auto &item : regions) {
        ++regions_num[item];
    }
    unsigned max_repetition = 0;
    for (const auto &item : regions_num) {
        if (item.second > max_repetition) {
            max_repetition = item.second;
        }
    }
    return max_repetition;
}

int main() {
    std::cout << FindMaxRepetitionCount({
                                                {
                                                        "Moscow",
                                                        "Russia",
                                                        {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                        89
                                                },
                                                {
                                                        "Russia",
                                                        "Eurasia",
                                                        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                        89
                                                },
                                                {
                                                        "Moscow",
                                                        "Russia",
                                                        {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                        89
                                                },
                                                {
                                                        "Moscow",
                                                        "Russia",
                                                        {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                        89
                                                },
                                                {
                                                        "Russia",
                                                        "Eurasia",
                                                        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                        89
                                                },
                                        }) << std::endl;

    std::cout << FindMaxRepetitionCount({
                                                {
                                                        "Moscow",
                                                        "Russia",
                                                        {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                                                        89
                                                },
                                                {
                                                        "Russia",
                                                        "Eurasia",
                                                        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"},      {Lang::IT, "Russia"}},
                                                        89
                                                },
                                                {
                                                        "Moscow",
                                                        "Russia",
                                                        {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                                                        89
                                                },
                                                {
                                                        "Moscow",
                                                        "Toulouse",
                                                        {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                                                        89
                                                },
                                                {
                                                        "Moscow",
                                                        "Russia",
                                                        {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                                                        31
                                                },
                                        }) << std::endl;


    return 0;
}