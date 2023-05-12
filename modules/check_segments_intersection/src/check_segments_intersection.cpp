// Copyright 2023 Tychinin Alexey

#include "include/check_segments_intersection.h"

namespace geom {
bool check_segments_intersection(const Segment& s1, const Segment& s2) {
    double t1 = ( (s2.p1.x-s2.p2.x) * (s1.p1.y-s2.p1.y) -
        (s1.p1.x-s2.p1.x) * (s2.p1.y-s2.p2.y) );
    double t2 = ( (s1.p1.x-s1.p2.x) * (s1.p1.y-s2.p1.y) -
        (s1.p1.x-s2.p1.x) * (s1.p1.y-s1.p2.y) );
    double z = ( (s2.p1.x-s2.p2.x) * (s1.p1.y-s1.p2.y) -
        (s1.p1.x-s1.p2.x) * (s2.p1.y-s2.p2.y) );

    if (z > 0) {
        return t1 >= 0 && t1<= z && t2 >= 0 && t2 <= z;
    } else if (z < 0) {
        return t1 <= 0 && t1>= z && t2 <= 0 && t2 >= z;
    } else {
        return t1 == 0 && t2 ==0 && s1.p2.x >= s2.p1.x;
    }
}
}  // namespace geom
