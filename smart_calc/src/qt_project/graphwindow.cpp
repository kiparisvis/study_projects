#include "graphwindow.h"

#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget* parent)
    : QDialog(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::slot_xMin(double num) { xMin = num; }

void GraphWindow::slot_xMax(double num) { xMax = num; }

void GraphWindow::slot_yMin(double num) { yMin = num; }

void GraphWindow::slot_yMax(double num) { yMax = num; }

void GraphWindow::plotGraph(char* infix_string) {
  QString str_out = infix_string;
  ui->label->setText("y=" + str_out);
  ui->widget->xAxis->setRange(xMin, xMax);
  ui->widget->yAxis->setRange(yMin, yMax);
  h = (xMax - xMin) / 5000;
  X = xMin;

  for (X = xMin; X <= xMax; X += h) {
    Y = calc_infix_string_with_x(infix_string, X);
    x.push_back(X);
    y.push_back(Y);
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}
