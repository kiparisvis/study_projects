/********************************************************************************
** Form generated from reading UI file 'creditwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITWINDOW_H
#define UI_CREDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditWindow
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineSum;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineTime;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *linePercent;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QRadioButton *radioButton_anuit;
    QLabel *label_7;
    QRadioButton *radioButton_diff;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *tableWidget;
    QLabel *label_8;
    QLabel *pay_in_month;
    QLabel *label_10;
    QLabel *overpay;
    QLabel *label_12;
    QLabel *total_pay;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *CreditWindow)
    {
        if (CreditWindow->objectName().isEmpty())
            CreditWindow->setObjectName(QString::fromUtf8("CreditWindow"));
        CreditWindow->resize(480, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreditWindow->sizePolicy().hasHeightForWidth());
        CreditWindow->setSizePolicy(sizePolicy);
        CreditWindow->setMinimumSize(QSize(480, 640));
        CreditWindow->setMaximumSize(QSize(480, 640));
        formLayout = new QFormLayout(CreditWindow);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(CreditWindow);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineSum = new QLineEdit(CreditWindow);
        lineSum->setObjectName(QString::fromUtf8("lineSum"));
        lineSum->setMinimumSize(QSize(150, 25));
        lineSum->setMaximumSize(QSize(150, 25));

        horizontalLayout->addWidget(lineSum);

        label_2 = new QLabel(CreditWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        label_3 = new QLabel(CreditWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineTime = new QLineEdit(CreditWindow);
        lineTime->setObjectName(QString::fromUtf8("lineTime"));
        lineTime->setMinimumSize(QSize(150, 25));
        lineTime->setMaximumSize(QSize(150, 25));

        horizontalLayout_2->addWidget(lineTime);

        comboBox = new QComboBox(CreditWindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        label_4 = new QLabel(CreditWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        linePercent = new QLineEdit(CreditWindow);
        linePercent->setObjectName(QString::fromUtf8("linePercent"));
        linePercent->setMinimumSize(QSize(150, 25));
        linePercent->setMaximumSize(QSize(150, 25));

        horizontalLayout_3->addWidget(linePercent);

        label_5 = new QLabel(CreditWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        label_6 = new QLabel(CreditWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        radioButton_anuit = new QRadioButton(CreditWindow);
        radioButton_anuit->setObjectName(QString::fromUtf8("radioButton_anuit"));
        radioButton_anuit->setChecked(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, radioButton_anuit);

        label_7 = new QLabel(CreditWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        radioButton_diff = new QRadioButton(CreditWindow);
        radioButton_diff->setObjectName(QString::fromUtf8("radioButton_diff"));

        formLayout->setWidget(4, QFormLayout::FieldRole, radioButton_diff);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton = new QPushButton(CreditWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(100, 25));
        pushButton->setMaximumSize(QSize(100, 25));
        pushButton->setLayoutDirection(Qt::LeftToRight);
        pushButton->setFlat(false);

        horizontalLayout_5->addWidget(pushButton, 0, Qt::AlignHCenter);


        formLayout->setLayout(5, QFormLayout::SpanningRole, horizontalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(480, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(6, QFormLayout::SpanningRole, horizontalSpacer_4);

        tableWidget = new QTableWidget(CreditWindow);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFocusPolicy(Qt::ClickFocus);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setShowGrid(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setDefaultSectionSize(91);

        formLayout->setWidget(12, QFormLayout::SpanningRole, tableWidget);

        label_8 = new QLabel(CreditWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        pay_in_month = new QLabel(CreditWindow);
        pay_in_month->setObjectName(QString::fromUtf8("pay_in_month"));

        formLayout->setWidget(7, QFormLayout::FieldRole, pay_in_month);

        label_10 = new QLabel(CreditWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_10);

        overpay = new QLabel(CreditWindow);
        overpay->setObjectName(QString::fromUtf8("overpay"));

        formLayout->setWidget(8, QFormLayout::FieldRole, overpay);

        label_12 = new QLabel(CreditWindow);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_12);

        total_pay = new QLabel(CreditWindow);
        total_pay->setObjectName(QString::fromUtf8("total_pay"));

        formLayout->setWidget(9, QFormLayout::FieldRole, total_pay);

        label_9 = new QLabel(CreditWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(11, QFormLayout::SpanningRole, label_9);

        horizontalSpacer_5 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(10, QFormLayout::SpanningRole, horizontalSpacer_5);

        QWidget::setTabOrder(lineSum, lineTime);
        QWidget::setTabOrder(lineTime, comboBox);
        QWidget::setTabOrder(comboBox, linePercent);
        QWidget::setTabOrder(linePercent, radioButton_anuit);
        QWidget::setTabOrder(radioButton_anuit, radioButton_diff);
        QWidget::setTabOrder(radioButton_diff, pushButton);
        QWidget::setTabOrder(pushButton, tableWidget);

        retranslateUi(CreditWindow);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(CreditWindow);
    } // setupUi

    void retranslateUi(QDialog *CreditWindow)
    {
        CreditWindow->setWindowTitle(QCoreApplication::translate("CreditWindow", "CreditCalc", nullptr));
        label->setText(QCoreApplication::translate("CreditWindow", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        lineSum->setText(QCoreApplication::translate("CreditWindow", "100000", nullptr));
        label_2->setText(QCoreApplication::translate("CreditWindow", "\321\200\321\203\320\261.", nullptr));
        label_3->setText(QCoreApplication::translate("CreditWindow", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        lineTime->setText(QCoreApplication::translate("CreditWindow", "2", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("CreditWindow", "\320\273\320\265\321\202", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("CreditWindow", "\320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));

        label_4->setText(QCoreApplication::translate("CreditWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272", nullptr));
        linePercent->setText(QCoreApplication::translate("CreditWindow", "20", nullptr));
        label_5->setText(QCoreApplication::translate("CreditWindow", "%", nullptr));
        label_6->setText(QCoreApplication::translate("CreditWindow", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
        radioButton_anuit->setText(QCoreApplication::translate("CreditWindow", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        label_7->setText(QString());
        radioButton_diff->setText(QCoreApplication::translate("CreditWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));
        pushButton->setText(QCoreApplication::translate("CreditWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("CreditWindow", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266: ", nullptr));
        pay_in_month->setText(QCoreApplication::translate("CreditWindow", "-", nullptr));
        label_10->setText(QCoreApplication::translate("CreditWindow", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203:", nullptr));
        overpay->setText(QCoreApplication::translate("CreditWindow", "-", nullptr));
        label_12->setText(QCoreApplication::translate("CreditWindow", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260:", nullptr));
        total_pay->setText(QCoreApplication::translate("CreditWindow", "-", nullptr));
        label_9->setText(QCoreApplication::translate("CreditWindow", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\265 \320\277\320\273\320\260\321\202\320\265\320\266\320\270:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditWindow: public Ui_CreditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITWINDOW_H
