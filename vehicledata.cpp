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
        nextSpeed = 0; // Reset to 0 when we hit max speed
    }
    setSpeed(nextSpeed);

    // Synchronized Gear & RPM Logic
    int nextRpm = 800; // Default idle RPM
    QString currentGear = "P";

    if (nextSpeed == 0) {
        currentGear = "P";
        nextRpm = 800; // Idle
    }
    // GEAR D1 (Speed 1 to 40)
    else if (nextSpeed <= 40) {
        currentGear = "D1";
        // Map speed (1-40) to an RPM range of (1000-6000)
        nextRpm = 1000 + ((nextSpeed - 0) * 5000 / 40);
    }
    // GEAR D2 (Speed 41 to 80)
    else if (nextSpeed <= 80) {
        currentGear = "D2";
        // Map speed (41-80) to an RPM range of (2000-6000)
        nextRpm = 2000 + ((nextSpeed - 40) * 4000 / 40);
    }
    // GEAR D3 (Speed 81 to 120)
    else if (nextSpeed <= 120) {
        currentGear = "D3";
        // Map speed (81-120) to an RPM range of (2500-6000)
        nextRpm = 2500 + ((nextSpeed - 80) * 3500 / 40);
    }
    // GEAR D4 (Speed 121 to 160)
    else {
        currentGear = "D4";
        // Map speed (121-160) to an RPM range of (3000-6000)
        nextRpm = 3000 + ((nextSpeed - 120) * 3000 / 40);
    }

    setRpm(nextRpm);
    setGear(currentGear);
}
