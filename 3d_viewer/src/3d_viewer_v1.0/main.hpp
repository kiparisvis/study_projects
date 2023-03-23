#define GL_SILENCE_DEPRECATION
// #pragma once
#include <QApplication>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QTimer>
#include <QWheelEvent>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cerrno>
#include <fstream>
#include <iostream>

#include "qgifimage.h"
using namespace std;

extern "C" {
#include "parser/parser.h"
}
enum { NONE, SQUARE, ROUND };

class Viewer3d : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  Viewer3d(QWidget *parent = nullptr);
  ~Viewer3d() override;
  void saveJpeg(const QString &filename);
  void saveBmp(const QString &filename);
  void changepos_x(double xMov);
  void changepos_y(double yMov);
  void changepos_z(double zMov);
  double xMov = 0.01, yMov = 0.01, zMov = 0.01;
  void initializeGL() override;
  void load_settings();
  void paintGL() override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
  void changeBackround(double r, double b, double g);
  void changeBackgroundR(double c);
  void changeBackgroundG(double c);
  void changeBackgroundB(double c);
  void changePointR(double c);
  void changePointG(double c);
  void changePointB(double c);
  void changeLineR(double c);
  void changeLineG(double c);
  void changeLineB(double c);
  void bla();
  void load_file(QString filename);
  void changePointType(short int type);
  void setPointWidth(double pw);
  void setParallel(bool parallel_);
  void setLineWidth(double lw);
  void setDottedLine(bool dl);
  void rotate(double xr, double yr, double zr);
  void zoom_on(double zz);
  void saveGif();
  data_t data = {};

 private:
  QImage grabFramebuffer();
  QPoint mPos;
  double xRot, yRot;
  double scaleValue;
  bool leftButton, rightButton;
  double backR = 0, backG = 0, backB = 0;
  double lineR = 1, lineG = 1, lineB = 1;
  double pointR = 0, pointG = 0, pointB = 0;
  double lineWidth = 1;
  double pointWidth = 1;
  short int pointType = NONE;
  bool parallel = false;
  bool dottedline = false;
  int time;
  QTimer *timer;
  QGifImage *gif;
};

class MainWindow : public QMainWindow {
 public:
  MainWindow() {
    this->setObjectName(QString::fromUtf8("3DVIEWER_V1.0"));
    this->resize(2560, 1302);

    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    horizontalLayoutWidget_8 = new QWidget(centralwidget);
    horizontalLayoutWidget_8->setObjectName(
        QString::fromUtf8("horizontalLayoutWidget_8"));
    horizontalLayoutWidget_8->setGeometry(QRect(10, 0, 1271, 1131));
    horizontalLayout_13 = new QHBoxLayout(horizontalLayoutWidget_8);
    horizontalLayout_13->setObjectName(
        QString::fromUtf8("horizontalLayout_13"));
    horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
    verticalLayout_11 = new QVBoxLayout();
    verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
    vwr = new Viewer3d(horizontalLayoutWidget_8);
    vwr->setObjectName(QString::fromUtf8("vwr"));
    verticalLayout_11->addWidget(vwr);
    verticalLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
    verticalLayout->setSpacing(-1);
#endif
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, -1, -1);
    label_4 = new QLabel(horizontalLayoutWidget_8);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    verticalLayout->addWidget(label_4);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_5 = new QLabel(horizontalLayoutWidget_8);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    horizontalLayout->addWidget(label_5);

    label_6 = new QLabel(horizontalLayoutWidget_8);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    horizontalLayout->addWidget(label_6);

    label_7 = new QLabel(horizontalLayoutWidget_8);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    horizontalLayout->addWidget(label_7);

