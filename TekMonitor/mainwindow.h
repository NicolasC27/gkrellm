#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "includes/modules/Date.hpp"
#include "includes/modules/User.hpp"
#include "includes/modules/System.hpp"
#include "includes/modules/Battery.hpp"
#include "includes/modules/Cpu.hpp"
#include "includes/modules/Ram.hpp"
#include "includes/modules/NetworkLoad.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
  {
    Q_OBJECT

    public slots:
    void UpdateBattery();
    void UpdateDateTime();
    void UpdateActivity();
    void UpdateRam();
    void UpdateNet();
  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private:
    Ui::MainWindow *ui;
    Date date;
    User user;
    System system;
    Battery battery;
    Cpu cpu;
    Ram ram;
    NetworkLoad net;
  };

#endif // MAINWINDOW_H
