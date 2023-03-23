/********************************************************************************
** Form generated from reading UI file 'depositwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITWINDOW_H
#define UI_DEPOSITWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *L1_add;
    QLabel *label;
    QHBoxLayout *l1_sumLayout;
    QLineEdit *lineSum;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *l2_periodLayout;
    QLineEdit *linePeriod;
    QComboBox *comboBox;
    QLabel *label_4;
    QHBoxLayout *l3_prdBeginLayout;
    QDateEdit *dateBox;
    QLabel *label_5;
    QHBoxLayout *l4_intRateLayout;
    QLineEdit *lineInerestRate;
    QLabel *label_9;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineTaxRate;
    QLabel *label_18;
    QLabel *label_8;
    QHBoxLayout *l5_pereodityLayout;
    QComboBox *comboBoxPeriodity;
    QLabel *label_11;
    QHBoxLayout *l6_capitalizLayout;
    QCheckBox *checkBoxCapital;
    QLabel *label_10;
    QPushButton *b_add_to_adds_list;
    QLabel *label_6;
    QHBoxLayout *l9_taxRateLayout;
    QLineEdit *lineCB;
    QLabel *label_13;
    QFormLayout *L2_sub;
    QLabel *label_12;
    QPushButton *b_add_to_subs_list;
    QFormLayout *L3_bottom;
    QHBoxLayout *l11_calcButLayout;
    QPushButton *pushButtonCalc;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_14;
    QHBoxLayout *l12_Layout;
    QLabel *label_out_percents;
    QLabel *label_15;
    QHBoxLayout *l13_Layout;
    QLabel *label_out_tax;
    QLabel *label_16;
    QHBoxLayout *l14_Layout;
    QLabel *label_out_sum;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;

    void setupUi(QDialog *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName(QString::fromUtf8("DepositWindow"));
        DepositWindow->resize(480, 943);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DepositWindow->sizePolicy().hasHeightForWidth());
        DepositWindow->setSizePolicy(sizePolicy);
        DepositWindow->setMinimumSize(QSize(480, 490));
        DepositWindow->setMaximumSize(QSize(480, 16777215));
        DepositWindow->setModal(true);
        verticalLayout_2 = new QVBoxLayout(DepositWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(DepositWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFocusPolicy(Qt::NoFocus);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 454, 917));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        L1_add = new QFormLayout();
        L1_add->setObjectName(QString::fromUtf8("L1_add"));
        L1_add->setLabelAlignment(Qt::AlignCenter);
        L1_add->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(167, 20));

        L1_add->setWidget(0, QFormLayout::LabelRole, label);

        l1_sumLayout = new QHBoxLayout();
        l1_sumLayout->setObjectName(QString::fromUtf8("l1_sumLayout"));
        l1_sumLayout->setContentsMargins(5, -1, -1, -1);
        lineSum = new QLineEdit(scrollAreaWidgetContents);
        lineSum->setObjectName(QString::fromUtf8("lineSum"));

        l1_sumLayout->addWidget(lineSum);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        l1_sumLayout->addWidget(label_2);


        L1_add->setLayout(0, QFormLayout::FieldRole, l1_sumLayout);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(167, 20));

        L1_add->setWidget(1, QFormLayout::LabelRole, label_3);

        l2_periodLayout = new QHBoxLayout();
        l2_periodLayout->setObjectName(QString::fromUtf8("l2_periodLayout"));
        l2_periodLayout->setContentsMargins(5, -1, -1, -1);
        linePeriod = new QLineEdit(scrollAreaWidgetContents);
        linePeriod->setObjectName(QString::fromUtf8("linePeriod"));

        l2_periodLayout->addWidget(linePeriod);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        l2_periodLayout->addWidget(comboBox);


        L1_add->setLayout(1, QFormLayout::FieldRole, l2_periodLayout);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(167, 20));

        L1_add->setWidget(2, QFormLayout::LabelRole, label_4);

        l3_prdBeginLayout = new QHBoxLayout();
        l3_prdBeginLayout->setObjectName(QString::fromUtf8("l3_prdBeginLayout"));
        dateBox = new QDateEdit(scrollAreaWidgetContents);
        dateBox->setObjectName(QString::fromUtf8("dateBox"));
        dateBox->setDateTime(QDateTime(QDate(2022, 9, 5), QTime(12, 0, 0)));
        dateBox->setCurrentSection(QDateTimeEdit::DaySection);
        dateBox->setCalendarPopup(true);
        dateBox->setDate(QDate(2022, 9, 5));

        l3_prdBeginLayout->addWidget(dateBox);


        L1_add->setLayout(2, QFormLayout::FieldRole, l3_prdBeginLayout);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(167, 20));

        L1_add->setWidget(3, QFormLayout::LabelRole, label_5);

        l4_intRateLayout = new QHBoxLayout();
        l4_intRateLayout->setObjectName(QString::fromUtf8("l4_intRateLayout"));
        l4_intRateLayout->setContentsMargins(5, -1, -1, -1);
        lineInerestRate = new QLineEdit(scrollAreaWidgetContents);
        lineInerestRate->setObjectName(QString::fromUtf8("lineInerestRate"));

        l4_intRateLayout->addWidget(lineInerestRate);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        l4_intRateLayout->addWidget(label_9);


        L1_add->setLayout(3, QFormLayout::FieldRole, l4_intRateLayout);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(167, 0));

        L1_add->setWidget(4, QFormLayout::LabelRole, label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, -1, -1);
        lineTaxRate = new QLineEdit(scrollAreaWidgetContents);
        lineTaxRate->setObjectName(QString::fromUtf8("lineTaxRate"));

        horizontalLayout->addWidget(lineTaxRate);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout->addWidget(label_18);


        L1_add->setLayout(4, QFormLayout::FieldRole, horizontalLayout);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(167, 20));

        L1_add->setWidget(5, QFormLayout::LabelRole, label_8);

        l5_pereodityLayout = new QHBoxLayout();
        l5_pereodityLayout->setObjectName(QString::fromUtf8("l5_pereodityLayout"));
        comboBoxPeriodity = new QComboBox(scrollAreaWidgetContents);
        comboBoxPeriodity->addItem(QString());
        comboBoxPeriodity->addItem(QString());
        comboBoxPeriodity->addItem(QString());
        comboBoxPeriodity->addItem(QString());
        comboBoxPeriodity->addItem(QString());
        comboBoxPeriodity->addItem(QString());
        comboBoxPeriodity->addItem(QString());
        comboBoxPeriodity->setObjectName(QString::fromUtf8("comboBoxPeriodity"));

        l5_pereodityLayout->addWidget(comboBoxPeriodity);


        L1_add->setLayout(5, QFormLayout::FieldRole, l5_pereodityLayout);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(167, 0));

        L1_add->setWidget(6, QFormLayout::LabelRole, label_11);

        l6_capitalizLayout = new QHBoxLayout();
        l6_capitalizLayout->setObjectName(QString::fromUtf8("l6_capitalizLayout"));
        l6_capitalizLayout->setContentsMargins(5, -1, -1, 6);
        checkBoxCapital = new QCheckBox(scrollAreaWidgetContents);
        checkBoxCapital->setObjectName(QString::fromUtf8("checkBoxCapital"));
        checkBoxCapital->setMinimumSize(QSize(0, 20));

        l6_capitalizLayout->addWidget(checkBoxCapital);


        L1_add->setLayout(6, QFormLayout::FieldRole, l6_capitalizLayout);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(167, 23));

        L1_add->setWidget(8, QFormLayout::LabelRole, label_10);

        b_add_to_adds_list = new QPushButton(scrollAreaWidgetContents);
        b_add_to_adds_list->setObjectName(QString::fromUtf8("b_add_to_adds_list"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(b_add_to_adds_list->sizePolicy().hasHeightForWidth());
        b_add_to_adds_list->setSizePolicy(sizePolicy1);
        b_add_to_adds_list->setMinimumSize(QSize(25, 25));
        b_add_to_adds_list->setMaximumSize(QSize(25, 25));

        L1_add->setWidget(8, QFormLayout::FieldRole, b_add_to_adds_list);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(167, 20));

        L1_add->setWidget(7, QFormLayout::LabelRole, label_6);

        l9_taxRateLayout = new QHBoxLayout();
        l9_taxRateLayout->setObjectName(QString::fromUtf8("l9_taxRateLayout"));
        l9_taxRateLayout->setContentsMargins(5, -1, -1, -1);
        lineCB = new QLineEdit(scrollAreaWidgetContents);
        lineCB->setObjectName(QString::fromUtf8("lineCB"));

        l9_taxRateLayout->addWidget(lineCB);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        l9_taxRateLayout->addWidget(label_13);


        L1_add->setLayout(7, QFormLayout::FieldRole, l9_taxRateLayout);


        verticalLayout_4->addLayout(L1_add);

        L2_sub = new QFormLayout();
        L2_sub->setObjectName(QString::fromUtf8("L2_sub"));
        L2_sub->setLabelAlignment(Qt::AlignCenter);
        L2_sub->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(167, 23));

        L2_sub->setWidget(0, QFormLayout::LabelRole, label_12);

        b_add_to_subs_list = new QPushButton(scrollAreaWidgetContents);
        b_add_to_subs_list->setObjectName(QString::fromUtf8("b_add_to_subs_list"));
        sizePolicy1.setHeightForWidth(b_add_to_subs_list->sizePolicy().hasHeightForWidth());
        b_add_to_subs_list->setSizePolicy(sizePolicy1);
        b_add_to_subs_list->setMinimumSize(QSize(25, 25));
        b_add_to_subs_list->setMaximumSize(QSize(25, 25));

        L2_sub->setWidget(0, QFormLayout::FieldRole, b_add_to_subs_list);


        verticalLayout_4->addLayout(L2_sub);

        L3_bottom = new QFormLayout();
        L3_bottom->setObjectName(QString::fromUtf8("L3_bottom"));
        l11_calcButLayout = new QHBoxLayout();
        l11_calcButLayout->setObjectName(QString::fromUtf8("l11_calcButLayout"));
        pushButtonCalc = new QPushButton(scrollAreaWidgetContents);
        pushButtonCalc->setObjectName(QString::fromUtf8("pushButtonCalc"));
        pushButtonCalc->setMinimumSize(QSize(100, 25));
        pushButtonCalc->setMaximumSize(QSize(100, 25));

        l11_calcButLayout->addWidget(pushButtonCalc, 0, Qt::AlignHCenter|Qt::AlignTop);


        L3_bottom->setLayout(1, QFormLayout::SpanningRole, l11_calcButLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        L3_bottom->setItem(2, QFormLayout::SpanningRole, horizontalSpacer_2);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        L3_bottom->setWidget(3, QFormLayout::LabelRole, label_14);

        l12_Layout = new QHBoxLayout();
        l12_Layout->setObjectName(QString::fromUtf8("l12_Layout"));
        label_out_percents = new QLabel(scrollAreaWidgetContents);
        label_out_percents->setObjectName(QString::fromUtf8("label_out_percents"));

        l12_Layout->addWidget(label_out_percents);


        L3_bottom->setLayout(3, QFormLayout::FieldRole, l12_Layout);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        L3_bottom->setWidget(4, QFormLayout::LabelRole, label_15);

        l13_Layout = new QHBoxLayout();
        l13_Layout->setObjectName(QString::fromUtf8("l13_Layout"));
        label_out_tax = new QLabel(scrollAreaWidgetContents);
        label_out_tax->setObjectName(QString::fromUtf8("label_out_tax"));

        l13_Layout->addWidget(label_out_tax);


        L3_bottom->setLayout(4, QFormLayout::FieldRole, l13_Layout);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        L3_bottom->setWidget(5, QFormLayout::LabelRole, label_16);

        l14_Layout = new QHBoxLayout();
        l14_Layout->setObjectName(QString::fromUtf8("l14_Layout"));
        label_out_sum = new QLabel(scrollAreaWidgetContents);
        label_out_sum->setObjectName(QString::fromUtf8("label_out_sum"));

        l14_Layout->addWidget(label_out_sum);


        L3_bottom->setLayout(5, QFormLayout::FieldRole, l14_Layout);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        L3_bottom->setWidget(7, QFormLayout::SpanningRole, label_17);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        L3_bottom->setItem(6, QFormLayout::SpanningRole, horizontalSpacer);


        verticalLayout_4->addLayout(L3_bottom);

        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setMinimumSize(QSize(0, 300));
        tableWidget->setFocusPolicy(Qt::ClickFocus);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout_4->addWidget(tableWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        QWidget::setTabOrder(lineSum, linePeriod);
        QWidget::setTabOrder(linePeriod, comboBox);
        QWidget::setTabOrder(comboBox, dateBox);
        QWidget::setTabOrder(dateBox, lineInerestRate);
        QWidget::setTabOrder(lineInerestRate, lineCB);
        QWidget::setTabOrder(lineCB, pushButtonCalc);
        QWidget::setTabOrder(pushButtonCalc, scrollArea);

        retranslateUi(DepositWindow);

        comboBox->setCurrentIndex(1);
        comboBoxPeriodity->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QDialog *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "DepositCalc", nullptr));
        label->setText(QCoreApplication::translate("DepositWindow", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        lineSum->setText(QCoreApplication::translate("DepositWindow", "100000", nullptr));
        label_2->setText(QCoreApplication::translate("DepositWindow", "\321\200\321\203\320\261.", nullptr));
        label_3->setText(QCoreApplication::translate("DepositWindow", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        linePeriod->setText(QCoreApplication::translate("DepositWindow", "12", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("DepositWindow", "\320\264\320\275\320\265\320\271", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("DepositWindow", "\320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("DepositWindow", "\320\273\320\265\321\202", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("DepositWindow", "\320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        label_4->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\260\321\207\320\260\320\273\320\276 \321\201\321\200\320\276\320\272\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("DepositWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        lineInerestRate->setText(QCoreApplication::translate("DepositWindow", "9", nullptr));
        label_9->setText(QCoreApplication::translate("DepositWindow", "% \320\263\320\276\320\264\320\276\320\262\321\213\321\205", nullptr));
        label_7->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        lineTaxRate->setText(QCoreApplication::translate("DepositWindow", "13", nullptr));
        label_18->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        label_8->setText(QCoreApplication::translate("DepositWindow", "\320\237\320\265\321\200\320\265\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        comboBoxPeriodity->setItemText(0, QCoreApplication::translate("DepositWindow", "\320\272\320\260\320\266\320\264\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));
        comboBoxPeriodity->setItemText(1, QCoreApplication::translate("DepositWindow", "\320\272\320\260\320\266\320\264\321\203\321\216 \320\275\320\265\320\264\320\265\320\273\321\216", nullptr));
        comboBoxPeriodity->setItemText(2, QCoreApplication::translate("DepositWindow", "\321\200\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        comboBoxPeriodity->setItemText(3, QCoreApplication::translate("DepositWindow", "\321\200\320\260\320\267 \320\262 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        comboBoxPeriodity->setItemText(4, QCoreApplication::translate("DepositWindow", "\321\200\320\260\320\267 \320\262 \320\277\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        comboBoxPeriodity->setItemText(5, QCoreApplication::translate("DepositWindow", "\321\200\320\260\320\267 \320\262 \320\263\320\276\320\264", nullptr));
        comboBoxPeriodity->setItemText(6, QCoreApplication::translate("DepositWindow", "\320\262 \320\272\320\276\320\275\321\206\320\265 \321\201\321\200\320\276\320\272\320\260", nullptr));

        comboBoxPeriodity->setCurrentText(QCoreApplication::translate("DepositWindow", "\321\200\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));
        label_11->setText(QCoreApplication::translate("DepositWindow", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        checkBoxCapital->setText(QString());
        label_10->setText(QCoreApplication::translate("DepositWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\271", nullptr));
        b_add_to_adds_list->setText(QCoreApplication::translate("DepositWindow", "+", nullptr));
        label_6->setText(QCoreApplication::translate("DepositWindow", "\320\232\320\273\321\216\321\207\320\265\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260 \320\246\320\221", nullptr));
        lineCB->setText(QCoreApplication::translate("DepositWindow", "8", nullptr));
        label_13->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        label_12->setText(QCoreApplication::translate("DepositWindow", "\320\247\320\260\321\201\321\202\320\270\321\207\320\275\321\213\320\265 \321\201\320\275\321\217\321\202\320\270\321\217", nullptr));
        b_add_to_subs_list->setText(QCoreApplication::translate("DepositWindow", "+", nullptr));
        pushButtonCalc->setText(QCoreApplication::translate("DepositWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_14->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_out_percents->setText(QCoreApplication::translate("DepositWindow", "-", nullptr));
        label_15->setText(QCoreApplication::translate("DepositWindow", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260\320\273\320\276\320\263\320\260", nullptr));
        label_out_tax->setText(QCoreApplication::translate("DepositWindow", "-", nullptr));
        label_16->setText(QCoreApplication::translate("DepositWindow", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260 \320\262\320\272\320\273\320\260\320\264\320\265 \320\272 \320\272\320\276\320\275\321\206\321\203 \321\201\321\200\320\276\320\272\320\260", nullptr));
        label_out_sum->setText(QCoreApplication::translate("DepositWindow", "-", nullptr));
        label_17->setText(QCoreApplication::translate("DepositWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\275\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DepositWindow", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\276\n"
"\320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262,\n"
"\321\200\321\203\320\261.", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DepositWindow", "\320\222\320\272\320\273\320\260\320\264\n"
"\320\277\320\276\320\277\320\276\320\273\320\275\320\265\320\275,\n"
"\321\200\321\203\320\261.", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DepositWindow", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272 \320\275\320\260\n"
"\320\262\320\272\320\273\320\260\320\264\320\265,\n"
"\321\200\321\203\320\261.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H