    verticalLayout->addLayout(horizontalLayout);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    pushButton_23 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));

    horizontalLayout_2->addWidget(pushButton_23);

    pushButton_24 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));

    horizontalLayout_2->addWidget(pushButton_24);

    pushButton_25 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));

    horizontalLayout_2->addWidget(pushButton_25);

    verticalLayout->addLayout(horizontalLayout_2);

    verticalLayout->setStretch(2, 1);

    verticalLayout_11->addLayout(verticalLayout);

    verticalLayout_11->setStretch(0, 1);

    horizontalLayout_13->addLayout(verticalLayout_11);

    verticalLayout_12 = new QVBoxLayout();
    verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label_3 = new QLabel(horizontalLayoutWidget_8);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    verticalLayout_2->addWidget(label_3);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    lineEdit_2 = new QLineEdit(horizontalLayoutWidget_8);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
    lineEdit_2->setInputMethodHints(Qt::ImhDigitsOnly);

    horizontalLayout_3->addWidget(lineEdit_2);

    lineEdit = new QLineEdit(horizontalLayoutWidget_8);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setInputMethodHints(Qt::ImhDigitsOnly);

    horizontalLayout_3->addWidget(lineEdit);

    lineEdit_3 = new QLineEdit(horizontalLayoutWidget_8);
    lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
    lineEdit_3->setInputMethodHints(Qt::ImhDigitsOnly);

    horizontalLayout_3->addWidget(lineEdit_3);
    ////
    verticalLayout_2->addLayout(horizontalLayout_3);

    horizontalLayout_7 = new QHBoxLayout();
    horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    pushButton = new QPushButton(horizontalLayoutWidget_8);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    horizontalLayout_4->addWidget(pushButton);

    pushButton_4 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

    horizontalLayout_4->addWidget(pushButton_4);

    horizontalLayout_7->addLayout(horizontalLayout_4);

    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    pushButton_2 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    horizontalLayout_5->addWidget(pushButton_2);

    pushButton_5 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

    horizontalLayout_5->addWidget(pushButton_5);

    horizontalLayout_7->addLayout(horizontalLayout_5);

    horizontalLayout_6 = new QHBoxLayout();
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    pushButton_3 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

    horizontalLayout_6->addWidget(pushButton_3);

    pushButton_6 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

    horizontalLayout_6->addWidget(pushButton_6);

    horizontalLayout_7->addLayout(horizontalLayout_6);

    verticalLayout_2->addLayout(horizontalLayout_7);

    verticalLayout_12->addLayout(verticalLayout_2);

    verticalLayout_10 = new QVBoxLayout();
    verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
    label_13 = new QLabel(horizontalLayoutWidget_8);
    label_13->setObjectName(QString::fromUtf8("label_13"));

    verticalLayout_10->addWidget(label_13);

    horizontalLayout_20 = new QHBoxLayout();
    horizontalLayout_20->setObjectName(
        QString::fromUtf8("horizontalLayout_20"));
    horizontalSlider_15 = new QSlider(horizontalLayoutWidget_8);
    horizontalSlider_15->setObjectName(
        QString::fromUtf8("horizontalSlider_15"));
    horizontalSlider_15->setOrientation(Qt::Horizontal);

    horizontalLayout_20->addWidget(horizontalSlider_15);

    horizontalSlider_16 = new QSlider(horizontalLayoutWidget_8);
    horizontalSlider_16->setObjectName(
        QString::fromUtf8("horizontalSlider_16"));
    horizontalSlider_16->setOrientation(Qt::Horizontal);

    horizontalLayout_20->addWidget(horizontalSlider_16);

    horizontalSlider_17 = new QSlider(horizontalLayoutWidget_8);
    horizontalSlider_17->setObjectName(
        QString::fromUtf8("horizontalSlider_17"));
    horizontalSlider_17->setOrientation(Qt::Horizontal);

    horizontalLayout_20->addWidget(horizontalSlider_17);

    verticalLayout_10->addLayout(horizontalLayout_20);

    verticalLayout_12->addLayout(verticalLayout_10);

    verticalLayout_9 = new QVBoxLayout();
    verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
    label_11 = new QLabel(horizontalLayoutWidget_8);
    label_11->setObjectName(QString::fromUtf8("label_11"));

    verticalLayout_9->addWidget(label_11);

    horizontalSlider_7 = new QSlider(horizontalLayoutWidget_8);
    horizontalSlider_7->setObjectName(QString::fromUtf8("horizontalSlider_7"));
    horizontalSlider_7->setOrientation(Qt::Horizontal);

    verticalLayout_9->addWidget(horizontalSlider_7);

    verticalLayout_12->addLayout(verticalLayout_9);

    verticalLayout_7 = new QVBoxLayout();
    verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
    label_10 = new QLabel(horizontalLayoutWidget_8);
    label_10->setObjectName(QString::fromUtf8("label_10"));

    verticalLayout_7->addWidget(label_10);

    horizontalLayout_21 = new QHBoxLayout();
    horizontalLayout_21->setObjectName(
        QString::fromUtf8("horizontalLayout_21"));
    pushButton_20 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));

    horizontalLayout_21->addWidget(pushButton_20);

    pushButton_22 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));

    horizontalLayout_21->addWidget(pushButton_22);

    pushButton_21 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));

    horizontalLayout_21->addWidget(pushButton_21);

    verticalLayout_7->addLayout(horizontalLayout_21);

    verticalLayout_12->addLayout(verticalLayout_7);

    horizontalLayout_15 = new QHBoxLayout();
    horizontalLayout_15->setObjectName(
        QString::fromUtf8("horizontalLayout_15"));
    pushButton_15 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

    horizontalLayout_15->addWidget(pushButton_15);

    pushButton_14 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

    horizontalLayout_15->addWidget(pushButton_14);

    verticalLayout_12->addLayout(horizontalLayout_15);

    verticalLayout_4 = new QVBoxLayout();
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    label = new QLabel(horizontalLayoutWidget_8);
    label->setObjectName(QString::fromUtf8("label"));

    verticalLayout_4->addWidget(label);

    lineEdit_8 = new QLineEdit(horizontalLayoutWidget_8);
    lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
    lineEdit_8->setInputMethodHints(Qt::ImhDigitsOnly);

    verticalLayout_4->addWidget(lineEdit_8);

    horizontalLayout_14 = new QHBoxLayout();
    horizontalLayout_14->setObjectName(
        QString::fromUtf8("horizontalLayout_14"));
    pushButton_32 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));

    horizontalLayout_14->addWidget(pushButton_32);

    pushButton_33 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));

    horizontalLayout_14->addWidget(pushButton_33);

    verticalLayout_4->addLayout(horizontalLayout_14);

    verticalLayout_12->addLayout(verticalLayout_4);

    verticalLayout_8 = new QVBoxLayout();
    verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
    label_12 = new QLabel(horizontalLayoutWidget_8);
    label_12->setObjectName(QString::fromUtf8("label_12"));

    verticalLayout_8->addWidget(label_12);

    horizontalLayout_19 = new QHBoxLayout();
    horizontalLayout_19->setObjectName(
        QString::fromUtf8("horizontalLayout_19"));
    horizontalSlider_12 = new QSlider(horizontalLayoutWidget_8);
    horizontalSlider_12->setObjectName(
        QString::fromUtf8("horizontalSlider_12"));
    horizontalSlider_12->setOrientation(Qt::Horizontal);

    horizontalLayout_19->addWidget(horizontalSlider_12);

    horizontalSlider_13 = new QSlider(horizontalLayoutWidget_8);
    horizontalSlider_13->setObjectName(
        QString::fromUtf8("horizontalSlider_13"));
    horizontalSlider_13->setOrientation(Qt::Horizontal);

    horizontalLayout_19->addWidget(horizontalSlider_13);

    horizontalSlider_14 = new QSlider(horizontalLayoutWidget_8);
    horizontalSlider_14->setObjectName(
        QString::fromUtf8("horizontalSlider_14"));
    horizontalSlider_14->setOrientation(Qt::Horizontal);

    horizontalLayout_19->addWidget(horizontalSlider_14);

    verticalLayout_8->addLayout(horizontalLayout_19);

    verticalLayout_12->addLayout(verticalLayout_8);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    label_14 = new QLabel(horizontalLayoutWidget_8);
    label_14->setObjectName(QString::fromUtf8("label_14"));

    verticalLayout_3->addWidget(label_14);

    horizontalLayout_8 = new QHBoxLayout();
    horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
    lineEdit_7 = new QLineEdit(horizontalLayoutWidget_8);
    lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
    lineEdit_7->setInputMethodHints(Qt::ImhDigitsOnly);

    horizontalLayout_8->addWidget(lineEdit_7);

    lineEdit_9 = new QLineEdit(horizontalLayoutWidget_8);
    lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
    lineEdit_9->setInputMethodHints(Qt::ImhDigitsOnly);

    horizontalLayout_8->addWidget(lineEdit_9);

    lineEdit_10 = new QLineEdit(horizontalLayoutWidget_8);
    lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
    lineEdit_10->setInputMethodHints(Qt::ImhDigitsOnly);

    horizontalLayout_8->addWidget(lineEdit_10);

    verticalLayout_3->addLayout(horizontalLayout_8);

    horizontalLayout_9 = new QHBoxLayout();
    horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
    horizontalLayout_10 = new QHBoxLayout();
    horizontalLayout_10->setObjectName(
        QString::fromUtf8("horizontalLayout_10"));
    pushButton_26 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));

    horizontalLayout_10->addWidget(pushButton_26);

    pushButton_27 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));

    horizontalLayout_10->addWidget(pushButton_27);

    horizontalLayout_9->addLayout(horizontalLayout_10);

    horizontalLayout_11 = new QHBoxLayout();
    horizontalLayout_11->setObjectName(
        QString::fromUtf8("horizontalLayout_11"));
    pushButton_28 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));

    horizontalLayout_11->addWidget(pushButton_28);

    pushButton_29 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));

    horizontalLayout_11->addWidget(pushButton_29);

    horizontalLayout_9->addLayout(horizontalLayout_11);

    horizontalLayout_12 = new QHBoxLayout();
    horizontalLayout_12->setObjectName(
        QString::fromUtf8("horizontalLayout_12"));
    pushButton_30 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));

    horizontalLayout_12->addWidget(pushButton_30);

    pushButton_31 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));

    horizontalLayout_12->addWidget(pushButton_31);

    horizontalLayout_9->addLayout(horizontalLayout_12);

    verticalLayout_3->addLayout(horizontalLayout_9);

    verticalLayout_12->addLayout(verticalLayout_3);

    verticalLayout_5 = new QVBoxLayout();
    verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
    label_8 = new QLabel(horizontalLayoutWidget_8);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    verticalLayout_5->addWidget(label_8);

    horizontalLayout_16 = new QHBoxLayout();
    horizontalLayout_16->setObjectName(
        QString::fromUtf8("horizontalLayout_16"));
    pushButton_18 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

    horizontalLayout_16->addWidget(pushButton_18);

    pushButton_19 = new QPushButton(horizontalLayoutWidget_8);
    pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));

    horizontalLayout_16->addWidget(pushButton_19);

    verticalLayout_5->addLayout(horizontalLayout_16);

    verticalLayout_12->addLayout(verticalLayout_5);

    verticalLayout_6 = new QVBoxLayout();
    verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
    label_9 = new QLabel(horizontalLayoutWidget_8);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    verticalLayout_6->addWidget(label_9);

    horizontalSlider_4 = new QSlider(horizontalLayoutWidget_8);
    horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
    horizontalSlider_4->setOrientation(Qt::Horizontal);

    verticalLayout_6->addWidget(horizontalSlider_4);

    verticalLayout_12->addLayout(verticalLayout_6);

    horizontalLayout_13->addLayout(verticalLayout_12);

    horizontalLayout_13->setStretch(0, 1);
    this->setCentralWidget(centralwidget);
    menubar = new QMenuBar(this);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 2560, 24));
    menu3dviewer = new QMenu(menubar);
    menu3dviewer->setObjectName(QString::fromUtf8("menu3dviewer"));
    this->setMenuBar(menubar);
    statusbar = new QStatusBar(this);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    this->setStatusBar(statusbar);

    menubar->addAction(menu3dviewer->menuAction());

    label_11->setText(
        QCoreApplication::translate("MainWindow", "Nodes Thickness", nullptr));
    label_13->setText(
        QCoreApplication::translate("MainWindow", "Background Color", nullptr));
    label_3->setText(
        QCoreApplication::translate("MainWindow", "Move", nullptr));
    label_10->setText(
        QCoreApplication::translate("MainWindow", "Nodes", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
    label_12->setText(
        QCoreApplication::translate("MainWindow", "Color of Nodes", nullptr));
    label_14->setText(
        QCoreApplication::translate("MainWindow", "Rotation", nullptr));
    label_8->setText(
        QCoreApplication::translate("MainWindow", " Figures", nullptr));
    label_9->setText(
        QCoreApplication::translate("MainWindow", "Line Thickness", nullptr));
    label_5->setText(QCoreApplication::translate(
        "MainWindow", fileName.toStdString().c_str(), nullptr));
    label_4->setText(
        QCoreApplication::translate("MainWindow", "Info", nullptr));
    label_6->setText(QCoreApplication::translate(
        "MainWindow", std::to_string(vwr->data.vertex_size / 3).c_str(),
        nullptr));
    label_7->setText(QCoreApplication::translate(
        "MainWindow", std::to_string(vwr->data.polygon_size / 6).c_str(),
        nullptr));

    pushButton->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_2->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_3->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_4->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    pushButton_5->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    pushButton_6->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));

    pushButton_20->setText(
        QCoreApplication::translate("MainWindow", "Round", nullptr));
    pushButton_21->setText(
        QCoreApplication::translate("MainWindow", "Square", nullptr));
    pushButton_22->setText(
        QCoreApplication::translate("MainWindow", "None", nullptr));

    pushButton_15->setText(
        QCoreApplication::translate("MainWindow", "Not Parallel", nullptr));
    pushButton_14->setText(
        QCoreApplication::translate("MainWindow", "Parallel", nullptr));
    pushButton_32->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_33->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    pushButton_26->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_27->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    pushButton_28->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_29->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    pushButton_30->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_31->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));

    pushButton_18->setText(
        QCoreApplication::translate("MainWindow", "Dotted", nullptr));
    pushButton_19->setText(
        QCoreApplication::translate("MainWindow", "Solid", nullptr));
    // pushButton_17->setText(QCoreApplication::translate("MainWindow",
    // "nothing", nullptr));
    pushButton_23->setText(
        QCoreApplication::translate("MainWindow", "Save jpg", nullptr));
    pushButton_24->setText(
        QCoreApplication::translate("MainWindow", "Save bmp", nullptr));
    pushButton_25->setText(
        QCoreApplication::translate("MainWindow", "Save gif", nullptr));

    pushButton_7 = new QPushButton(centralwidget);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    pushButton_7->setText(
        QCoreApplication::translate("MainWindow", "Load model", nullptr));
    pushButton_7->setGeometry(QRect(QPoint(1400, 200), QSize(250, 250)));

    pushButton_39 = new QPushButton(centralwidget);
    pushButton_39->setObjectName(QString::fromUtf8("pushButton_39"));
    pushButton_39->setText(
        QCoreApplication::translate("MainWindow", "Load settings", nullptr));
    pushButton_39->setGeometry(QRect(QPoint(1400, 600), QSize(250, 250)));

    horizontalSlider_18 = new QSlider(centralwidget);
    horizontalSlider_18->setObjectName(
        QString::fromUtf8("horizontalSlider_18"));

    horizontalSlider_19 = new QSlider(centralwidget);
    horizontalSlider_19->setObjectName(
        QString::fromUtf8("horizontalSlider_19"));

    horizontalSlider_20 = new QSlider(centralwidget);
    horizontalSlider_20->setObjectName(
        QString::fromUtf8("horizontalSlider_20"));

    horizontalSlider_18->setGeometry(QRect(QPoint(1500, 1000), QSize(100, 30)));
    horizontalSlider_19->setGeometry(QRect(QPoint(1650, 1000), QSize(100, 30)));
    horizontalSlider_20->setGeometry(QRect(QPoint(1800, 1000), QSize(100, 30)));

    label_19 = new QLabel(centralwidget);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setGeometry(QRect(QPoint(1500, 950), QSize(100, 30)));
    label_19->setText(
        QCoreApplication::translate("MainWindow", "Line Color", nullptr));

    horizontalSlider_18->setOrientation(Qt::Horizontal);
    horizontalSlider_19->setOrientation(Qt::Horizontal);
    horizontalSlider_20->setOrientation(Qt::Horizontal);
    horizontalSlider_12->setMinimum(0);
    horizontalSlider_12->setMaximum(100);
    horizontalSlider_13->setMinimum(0);
    horizontalSlider_13->setMaximum(100);
    horizontalSlider_14->setMinimum(0);
    horizontalSlider_15->setMaximum(100);
    horizontalSlider_15->setMinimum(0);
    horizontalSlider_15->setMaximum(100);
    horizontalSlider_16->setMinimum(0);
    horizontalSlider_16->setMaximum(100);
    horizontalSlider_17->setMinimum(0);
    horizontalSlider_17->setMaximum(100);
    horizontalSlider_7->setMinimum(0);
    horizontalSlider_7->setMaximum(100);
    horizontalSlider_18->setMinimum(0);
    horizontalSlider_18->setMaximum(100);

    horizontalSlider_19->setMinimum(0);
    horizontalSlider_19->setMaximum(100);
    horizontalSlider_20->setMinimum(0);
    horizontalSlider_20->setMaximum(100);
    fileName = QFileDialog::getOpenFileName(this, "Выбрать файл", nullptr,
                                            "Object(*.obj)");
    vwr->load_file(fileName);
    label_5->setText(QCoreApplication::translate(
        "MainWindow", fileName.toStdString().c_str(), nullptr));
    label_6->setText(QCoreApplication::translate(
        "MainWindow", std::to_string(vwr->data.vertex_size / 3).c_str(),
        nullptr));
    label_7->setText(QCoreApplication::translate(
        "MainWindow", std::to_string(vwr->data.polygon_size / 6).c_str(),
        nullptr));
  }

  void setup() {
    /**/
    // Coordinates
    QObject::connect(lineEdit_3, &QLineEdit::returnPressed, [=]() {
      vwr->changepos_z(lineEdit_3->text().toDouble() / 100.);
    });
    QObject::connect(lineEdit_2, &QLineEdit::returnPressed, [=]() {
      vwr->changepos_x(lineEdit_2->text().toDouble() / 100.);
    });
    QObject::connect(lineEdit, &QLineEdit::returnPressed, [=]() {
      vwr->changepos_y(lineEdit->text().toDouble() / 100.);
    });
    QObject::connect(pushButton, &QPushButton::clicked,
                     [=]() { vwr->changepos_x(vwr->xMov); });
    QObject::connect(pushButton_4, &QPushButton::clicked,
                     [=]() { vwr->changepos_x(-vwr->xMov); });
    QObject::connect(pushButton_2, &QPushButton::clicked,
                     [=]() { vwr->changepos_y(vwr->yMov); });
    QObject::connect(pushButton_5, &QPushButton::clicked,
                     [=]() { vwr->changepos_y(-vwr->yMov); });
    QObject::connect(pushButton_3, &QPushButton::clicked,
                     [=]() { vwr->changepos_z(vwr->zMov); });
    QObject::connect(pushButton_6, &QPushButton::clicked,
                     [=]() { vwr->changepos_z(-vwr->zMov); });

    // Background colors
    QObject::connect(horizontalSlider_15, &QSlider::valueChanged, [=]() {
      vwr->changeBackgroundR(horizontalSlider_15->value() * 0.01);
    });
    QObject::connect(horizontalSlider_16, &QSlider::valueChanged, [=]() {
      vwr->changeBackgroundG(horizontalSlider_16->value() * 0.01);
    });
    QObject::connect(horizontalSlider_17, &QSlider::valueChanged, [=]() {
      vwr->changeBackgroundB(horizontalSlider_17->value() * 0.01);
    });

    QObject::connect(horizontalSlider_18, &QSlider::valueChanged, [=]() {
      vwr->changeLineR(horizontalSlider_18->value() * 0.01);
    });
    QObject::connect(horizontalSlider_19, &QSlider::valueChanged, [=]() {
      vwr->changeLineG(horizontalSlider_19->value() * 0.01);
    });
    QObject::connect(horizontalSlider_20, &QSlider::valueChanged, [=]() {
      vwr->changeLineB(horizontalSlider_20->value() * 0.01);
    });

    // Point type changes
    QObject::connect(pushButton_20, &QPushButton::clicked,
                     [=]() { vwr->changePointType(ROUND); });
    QObject::connect(pushButton_21, &QPushButton::clicked,
                     [=]() { vwr->changePointType(SQUARE); });
    QObject::connect(pushButton_22, &QPushButton::clicked,
                     [=]() { vwr->changePointType(NONE); });

    // Parallel/not parallel buttons
    QObject::connect(pushButton_14, &QPushButton::clicked,
                     [=]() { vwr->setParallel(true); });
    QObject::connect(pushButton_15, &QPushButton::clicked,
                     [=]() { vwr->setParallel(false); });

    // Load button
    QObject::connect(pushButton_7, &QPushButton::clicked, [=]() {
      fileName = QFileDialog::getOpenFileName(this, "Выбрать файл", nullptr,
                                              "Object(*.obj)");
      std::cout << "Filename: " << fileName.toStdString().c_str() << std::endl;
      vwr->load_file(fileName);
      label_5->setText(QCoreApplication::translate(
          "MainWindow", fileName.toStdString().c_str(), nullptr));
      label_6->setText(QCoreApplication::translate(
          "MainWindow", std::to_string(vwr->data.vertex_size / 3).c_str(),
          nullptr));
      label_7->setText(QCoreApplication::translate(
          "MainWindow", std::to_string(vwr->data.polygon_size / 6).c_str(),
          nullptr));
    });
    // Load settings button
    QObject::connect(pushButton_39, &QPushButton::clicked,
                     [=]() { vwr->load_settings(); });

    // Point width
    QObject::connect(horizontalSlider_7, &QSlider::valueChanged, [=]() {
      vwr->setPointWidth(horizontalSlider_7->value() * 0.2);
    });

    // Point color
    QObject::connect(horizontalSlider_12, &QSlider::valueChanged, [=]() {
      vwr->changePointR(horizontalSlider_12->value() * 0.01);
    });

    QObject::connect(horizontalSlider_13, &QSlider::valueChanged, [=]() {
      vwr->changePointG(horizontalSlider_13->value() * 0.01);
    });

    QObject::connect(horizontalSlider_14, &QSlider::valueChanged, [=]() {
      vwr->changePointB(horizontalSlider_14->value() * 0.01);
    });

    // Line width
    QObject::connect(horizontalSlider_4, &QSlider::valueChanged, [=]() {
      vwr->setLineWidth(horizontalSlider_4->value() * 0.2);
    });

    // Dotted line ?
    QObject::connect(pushButton_18, &QPushButton::clicked,
                     [=]() { vwr->setDottedLine(true); });
    QObject::connect(pushButton_19, &QPushButton::clicked,
                     [=]() { vwr->setDottedLine(false); });

    // Rotation
    QObject::connect(pushButton_26, &QPushButton::clicked,
                     [=]() { vwr->rotate(3, 0, 0); });
    QObject::connect(pushButton_27, &QPushButton::clicked,
                     [=]() { vwr->rotate(-3, 0, 0); });
    QObject::connect(pushButton_28, &QPushButton::clicked,
                     [=]() { vwr->rotate(0, 3, 0); });
    QObject::connect(pushButton_29, &QPushButton::clicked,
                     [=]() { vwr->rotate(0, -3, 0); });
    QObject::connect(pushButton_30, &QPushButton::clicked,
                     [=]() { vwr->rotate(0, 0, 3); });
    QObject::connect(pushButton_31, &QPushButton::clicked,
                     [=]() { vwr->rotate(0, 0, -3); });

    // Rotation lineEdit
    QObject::connect(lineEdit_7, &QLineEdit::returnPressed, [=]() {
      vwr->rotate(lineEdit_7->text().toDouble(), 0, 0);
    });
    QObject::connect(lineEdit_8, &QLineEdit::returnPressed, [=]() {
      vwr->rotate(0, lineEdit_8->text().toDouble(), 0);
    });
    QObject::connect(lineEdit_10, &QLineEdit::returnPressed, [=]() {
      vwr->rotate(0, 0, lineEdit_10->text().toDouble());
    });

    // Zoom
    QObject::connect(lineEdit_8, &QLineEdit::returnPressed,
                     [=]() { vwr->zoom_on(lineEdit_8->text().toDouble()); });
    QObject::connect(pushButton_32, &QPushButton::clicked,
                     [=]() { vwr->zoom_on(1.1); });
    QObject::connect(pushButton_33, &QPushButton::clicked,
                     [=]() { vwr->zoom_on(0.9); });

    // Saves
    QObject::connect(pushButton_23, &QPushButton::clicked,
                     [=]() { vwr->saveJpeg("res.jpeg"); });
    QObject::connect(pushButton_24, &QPushButton::clicked,
                     [=]() { vwr->saveBmp("res.bmp"); });
    QObject::connect(pushButton_25, &QPushButton::clicked,
                     [=]() { vwr->saveGif(); });
  }
  QString fileName;
  Viewer3d *vwr;

  QWidget *centralwidget;
  QWidget *horizontalLayoutWidget_2;
  QWidget *horizontalLayoutWidget_3;
  QWidget *horizontalLayoutWidget_4;
  QWidget *horizontalLayoutWidget_5;
  QWidget *horizontalLayoutWidget_6;
  QWidget *horizontalLayoutWidget_7;
  QWidget *horizontalLayoutWidget_8;

  QHBoxLayout *horizontalLayout;
  QHBoxLayout *horizontalLayout_2;
  QHBoxLayout *horizontalLayout_3;
  QHBoxLayout *horizontalLayout_4;
  QHBoxLayout *horizontalLayout_5;
  QHBoxLayout *horizontalLayout_6;
  QHBoxLayout *horizontalLayout_7;
  QHBoxLayout *horizontalLayout_8;
  QHBoxLayout *horizontalLayout_9;
  QHBoxLayout *horizontalLayout_10;
  QHBoxLayout *horizontalLayout_11;
  QHBoxLayout *horizontalLayout_12;
  QHBoxLayout *horizontalLayout_13;
  QHBoxLayout *horizontalLayout_14;
  QHBoxLayout *horizontalLayout_15;
  QHBoxLayout *horizontalLayout_16;
  QHBoxLayout *horizontalLayout_17;
  QHBoxLayout *horizontalLayout_18;
  QHBoxLayout *horizontalLayout_19;
  QHBoxLayout *horizontalLayout_20;
  QHBoxLayout *horizontalLayout_21;
  QHBoxLayout *horizontalLayout_22;
  QHBoxLayout *horizontalLayout_23;
  QHBoxLayout *horizontalLayout_24;
  QHBoxLayout *horizontalLayout_25;
  QHBoxLayout *horizontalLayout_26;
  QHBoxLayout *horizontalLayout_27;
  QHBoxLayout *horizontalLayout_28;
  QHBoxLayout *horizontalLayout_29;

  Viewer3d *openGLWidget;

  QVBoxLayout *verticalLayout;
  QVBoxLayout *verticalLayout_2;
  QVBoxLayout *verticalLayout_3;
  QVBoxLayout *verticalLayout_4;
  QVBoxLayout *verticalLayout_5;
  QVBoxLayout *verticalLayout_6;
  QVBoxLayout *verticalLayout_7;
  QVBoxLayout *verticalLayout_8;
  QVBoxLayout *verticalLayout_9;
  QVBoxLayout *verticalLayout_10;
  QVBoxLayout *verticalLayout_11;
  QVBoxLayout *verticalLayout_12;

  QLabel *label;
  QLabel *label_2;
  QLabel *label_3;
  QLabel *label_4;
  QLabel *label_5;
  QLabel *label_6;
  QLabel *label_7;
  QLabel *label_8;
  QLabel *label_9;
  QLabel *label_10;
  QLabel *label_11;
  QLabel *label_12;
  QLabel *label_13;
  QLabel *label_14;
  QLabel *label_15;
  QLabel *label_16;
  QLabel *label_17;
  QLabel *label_18;
  QLabel *label_19;

  QPushButton *pushButton;
  QPushButton *pushButton_2;
  QPushButton *pushButton_3;
  QPushButton *pushButton_4;
  QPushButton *pushButton_5;
  QPushButton *pushButton_6;
  QPushButton *pushButton_7;
  QPushButton *pushButton_8;
  QPushButton *pushButton_9;
  QPushButton *pushButton_10;
  QPushButton *pushButton_12;
  QPushButton *pushButton_13;
  QPushButton *pushButton_14;
  QPushButton *pushButton_15;
  QPushButton *pushButton_16;
  QPushButton *pushButton_17;
  QPushButton *pushButton_18;
  QPushButton *pushButton_19;
  QPushButton *pushButton_20;
  QPushButton *pushButton_21;
  QPushButton *pushButton_22;
  QPushButton *pushButton_23;
  QPushButton *pushButton_24;
  QPushButton *pushButton_25;
  QPushButton *pushButton_26;
  QPushButton *pushButton_27;
  QPushButton *pushButton_28;
  QPushButton *pushButton_29;
  QPushButton *pushButton_30;
  QPushButton *pushButton_31;
  QPushButton *pushButton_32;
  QPushButton *pushButton_33;
  QPushButton *pushButton_34;
  QPushButton *pushButton_35;
  QPushButton *pushButton_36;
  QPushButton *pushButton_37;
  QPushButton *pushButton_38;
  QPushButton *pushButton_39;

  QLineEdit *lineEdit;
  QLineEdit *lineEdit_2;
  QLineEdit *lineEdit_3;
  QLineEdit *lineEdit_4;
  QLineEdit *lineEdit_5;
  QLineEdit *lineEdit_6;
  QLineEdit *lineEdit_7;
  QLineEdit *lineEdit_8;
  QLineEdit *lineEdit_9;
  QLineEdit *lineEdit_10;

  QSlider *horizontalSlider;
  QSlider *horizontalSlider_2;
  QSlider *horizontalSlider_3;
  QSlider *horizontalSlider_4;
  QSlider *horizontalSlider_5;
  QSlider *horizontalSlider_6;
  QSlider *horizontalSlider_7;
  QSlider *horizontalSlider_8;
  QSlider *horizontalSlider_9;
  QSlider *horizontalSlider_10;
  QSlider *horizontalSlider_11;
  QSlider *horizontalSlider_12;
  QSlider *horizontalSlider_13;
  QSlider *horizontalSlider_14;
  QSlider *horizontalSlider_15;
  QSlider *horizontalSlider_16;
  QSlider *horizontalSlider_17;
  QSlider *horizontalSlider_18;
  QSlider *horizontalSlider_19;
  QSlider *horizontalSlider_20;

  QMenuBar *menubar;
  QStatusBar *statusbar;
  QMenu *menu3dviewer;

  // QPushButton *pushButton_23;

  // QLineEdit *lineEdit_2;

  QPushButton *pushButton_100;
  QPushButton *pushButton_200;
  QPushButton *pushButton_300;
  QPushButton *pushButton_400;
};