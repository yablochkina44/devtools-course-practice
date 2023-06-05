// Copyright 2023 Kruglikova Valeriia

#ifndef  MODULES_INTERSECTIONS_INCLUDE_INTERSECTIONS_LINE_AND_PLANE_APP_H_
#define  MODULES_INTERSECTIONS_INCLUDE_INTERSECTIONS_LINE_AND_PLANE_APP_H_

#include <string>
#include <exception>
#include <cctype>
#include "include/intersections_line_and_plane.h"

class I3DApplication {
 public:
    I3DApplication();
    std::string operator()(int argc, const char** argv);
 private:
    std::string message_;
    void help(const char* appname);
};

#endif  //  MODULES_INTERSECTIONS_INCLUDE_INTERSECTIONS_LINE_AND_PLANE_APP_H_
