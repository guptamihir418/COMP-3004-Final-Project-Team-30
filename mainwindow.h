#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTimer>
#include <QtWidgets>

#include "session.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    float batteryLvl;   //the battery level of the device
    bool deviceOn;      //whether the device is on or off
    void displayBattery();
    void hideBattery();
    void displayLabels();
    void hideLabels();
    void hideSessionLabels();
    QElapsedTimer powerTimer;   //tracks how long the powerButton is pressed
    QTimer* blinkTimer;         //regulates how long a number is blinked for
    QTimer* connectionTimer;    //regulates how long the connection status is displayed
    int connectionStatus;       //1.No Connection 2. Okay Connection. 3. Excellent Connection
    int blinkCount;             //how long a number has blinked for (blinkCount * blinkTimer->interval)
    int connectionCount;        //how long connection status has been displayed for (connectionCount * connectionTimer->interval)
    int blinkingNum;            //the number that is being blinked (1-8)
    bool leftEarConnected;      //whether the left ear is connected or not
    bool rightEarConnected;     //whether the right ear is connected or not
    QLabel* currentGroup;
    QLabel* currentSession;
    void togglePower();
    void blinkNumber();
    void navigateSessionGroups();
    void displaySessionLabel(QLabel* label);
    void testConnection();
    void displayConnectionStatus();
    void selectUpButtonAction();
    void selectDownButtonAction();
    void lightUpGroups();
    Session session;
    int operation; //1 is to select session, 2 is to select intensity, 3 is to go up and down in history
    void showIntensity(int);

    // Therapy* therapies[MAX_THERAPY_COUNT];

private slots:
    void startPowerTimer();
    void selectPowerAction();
    void toggleLeftEarConnection();
    void toggleRightEarConnection();
    void displayHistory();
    void assignSession(int);
    void sessionOff();
};
#endif // MAINWINDOW_H
