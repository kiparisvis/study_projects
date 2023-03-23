#include "mainwindow.h"

#include "creditwindow.h"
#include "depositwindow.h"
#include "graphwindow.h"
#include "ui_mainwindow.h"

extern "C" {
#include "../c_calc_polish.h"
#include "c_validate_input.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QLocale::setDefault(QLocale::c());
  bad_answer_in_display = 0;
  connect(ui->b_0, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_1, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_2, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_3, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_4, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_5, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_6, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_7, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_8, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_9, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_acos, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_add, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_asin, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_atan, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_bracket_left, SIGNAL(clicked()), this,
          SLOT(PushButton_clicked()));
  connect(ui->b_bracket_right, SIGNAL(clicked()), this,
          SLOT(PushButton_clicked()));
  connect(ui->b_clear, SIGNAL(clicked()), this, SLOT(on_b_clear_clicked()));
  connect(ui->b_cos, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_div, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_dot, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_exp, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_ln, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_log, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_mod, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_mul, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_sin, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_sqrt, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_sub, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_tan, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));
  connect(ui->b_x, SIGNAL(clicked()), this, SLOT(PushButton_clicked()));

  doubleValidation = new QDoubleValidator;
  doubleValidation->setLocale(QLocale::English);
  ui->lineEdit_xmin->setValidator(doubleValidation);
  ui->lineEdit_xmax->setValidator(doubleValidation);
  ui->lineEdit_ymin->setValidator(doubleValidation);
  ui->lineEdit_ymax->setValidator(doubleValidation);
  ui->line_x->setValidator(doubleValidation);
}

MainWindow::~MainWindow() {
  delete doubleValidation;
  delete ui;
}

void MainWindow::PushButton_clicked() {
  if (!bad_answer_in_display) {
    ui->comments->setText("");
    QPushButton *but_num = (QPushButton *)sender();
    QByteArray pushed_button = but_num->text().toLocal8Bit();
    QByteArray display_string = ui->display->toPlainText().toLocal8Bit();
    int validation =
        validate_pushed_buttons(display_string.data(), pushed_button.data());
    if (validation == 1) {
      ui->display->setPlainText(display_string + but_num->text());
    } else if (validation == 2) {
      QString d_string = ui->display->toPlainText();
      d_string.chop(1);
      ui->display->setPlainText(d_string + but_num->text());
    } else if (validation == 3) {
      QString d_string = ui->display->toPlainText();
      d_string.chop(1);
      ui->display->setPlainText(d_string + but_num->text() + "(");
    } else if (validation == 4) {
      ui->display->setPlainText(display_string + but_num->text() + "(");
    } else if (validation == 5) {
      ui->comments->setText("Максимальное возможный ввод: 255 символов.");
    }
  }
}

void MainWindow::on_b_clear_clicked() {
  ui->comments->setText("");
  ui->display->setPlainText("0");
  bad_answer_in_display = 0;
}

void MainWindow::on_b_del_clicked() {
  ui->comments->setText("");
  if (ui->display->toPlainText().length() == 1) {
    ui->display->setPlainText("0");
    bad_answer_in_display = 0;
  } else {
    if (bad_answer_in_display) {
      ui->display->setPlainText("0");
      bad_answer_in_display = 0;
    } else {
      QByteArray display_string = ui->display->toPlainText().toLocal8Bit();
      display_string.chop(delete_last_input(display_string.data()));
      if (!display_string.length()) display_string = "0";
      ui->display->setPlainText(display_string);
    }
  }
}

void MainWindow::on_b_enter_clicked() {
  QLocale::setDefault(QLocale::c());
  if (!bad_answer_in_display) {
    double answer;
    QByteArray display_string = ui->display->toPlainText().toLocal8Bit();
    int validation = error_in_finished_string(display_string.data());
    if (validation == 1) {
      ui->comments->setText("Закочите выражение, введите число или х");
    } else if (validation == 2) {
      ui->comments->setText("Необходимо закрыть все скобки");
    } else if (validation == 3) {
      ui->comments->setText(
          "Закочите выражение, введите число или х и закройте все скобки");
    } else {
      if (strchr(display_string.data(), 'x')) {
        if (ui->line_x->text() == "") {
          ui->comments->setText(
              "Для вычисления выражения с х, введите его значение");
        } else {
          answer = calc_infix_string_with_x(display_string.data(),
                                            ui->line_x->text().toDouble());
          ui->display->setPlainText(QString::number(answer));
          display_string = ui->display->toPlainText().toLocal8Bit();
          bad_answer_in_display = is_correct_num(display_string.data(),
                                                 strlen(display_string.data()));
        }

      } else {
        answer = calc_infix_string_without_x(display_string.data());
        ui->display->setPlainText(QString::number(answer));
        display_string = ui->display->toPlainText().toLocal8Bit();
        bad_answer_in_display = is_correct_num(display_string.data(),
                                               strlen(display_string.data()));
      }
    }
  }
}

void MainWindow::on_creditButton_clicked() {
  credit_window = new CreditWindow();
  credit_window->setModal(true);
  credit_window->exec();
}

void MainWindow::on_depositButton_clicked() {
  deposit_window = new DepositWindow();
  deposit_window->setModal(true);
  deposit_window->exec();
}

void MainWindow::on_display_textChanged() {
  QTextCursor *newCursor = new QTextCursor(ui->display->textCursor());
  newCursor->movePosition(QTextCursor::End);
  ui->display->setTextCursor(*newCursor);
  delete newCursor;
}

void MainWindow::on_b_graph_clicked() {
  QByteArray display_string = ui->display->toPlainText().toLocal8Bit();
  if (strchr(display_string.data(), 'x')) {
    double xMin = ui->lineEdit_xmin->text().toDouble();
    double xMax = ui->lineEdit_xmax->text().toDouble();
    double yMin = ui->lineEdit_ymin->text().toDouble();
    double yMax = ui->lineEdit_ymax->text().toDouble();
    if ((xMin == 0 && xMin == xMax) || (yMin == 0 && yMin == yMax)) {
      ui->comments->setText(
          "Для вывода графика введите значения Xmin, Xmax, Ymin, Ymax.");
    } else if (xMin >= xMax || yMin >= yMax) {
      ui->comments->setText("Xmin и Ymin должны быть меньше Xmax и Ymax.");
    } else if (check_x_y_min_max(xMin, xMax, yMin, yMax)) {
      ui->comments->setText(
          "Задайте xMin, xMax, yMin, yMax в пределах [-1000000, 1000000].");
    } else {
      graph_window = new GraphWindow();
      graph_window->slot_xMin(xMin);
      graph_window->slot_xMax(xMax);
      graph_window->slot_yMin(yMin);
      graph_window->slot_yMax(yMax);
      graph_window->plotGraph(display_string.data());
      graph_window->setModal(true);
      graph_window->exec();
      bad_answer_in_display = 0;
    }
  } else {
    ui->comments->setText("Для вывода графика необходим х в выражении.");
  }
}

void MainWindow::on_lineEdit_xmin_textEdited() { ui->comments->setText(""); }

void MainWindow::on_lineEdit_xmax_textEdited() { ui->comments->setText(""); }

void MainWindow::on_lineEdit_ymin_textEdited() { ui->comments->setText(""); }

void MainWindow::on_lineEdit_ymax_textEdited() { ui->comments->setText(""); }

void MainWindow::on_line_x_textEdited() { ui->comments->setText(""); }
