cmake_minimum_required(VERSION 3.14)
project(BankManagementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankManagementSystem
        main.cpp
        employee.cpp
        customer.cpp
        transaction.cpp
        queue.cpp
        branch.cpp
        file.cpp
        category.cpp
        utils.cpp)
