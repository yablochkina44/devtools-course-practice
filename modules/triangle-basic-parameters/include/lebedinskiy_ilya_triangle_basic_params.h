// Copyright 2023 Lebedinskiy Ilya

#ifndef MODULES_TRIANGLE_BASIC_PARAMETERS_INCLUDE_LEBEDINSKIY_ILYA_TRIANGLE_BASIC_PARAMS_H_
#define MODULES_TRIANGLE_BASIC_PARAMETERS_INCLUDE_LEBEDINSKIY_ILYA_TRIANGLE_BASIC_PARAMS_H_

#include <utility>
#include <vector>

class Triangle {
    std::pair<float, float> a;
    std::pair<float, float> b;
    std::pair<float, float> c;

 public:
    Triangle();
    Triangle(std::pair<float, float> _a, std::pair<float, float>
        _b, std::pair<float, float> _c);
    std::pair<float, float> get_a_point();
    std::pair<float, float> get_b_point();
    std::pair<float, float> get_c_point();
    void set_a_point(std::pair<float, float> _a);
    void set_b_point(std::pair<float, float> _b);
    void set_c_point(std::pair<float, float> _c);
    float get_height(float _side);
    float get_side_lenght(std::pair<float, float> _a,
        std::pair<float, float> _b);
    float get_perimeter();
    float get_square();
    ~Triangle();
};
#endif  // MODULES_TRIANGLE_BASIC_PARAMETERS_INCLUDE_LEBEDINSKIY_ILYA_TRIANGLE_BASIC_PARAMS_H_
