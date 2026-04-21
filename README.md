# Automotive Digital Instrument Cluster

A real-time digital instrument cluster simulator built with **C++** and **Qt Quick / QML**. 

## 📸 Preview
*SOON*

## Key Features
* **C++ Backend Simulator:** Generates realistic, real-time telemetry data (Speed, RPM, Gear state).
* **QML UI Integration:** Uses `QML_ELEMENT` and Qt Property Bindings for instant, zero-lag UI updates.
* **Vector Graphics:** Utilizes `QtQuick.Shapes` for smooth, anti-aliased, scalable gauge rendering.
* **Thread Safety:** (Planned) Separation of high-frequency data generation from the main GUI thread.

## How to Build and Run
1. Ensure you have **Qt 6** and **CMake** installed.
2. Clone this repository: ``git clone https://github.com/matteoespo/AutoCluster.git``
3. Open the ``CMakeLists.txt`` file in Qt Creator.
4. Configure the project using your desktop kit (e.g., MinGW or MSVC).
5. Build and Run.
