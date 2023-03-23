#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <math.h>

#include <QDialog>
#include <QDoubleValidator>
#include <QIntValidator>

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QDialog {
  Q_OBJECT

 public:
  explicit CreditWindow(QWidget *parent = nullptr);
  ~CreditWindow();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::CreditWindow *ui;
};

#endif  // CREDITWINDOW_H
