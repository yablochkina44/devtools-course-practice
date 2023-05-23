// Copyright 2023 Lebedinskiy Ilya

#include <utility>
#include <cmath>
#include "../include/lebedinskiy_ilya_triangle_basic_params.h"

Triangle::Triangle() {
    this->a = { 0, 3 };
    this->b = { 3, 6 };
    this->c = { 0, 0 };
}

Triangle::Triangle(std::pair<float, float> _a, std::pair<float, float> _b,
    std::pair<float, float> _c) {
    this->a = _a;
    this->b = _b;
    this->c = _c;
}

std::pair<float, float> Triangle::get_a_point() {
    return this->a;
}

std::pair<float, float> Triangle::get_b_point() {
    return this->b;
}

std::pair<float, float> Triangle::get_c_point() {
    return this->c;
}

void Triangle::set_a_point(std::pair<float, float> _p) {
    this->a = _p;
}

void Triangle::set_b_point(std::pair<float, float> _p) {
    this->b = _p;
}

void Triangle::set_c_point(std::pair<float, float> _p) {
    this->c = _p;
}

float Triangle::get_height(float _side) {
    float res = 2 / _side * this->get_square();
    return res;
}

float Triangle::get_side_lenght(std::pair<float, float> _a,
    std::pair<float, float> _b) {
    float _ac = _b.first - _a.first;
    float _bc = _b.second - _a.second;
    float res = sqrt((_ac * _ac) + (_bc * _bc));
    return res;
}

float Triangle::get_perimeter() {
    float _ab = this->get_side_lenght(this->a, this->b);
    float _bc = this->get_side_lenght(this->b, this->c);
    float _ca = this->get_side_lenght(this->c, this->a);
    float res = _ab + _bc + _ca;
    return res;
}

float Triangle::get_square() {
    float pp = this->get_perimeter() / 2;
    float _ab = this->get_side_lenght(this->a, this->b);
    float _bc = this->get_side_lenght(this->b, this->c);
    float _ca = this->get_side_lenght(this->c, this->a);
    float res = sqrt(pp * (pp - _ab) * (pp - _bc) * (pp - _ca));
    return res;
}

Triangle::~Triangle() {
    this->a = { 0, 0 };
    this->b = { 0, 0 };
    this->c = { 0, 0 };
}
