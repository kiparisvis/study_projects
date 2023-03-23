#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QScrollBar>

#include "creditwindow.h"
#include "depositwindow.h"
#include "graphwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void PushButton_clicked();

  void on_b_clear_clicked();

  void on_b_del_clicked();

  void on_b_enter_clicked();

  void on_creditButton_clicked();

  void on_depositButton_clicked();

  void on_display_textChanged();

  void on_b_graph_clicked();

  void on_lineEdit_xmin_textEdited();

  void on_lineEdit_xmax_textEdited();

  void on_lineEdit_ymin_textEdited();

  void on_lineEdit_ymax_textEdited();

  void on_line_x_textEdited();

 private:
  Ui::MainWindow *ui;
  GraphWindow *graph_window;
  CreditWindow *credit_window;
  DepositWindow *deposit_window;
  int bad_answer_in_display;
  QDoubleValidator *doubleValidation;
};
#endif  // MAINWINDOW_H
