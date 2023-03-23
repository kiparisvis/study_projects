#include "creditwindow.h"

#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditWindow) {
  ui->setupUi(this);
  QDoubleValidator *creditSum = new QDoubleValidator;
  creditSum->setLocale(QLocale::English);
  ui->lineSum->setValidator(creditSum);
  QIntValidator *creditTime = new QIntValidator;
  ui->lineTime->setValidator(creditTime);
  ui->tableWidget->setHorizontalHeaderItem(
      0, new QTableWidgetItem("Сумма\nплатежа,\nруб."));
  ui->tableWidget->setHorizontalHeaderItem(
      1, new QTableWidgetItem("Платеж по\nосновному\nдолгу, руб."));
  ui->tableWidget->setHorizontalHeaderItem(
      2, new QTableWidgetItem("Платеж по\nпроцентам,\nруб."));
  ui->tableWidget->setHorizontalHeaderItem(
      3, new QTableWidgetItem("Остаток\nдолга,\nруб."));
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::on_pushButton_clicked() {
  int term_months;
  if (ui->comboBox->currentIndex() == 0)
    term_months = ui->lineTime->text().toInt() * 12;
  else
    term_months = ui->lineTime->text().toInt();
  ui->tableWidget->setRowCount(term_months);
  double credit_rate_per_month = ui->linePercent->text().toDouble() / 12 / 100;
  double balance_md = ui->lineSum->text().toDouble();
  double monthly_payment_all, monthly_payment_md, monthly_payment_pc,
      monthly_payment_min, monthly_payment_max, overpayment = 0,
                                                total_payment = 0;
  if (ui->radioButton_anuit->isChecked() == true) {
    double coef_anuit = (credit_rate_per_month *
                         pow((1 + credit_rate_per_month), term_months)) /
                        (pow((1 + credit_rate_per_month), term_months) - 1);
    monthly_payment_all = ui->lineSum->text().toDouble() * coef_anuit;
    total_payment = monthly_payment_all * term_months;
    for (int row = 0; row < term_months; row++) {
      monthly_payment_pc = balance_md * credit_rate_per_month;
      monthly_payment_pc = round(monthly_payment_pc * 100) / 100;
      overpayment += monthly_payment_pc;
      monthly_payment_md = monthly_payment_all - monthly_payment_pc;
      balance_md -= monthly_payment_md;
      ui->tableWidget->setItem(
          row, 0,
          new QTableWidgetItem(tr("%1").arg(monthly_payment_all, 0, 'f', 2)));
      ui->tableWidget->item(row, 0)->setTextAlignment(Qt::AlignRight |
                                                      Qt::AlignVCenter);
      ui->tableWidget->setItem(
          row, 1,
          new QTableWidgetItem(tr("%1").arg(monthly_payment_md, 0, 'f', 2)));
      ui->tableWidget->item(row, 1)->setTextAlignment(Qt::AlignRight |
                                                      Qt::AlignVCenter);
      ui->tableWidget->setItem(
          row, 2,
          new QTableWidgetItem(tr("%1").arg(monthly_payment_pc, 0, 'f', 2)));
      ui->tableWidget->item(row, 2)->setTextAlignment(Qt::AlignRight |
                                                      Qt::AlignVCenter);
      ui->tableWidget->setItem(
          row, 3, new QTableWidgetItem(tr("%1").arg(balance_md, 0, 'f', 2)));
      ui->tableWidget->item(row, 3)->setTextAlignment(Qt::AlignRight |
                                                      Qt::AlignVCenter);
      ui->pay_in_month->setText(tr("%1").arg(monthly_payment_all, 0, 'f', 2));
      ui->overpay->setText(tr("%1").arg(overpayment, 0, 'f', 2));
      ui->total_pay->setText(tr("%1").arg(total_payment, 0, 'f', 2));
    }
  } else if (ui->radioButton_diff->isChecked() == true) {
    monthly_payment_md = balance_md / term_months;
    monthly_payment_max = -INFINITY;
    monthly_payment_min = INFINITY;
    for (int row = 0; row < term_months; row++) {
      monthly_payment_pc =
          monthly_payment_md * (term_months - row) * credit_rate_per_month;
      monthly_payment_pc = round(monthly_payment_pc * 100) / 100;
      overpayment += monthly_payment_pc;
      monthly_payment_all = monthly_payment_md + monthly_payment_pc;
      if (monthly_payment_all < monthly_payment_min)
        monthly_payment_min = monthly_payment_all;
      if (monthly_payment_all > monthly_payment_max)
        monthly_payment_max = monthly_payment_all;
      total_payment += monthly_payment_all;
      balance_md -= monthly_payment_md;
      ui->tableWidget->setItem(
          row, 0,
          new QTableWidgetItem(tr("%1").arg(monthly_payment_all, 0, 'f', 2)));
      ui->tableWidget->item(row, 0)->setTextAlignment(Qt::AlignRight |
                                                      Qt::AlignVCenter);
      ui->tableWidget->setItem(
          row, 1,
          new QTableWidgetItem(tr("%1").arg(monthly_payment_md, 0, 'f', 2)));
      ui->tableWidget->item(row, 1)->setTextAlignment(Qt::AlignRight |
                                                      Qt::AlignVCenter);
      ui->tableWidget->setItem(
          row, 2,
          new QTableWidgetItem(tr("%1").arg(monthly_payment_pc, 0, 'f', 2)));
      ui->tableWidget->item(row, 2)->setTextAlignment(Qt::AlignRight |
                                                      Qt::AlignVCenter);
      ui->tableWidget->setItem(
          row, 3, new QTableWidgetItem(tr("%1").arg(balance_md, 0, 'f', 2)));
      ui->tableWidget->item(row, 3)->setTextAlignment(Qt::AlignRight |
                                                      Qt::AlignVCenter);
      ui->pay_in_month->setText(tr("%1 ... %2 руб.")
                                    .arg(monthly_payment_max, 0, 'f', 2)
                                    .arg(monthly_payment_min, 0, 'f', 2));
      ui->overpay->setText(tr("%1 руб.").arg(overpayment, 0, 'f', 2));
      ui->total_pay->setText(tr("%1 руб.").arg(total_payment, 0, 'f', 2));
    }
  }
}
