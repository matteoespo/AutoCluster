#include "vehicledata.h"

VehicleData::VehicleData(QObject *parent)
    : QObject(parent), m_speed(0), m_rpm(800) // Start at 0 km/h and 800 RPM (idle)
{
    // Create a timer to simulate real-time sensor data
    m_timer = new QTimer(this);

    // Connect the timer's "timeout" signal to our "simulateData" function
    connect(m_timer, &QTimer::timeout, this, &VehicleData::simulateData);

    // Start the timer: it will trigger every 50 milliseconds (20 times a second)
    m_timer->start(50);
}

int VehicleData::speed() const { return m_speed; }
int VehicleData::rpm() const { return m_rpm; }

void VehicleData::setSpeed(int newSpeed)
{
    if (m_speed == newSpeed) return; // Don't do anything if the value hasn't changed

    m_speed = newSpeed;
    emit speedChanged(); // FIRE THE SIGNAL!
}

void VehicleData::setRpm(int newRpm)
{
    if (m_rpm == newRpm) return;

    m_rpm = newRpm;
    emit rpmChanged();
}

void VehicleData::simulateData()
{
    // 1. Simulate Acceleration
    int nextSpeed = m_speed + 1;
    if (nextSpeed > 160) {
        nextSpeed = 0; // Reset to 0 when we hit 160 km/h
    }
    setSpeed(nextSpeed);

    // 2. Simulate RPM and Gear Shifting
    int nextRpm = m_rpm + 80;
    if (nextRpm > 6500) {
        nextRpm = 1500; // Simulate the RPM dropping when the car shifts gears
    }
    setRpm(nextRpm);
}
