# Automotive Digital Instrument Cluster 🏎️

A high-performance, real-time digital instrument cluster simulator built with **C++** and **Qt Quick / QML**. 

This project demonstrates a clean separation of concerns, which is standard in the Automotive (IVI) and embedded systems industries: a robust C++ backend handling data simulation and logic, seamlessly bridged to a hardware-accelerated QML frontend.

## 📸 Preview
*SOON*

## 🛠️ Tech Stack
* **Backend:** Modern C++ (C++17)
* **Frontend:** Qt Quick / QML (Qt 6)
* **Build System:** CMake
* **Architecture:** Model-View-ViewModel (MVVM) principles using Qt's Meta-Object System (`Q_PROPERTY`, Signals, and Slots).

## 🚀 Key Features
* **C++ Backend Simulator:** Generates realistic, real-time telemetry data (Speed, RPM, Gear state).
* **QML UI Integration:** Uses `QML_ELEMENT` and Qt Property Bindings for instant, zero-lag UI updates.
* **Vector Graphics:** Utilizes `QtQuick.Shapes` for smooth, anti-aliased, scalable gauge rendering.
* **Thread Safety:** (Planned) Separation of high-frequency data generation from the main GUI thread.

## ⚙️ How to Build and Run
1. Ensure you have **Qt 6** and **CMake** installed.
2. Clone this repository: ``git clone https://github.com/matteoespo/AutoCluster.git``
3. Open the ``CMakeLists.txt`` file in Qt Creator.
4. Configure the project using your desktop kit (e.g., MinGW or MSVC).
5. Build and Run.

## 🧠 Future Roadmap
    [ ] Add circular dynamic speedometer using QML Canvas/Shapes.

    [ ] Implement a state machine for gear shifting (P, R, N, D).

    [ ] Add turn signals and warning indicators.

    [ ] Transition data generation to a separate C++ worker thread.
