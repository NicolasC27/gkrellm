#include <QTimer>
#include <iterator>
#include <list>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  QTimer *time = new QTimer;
  ui->setupUi(this);
  ui->progressBar_4->setStyleSheet("background-color : #007f00;");
  QWidget::connect(time, SIGNAL(timeout()), this, SLOT(UpdateBattery()));
  QWidget::connect(time, SIGNAL(timeout()), this, SLOT(UpdateDateTime()));
  QWidget::connect(time, SIGNAL(timeout()), this, SLOT(UpdateActivity()));
  QWidget::connect(time, SIGNAL(timeout()), this, SLOT(UpdateRam()));
  QWidget::connect(time, SIGNAL(timeout()), this, SLOT(UpdateNet()));
  /*QPixmap bkgnd("/home/gerard_v/TekMonitor/images/image.jpg");
  QPalette palette;
  palette.setBrush(QPalette::Background, bkgnd);
  this->setPalette(palette);*/
  this->setFixedSize(813, 471);
  ui->label->setText(this->system.getOSVersion().c_str());
  ui->label_2->setText(this->system.getVersion().c_str());
  ui->progressBar_4->setValue(this->battery.getBatteryLevel());

  ui->groupBox->setTitle(std::string("CPU").c_str());
  ui->progressBar_3->setValue(this->cpu.cpu[0]);
  ui->progressBar->setValue(this->cpu.cpu[1]);
  ui->progressBar_2->setValue(this->cpu.cpu[2]);
  ui->progressBar_6->setValue(this->cpu.cpu[3]);
  ui->progressBar_5->setMinimum(0);
  ui->progressBar_5->setMaximum(this->ram.getTotalRam());
  ui->progressBar_5->setValue(this->ram.getOccupRam());

  ui->label_9->setText(std::to_string(this->ram.getOccupRam()).c_str());
  ui->label_10->setText(std::to_string(this->ram.getAvailRam()).c_str());
  ui->label_26->setText(this->cpu.getModel().c_str());


  ui->label_31->setText(this->user.getUserName().c_str());
  ui->label_33->setText(this->user.getMachineName().c_str());
  ui->label_3->setText(this->date.getTime().c_str());
  ui->label_4->setText(this->date.getDate().c_str());

  this->net.update();
  ui->label_5->setText(this->net.getIface().c_str());
  ui->label_8->setText(std::to_string(this->net.getReceive_bytes()).c_str());
  ui->label_11->setText(std::to_string(this->net.getReceive_packets()).c_str());
  ui->label_12->setText(std::to_string(this->net.getTrans_bytes()).c_str());
  ui->label_13->setText(std::to_string(this->net.getTrans_packet()).c_str());
  ui->label_20->setText(std::to_string(this->ram.getTotalRam() / 1000).c_str());

  time->start(1000);
}

void MainWindow::UpdateBattery()
{
  if (this->battery.getACStatus() == 1)
    ui->label_35->setEnabled(true);
  else
    ui->label_35->setEnabled(false);
  ui->progressBar_4->setValue(this->battery.getBatteryLevel());
  if (ui->progressBar_4->value() <= 25 && ui->progressBar_4->value() > 10)
    ui->progressBar_4->setStyleSheet("background-color : Orange");
  else if (ui->progressBar_4->value() <= 10)
    ui->progressBar_4->setStyleSheet("background-color : Red;");
  else
    ui->progressBar_4->setStyleSheet("background-color : #007f00;");
}

void MainWindow::UpdateDateTime()
{
  ui->label_3->setText(this->date.getTime().c_str());
  ui->label_4->setText(this->date.getDate().c_str());
}

void MainWindow::UpdateActivity()
{
  this->cpu.setActivity();
  ui->progressBar_3->setValue(this->cpu.cpu[0]);
  ui->progressBar->setValue(this->cpu.cpu[1]);
  ui->progressBar_2->setValue(this->cpu.cpu[2]);
  ui->progressBar_6->setValue(this->cpu.cpu[3]);
}

void MainWindow::UpdateRam()
{
  this->ram.setAvailRam();
  this->ram.getTotalRam();
  this->ram.setOccupRam();
  ui->progressBar_5->setValue(this->ram.getOccupRam());
  //ui->label_8->setText(std::to_string(this->ram.getTotalRam() / 1000).c_str());
  ui->label_9->setText(std::to_string(this->ram.getOccupRam() / 1000).c_str());
  ui->label_10->setText(std::to_string(this->ram.getAvailRam() / 1000).c_str());
}

void MainWindow::UpdateNet()
{
  this->net.update();
  ui->label_5->setText(this->net.getIface().c_str());
  ui->label_8->setText(std::to_string(this->net.getReceive_bytes()).c_str());
  ui->label_11->setText(std::to_string(this->net.getReceive_packets()).c_str());
  ui->label_12->setText(std::to_string(this->net.getTrans_bytes()).c_str());
  ui->label_13->setText(std::to_string(this->net.getTrans_packet()).c_str());
}

MainWindow::~MainWindow()
{
  delete ui;
}
