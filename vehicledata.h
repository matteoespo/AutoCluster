#ifndef VEHICLEDATA_H
#define VEHICLEDATA_H

#include <QObject>
#include <QTimer>
#include <QtQml/qqmlregistration.h>

class VehicleData : public QObject
{
    Q_OBJECT
    QML_ELEMENT // Tells Qt 6: "Make this C++ class available inside QML!"

    // These are the bridges to QML. If the C++ value changes, it emits a NOTIFY signal.
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int rpm READ rpm WRITE setRpm NOTIFY rpmChanged)

public:
    explicit VehicleData(QObject *parent = nullptr);

    // Getters
    int speed() const;
    int rpm() const;

    // Setters
    void setSpeed(int newSpeed);
    void setRpm(int newRpm);

signals:
    // QML listens for these signals to know when to redraw the screen
    void speedChanged();
    void rpmChanged();

private slots:
    // Internal loop to fake the engine running
    void simulateData();

private:
    int m_speed;
    int m_rpm;
    QTimer *m_timer;
};

#endif // VEHICLEDATA_H
