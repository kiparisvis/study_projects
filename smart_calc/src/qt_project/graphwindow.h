#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>

extern "C" {
#include "../c_calc_polish.h"
}

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  ~GraphWindow();

 private:
  Ui::GraphWindow *ui;
  double xMin, xMax, yMin, yMax, h, X, Y;
  int N;
  QVector<double> x, y;

 public slots:
  void slot_xMin(double num);
  void slot_xMax(double num);
  void slot_yMin(double num);
  void slot_yMax(double num);
  void plotGraph(char *infix_string);
};

#endif  // GRAPHWINDOW_H
