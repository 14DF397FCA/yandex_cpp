#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
    double quality;
    double freshness;
    double ratio;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }

    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        } else {
            return source_value - value;
        }
    }

    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else {
            operation = '+';
        }
    }

private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }

    double Apply(double value) const {
        for (const FunctionPart &item : parts) {
            value = item.Apply(value);
        }
        return value;
    }

    void Invert() {
        for (FunctionPart &part : parts) {
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    }

private:
    vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params &params, const Image &image) {
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.ratio * params.c);
    return function;
}

double ComputeImageWeight(const Params &params, const Image &image) {
//    double weight = image.quality;
//    weight -= image.freshness * params.a + params.b;
//    weight += image.ratio * params.c;
//    return weight;
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params, const Image &image, double weight) {
//    double quality = weight;
//    quality -= image.ratio * params.c;
//    quality += image.freshness * params.a + params.b;
//    return quality;
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    //  10-2*4-2+6*6 = 36
    cout << ComputeImageWeight(params, image) << endl;
    //  20-2*4-2+6*6 = 46
    cout << ComputeQualityByWeight(params, image, 46) << endl;
    return 0;
}