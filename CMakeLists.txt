cmake_minimum_required(VERSION 3.14)
project(StockMarketSimulator)

set(CMAKE_CXX_STANDARD 17)

# Enable vcpkg
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain")

include_directories(include)

add_executable(StockMarketSimulator
    src/main.cpp
    src/api_handler.cpp
    src/portfolio.cpp
    src/strategy.cpp
    src/utils.cpp
)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(StockMarketSimulator PRIVATE cpr::cpr nlohmann_json::nlohmann_json)
