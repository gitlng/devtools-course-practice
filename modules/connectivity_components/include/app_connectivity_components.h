// Copyright 2021 Tkachev Alexey

#ifndef DEVTOOLS_APP_CONNECTIVITY_COMPONENTS_H
#define DEVTOOLS_APP_CONNECTIVITY_COMPONENTS_H

#include <string>
#include "include/connectivity_components.h"

class AppConnComponents {
 private:
  std::string response;
  Graph graph;

 public:
    AppConnComponents();
    static std::string help();
    std::string operator()(int argc, const char** argv);
};

#endif //DEVTOOLS_APP_CONNECTIVITY_COMPONENTS_H
