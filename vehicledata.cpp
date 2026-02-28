#include "vehicledata.h"

VehicleData::VehicleData(QObject *parent)
    : QObject(parent), m_speed(0), m_rpm(800), m_gear("P")
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
QString VehicleData::gear() const { return m_gear; }

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

void VehicleData::setGear(const QString &newGear)
{
    if (m_gear == newGear) return;
    m_gear = newGear;
    emit gearChanged();
}

void VehicleData::simulateData()
{
    // Simulate Acceleration
    int nextSpeed = m_speed + 1;
    if (nextSpeed > 160) {
        nextSpeed = 0;
    }
    setSpeed(nextSpeed);

    // Gear & RPM Logic
    int nextRpm = m_rpm + 80;
    QString currentGear = "D1";

    if (m_speed == 0) {
        currentGear = "P";
        nextRpm = 800; // Idle RPM
    } else if (m_speed < 40) {
        currentGear = "D1";
    } else if (m_speed < 80) {
        currentGear = "D2";
        if (nextRpm > 6000) nextRpm = 3000; // Simulate gear shift drop
    } else if (m_speed < 120) {
        currentGear = "D3";
        if (nextRpm > 6000) nextRpm = 3500;
    } else {
        currentGear = "D4";
        if (nextRpm > 6000) nextRpm = 4000;
    }

    setRpm(nextRpm);
    setGear(currentGear);
}
