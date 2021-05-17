// Copyright 2021 Tkachev Alexey

#include "include/app_connectivity_components.h"
#include <vector>
#include <string>

#include <gtest/gtest.h>

TEST(Tkachev_connectivity_comp_app, creating) {
    ASSERT_NO_THROW(AppConnComponents());
}

TEST(Tkachev_connectivity_comp_app, no_args) {
    std::vector<const char*> argv {};
    const int argc = static_cast<int>(argv.size());

    AppConnComponents app;

    const std::string true_result = AppConnComponents::help();

    ASSERT_EQ(true_result, app(argc, argv.data()));
}

TEST(Tkachev_connectivity_comp_app, only_arg) {
    std::vector<const char*> argv {
        "app"
    };
    const int argc = static_cast<int>(argv.size());

    AppConnComponents app;

    const std::string true_result = AppConnComponents::help();

    ASSERT_EQ(true_result, app(argc, argv.data()));
}

TEST(Tkachev_connectivity_comp_app, invalid_arg) {
    std::vector<const char*> argv {
        "app",
        "something_wrong"
    };
    const int argc = static_cast<int>(argv.size());

    AppConnComponents app;

    const std::string true_result = "invalid arguments";

    ASSERT_EQ(true_result, app(argc, argv.data()));
}

TEST(Tkachev_connectivity_comp_app, create_set_get) {
    std::vector<const char*> argv {
        "app",
        "create", "3",
        "set",  "1", "1", "2",
        "get", "1", "2"
    };
    const int argc = static_cast<int>(argv.size());

    AppConnComponents app;

    const std::string true_result = "1";

    ASSERT_EQ(true_result, app(argc, argv.data()));
}


TEST(Tkachev_connectivity_comp_app, create_set_get_false) {
    std::vector<const char*> argv {
            "app",
            "create", "3",
            "set",  "0", "1", "2",
            "get", "1", "2"
    };
    const int argc = static_cast<int>(argv.size());

    AppConnComponents app;

    const std::string false_result = "1";

    ASSERT_EQ(false, false_result == app(argc, argv.data()));
}

TEST(Tkachev_connectivity_comp_app, create_many_set_many_get) {
    std::vector<const char*> argv {
            "app",
            "create", "5",
            "set",  "1", "1", "2",
            "set", "0", "1", "3",
            "get", "1", "2",
            "get", "1", "3"
    };
    const int argc = static_cast<int>(argv.size());

    AppConnComponents app;

    const std::string false_result = "0";

    ASSERT_EQ(false_result, app(argc, argv.data()));
}

TEST(Tkachev_connectivity_components_app, get_count_comp) {
    // analog of Pestreev's some_simple_graph test

    std::vector<const char*> argv {
            "app",
            "create", "7",
            "set",  "1", "0", "2",
            "set",  "1", "0", "3",
            "set",  "1", "1", "3",
            "set",  "1", "2", "0",
            "set",  "1", "3", "0",
            "set",  "1", "3", "1",
            "set",  "1", "4", "6",
            "set",  "1", "6", "4",
            "getcountcomps"
    };

    const int argc = static_cast<int>(argv.size());

    AppConnComponents app;
    const std::string result = app(argc, argv.data());
    const std::string true_result = "3";

    ASSERT_EQ(true_result, result);
}

TEST(Tkachev_connectivity_components_app, append_n_get_size) {
    // analog of Pestreev's some_simple_graph test

    std::vector<const char*> argv {
            "app",
            "create", "5",
            "append",
            "size"
    };

    const int argc = static_cast<int>(argv.size());

    AppConnComponents app;

    const std::string result = app(argc, argv.data());
    const std::string true_result = "6";

    ASSERT_EQ(true_result, result);
}




