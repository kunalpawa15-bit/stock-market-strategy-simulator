# 📊 Stock Market Strategy Simulator

A C++ command-line application that simulates buying and selling stocks using **live market data** and a simple **SMA (Simple Moving Average)** strategy. It features real-time stock tracking, profit/loss calculation, and CSV export functionality.

---

## 🚀 Features

- ✅ Fetches **live stock prices** using a public REST API (via CPR & nlohmann/json)
- ✅ Supports **interactive CLI** to buy/sell stocks
- ✅ Tracks **portfolio**, calculates **profit/loss**
- ✅ Implements **SMA-based automated trading strategy**
- ✅ Exports **portfolio to CSV** (`portfolio.csv`)
- ✅ Converts stock value from **USD to INR**

---

## 🛠️ Tech Stack

- **C++17**
- [CPR](https://github.com/libcpr/cpr) – HTTP requests
- [nlohmann/json](https://github.com/nlohmann/json) – JSON parsing
- **CMake** + **vcpkg** – Dependency management

---

## 🖥️ How to Build

```bash
git clone https://github.com/kunalpawa15-bit/stock-market-strategy-simulator.git
cd stock-market-strategy-simulator

# Install dependencies (with vcpkg)
./vcpkg/vcpkg install cpr nlohmann-json

# Build project
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build

# Run
./build/simulator
