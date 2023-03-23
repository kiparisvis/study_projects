/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topLayout;
    QPushButton *creditButton;
    QPushButton *depositButton;
    QLabel *comments;
    QPlainTextEdit *display;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QPushButton *b_sin;
    QPushButton *b_exp;
    QPushButton *b_5;
    QPushButton *b_7;
    QPushButton *b_4;
    QPushButton *b_sub;
    QPushButton *b_0;
    QPushButton *b_add;
    QPushButton *b_bracket_left;
    QPushButton *b_mul;
    QPushButton *b_sqrt;
    QPushButton *b_atan;
    QPushButton *b_1;
    QPushButton *b_log;
    QPushButton *b_asin;
    QPushButton *b_graph;
    QPushButton *b_tan;
    QPushButton *b_mod;
    QPushButton *b_9;
    QPushButton *b_bracket_right;
    QPushButton *b_x;
    QPushButton *b_ln;
    QPushButton *b_cos;
    QPushButton *b_acos;
    QPushButton *b_3;
    QPushButton *b_8;
    QGridLayout *gridLayout_2;
    QLabel *label_xmin;
    QLineEdit *lineEdit_xmin;
    QLabel *label_ymin;
    QLabel *label_ymax;
    QLabel *label_xmax;
    QLineEdit *lineEdit_ymin;
    QLineEdit *lineEdit_xmax;
    QLineEdit *lineEdit_ymax;
    QPushButton *b_6;
    QPushButton *b_2;
    QPushButton *b_enter;
    QPushButton *b_dot;
    QPushButton *b_div;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *line_x;
    QSpacerItem *horizontalSpacer;
    QPushButton *b_del;
    QPushButton *b_clear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(569, 520);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(569, 520));
        MainWindow->setMaximumSize(QSize(569, 520));
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setBaseSize(QSize(0, 0));
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setMinimumSize(QSize(569, 490));
        centralwidget->setMaximumSize(QSize(569, 16777215));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topLayout = new QHBoxLayout();
        topLayout->setSpacing(0);
        topLayout->setObjectName(QString::fromUtf8("topLayout"));
        topLayout->setSizeConstraint(QLayout::SetMinimumSize);
        topLayout->setContentsMargins(0, 0, 0, 0);
        creditButton = new QPushButton(centralwidget);
        creditButton->setObjectName(QString::fromUtf8("creditButton"));
        creditButton->setFocusPolicy(Qt::NoFocus);
        creditButton->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        topLayout->addWidget(creditButton);

        depositButton = new QPushButton(centralwidget);
        depositButton->setObjectName(QString::fromUtf8("depositButton"));
        depositButton->setFocusPolicy(Qt::NoFocus);
        depositButton->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));

        topLayout->addWidget(depositButton);


        verticalLayout->addLayout(topLayout);

        comments = new QLabel(centralwidget);
        comments->setObjectName(QString::fromUtf8("comments"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comments->sizePolicy().hasHeightForWidth());
        comments->setSizePolicy(sizePolicy2);
        comments->setMinimumSize(QSize(0, 25));
        comments->setMaximumSize(QSize(556, 25));
        comments->setStyleSheet(QString::fromUtf8(""));
        comments->setFrameShape(QFrame::Box);
        comments->setFrameShadow(QFrame::Raised);
        comments->setMidLineWidth(1);
        comments->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(comments);

        display = new QPlainTextEdit(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(5);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy3);
        display->setMinimumSize(QSize(0, 0));
        display->setMaximumSize(QSize(556, 16777215));
        QFont font;
        font.setPointSize(16);
        display->setFont(font);
        display->setFocusPolicy(Qt::NoFocus);
        display->setAcceptDrops(false);
        display->setStyleSheet(QString::fromUtf8(""));
        display->setFrameShape(QFrame::Box);
        display->setFrameShadow(QFrame::Raised);
        display->setMidLineWidth(1);
        display->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        display->setReadOnly(true);
        display->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        display->setCenterOnScroll(false);

        verticalLayout->addWidget(display);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(550, 348));
        widget->setMaximumSize(QSize(550, 348));
        widget->setBaseSize(QSize(560, 348));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        b_sin = new QPushButton(widget);
        b_sin->setObjectName(QString::fromUtf8("b_sin"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(b_sin->sizePolicy().hasHeightForWidth());
        b_sin->setSizePolicy(sizePolicy4);
        b_sin->setMinimumSize(QSize(68, 68));
        b_sin->setMaximumSize(QSize(68, 68));
        b_sin->setSizeIncrement(QSize(0, 0));
        b_sin->setBaseSize(QSize(68, 68));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        b_sin->setFont(font1);
        b_sin->setFocusPolicy(Qt::NoFocus);
        b_sin->setToolTipDuration(0);
        b_sin->setAutoDefault(false);
        b_sin->setFlat(false);

        gridLayout_3->addWidget(b_sin, 3, 6, 1, 1);

        b_exp = new QPushButton(widget);
        b_exp->setObjectName(QString::fromUtf8("b_exp"));
        sizePolicy4.setHeightForWidth(b_exp->sizePolicy().hasHeightForWidth());
        b_exp->setSizePolicy(sizePolicy4);
        b_exp->setMinimumSize(QSize(68, 68));
        b_exp->setMaximumSize(QSize(68, 68));
        b_exp->setSizeIncrement(QSize(0, 0));
        b_exp->setBaseSize(QSize(68, 68));
        b_exp->setFont(font1);
        b_exp->setFocusPolicy(Qt::NoFocus);
        b_exp->setToolTipDuration(0);
        b_exp->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 171, 171);"));
        b_exp->setAutoDefault(false);
        b_exp->setFlat(false);

        gridLayout_3->addWidget(b_exp, 3, 4, 1, 1);

        b_5 = new QPushButton(widget);
        b_5->setObjectName(QString::fromUtf8("b_5"));
        sizePolicy4.setHeightForWidth(b_5->sizePolicy().hasHeightForWidth());
        b_5->setSizePolicy(sizePolicy4);
        b_5->setMinimumSize(QSize(68, 68));
        b_5->setMaximumSize(QSize(68, 68));
        b_5->setSizeIncrement(QSize(0, 0));
        b_5->setBaseSize(QSize(68, 68));
        b_5->setFont(font1);
        b_5->setFocusPolicy(Qt::NoFocus);
        b_5->setToolTipDuration(0);
        b_5->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_5->setAutoDefault(false);
        b_5->setFlat(false);

        gridLayout_3->addWidget(b_5, 2, 1, 1, 1);

        b_7 = new QPushButton(widget);
        b_7->setObjectName(QString::fromUtf8("b_7"));
        sizePolicy4.setHeightForWidth(b_7->sizePolicy().hasHeightForWidth());
        b_7->setSizePolicy(sizePolicy4);
        b_7->setMinimumSize(QSize(68, 68));
        b_7->setMaximumSize(QSize(68, 68));
        b_7->setSizeIncrement(QSize(0, 0));
        b_7->setBaseSize(QSize(68, 68));
        b_7->setFont(font1);
        b_7->setFocusPolicy(Qt::NoFocus);
        b_7->setToolTipDuration(0);
        b_7->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_7->setAutoDefault(false);
        b_7->setFlat(false);

        gridLayout_3->addWidget(b_7, 3, 0, 1, 1);

        b_4 = new QPushButton(widget);
        b_4->setObjectName(QString::fromUtf8("b_4"));
        sizePolicy4.setHeightForWidth(b_4->sizePolicy().hasHeightForWidth());
        b_4->setSizePolicy(sizePolicy4);
        b_4->setMinimumSize(QSize(68, 68));
        b_4->setMaximumSize(QSize(68, 68));
        b_4->setSizeIncrement(QSize(0, 0));
        b_4->setBaseSize(QSize(68, 68));
        b_4->setFont(font1);
        b_4->setFocusPolicy(Qt::NoFocus);
        b_4->setToolTipDuration(0);
        b_4->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_4->setAutoDefault(false);
        b_4->setFlat(false);

        gridLayout_3->addWidget(b_4, 2, 0, 1, 1);

        b_sub = new QPushButton(widget);
        b_sub->setObjectName(QString::fromUtf8("b_sub"));
        sizePolicy4.setHeightForWidth(b_sub->sizePolicy().hasHeightForWidth());
        b_sub->setSizePolicy(sizePolicy4);
        b_sub->setMinimumSize(QSize(68, 68));
        b_sub->setMaximumSize(QSize(68, 68));
        b_sub->setSizeIncrement(QSize(0, 0));
        b_sub->setBaseSize(QSize(68, 68));
        b_sub->setFont(font1);
        b_sub->setFocusPolicy(Qt::NoFocus);
        b_sub->setToolTipDuration(0);
        b_sub->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));
        b_sub->setAutoDefault(false);
        b_sub->setFlat(false);

        gridLayout_3->addWidget(b_sub, 2, 3, 1, 1);

        b_0 = new QPushButton(widget);
        b_0->setObjectName(QString::fromUtf8("b_0"));
        sizePolicy4.setHeightForWidth(b_0->sizePolicy().hasHeightForWidth());
        b_0->setSizePolicy(sizePolicy4);
        b_0->setMinimumSize(QSize(68, 68));
        b_0->setMaximumSize(QSize(68, 68));
        b_0->setSizeIncrement(QSize(0, 0));
        b_0->setBaseSize(QSize(68, 68));
        b_0->setFont(font1);
        b_0->setFocusPolicy(Qt::NoFocus);
        b_0->setToolTipDuration(0);
        b_0->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_0->setAutoDefault(false);
        b_0->setFlat(false);

        gridLayout_3->addWidget(b_0, 4, 1, 1, 1);

        b_add = new QPushButton(widget);
        b_add->setObjectName(QString::fromUtf8("b_add"));
        sizePolicy4.setHeightForWidth(b_add->sizePolicy().hasHeightForWidth());
        b_add->setSizePolicy(sizePolicy4);
        b_add->setMinimumSize(QSize(68, 68));
        b_add->setMaximumSize(QSize(68, 68));
        b_add->setSizeIncrement(QSize(0, 0));
        b_add->setBaseSize(QSize(68, 68));
        b_add->setFont(font1);
        b_add->setFocusPolicy(Qt::NoFocus);
        b_add->setToolTipDuration(0);
        b_add->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));
        b_add->setAutoDefault(false);
        b_add->setFlat(false);

        gridLayout_3->addWidget(b_add, 1, 3, 1, 1);

        b_bracket_left = new QPushButton(widget);
        b_bracket_left->setObjectName(QString::fromUtf8("b_bracket_left"));
        sizePolicy4.setHeightForWidth(b_bracket_left->sizePolicy().hasHeightForWidth());
        b_bracket_left->setSizePolicy(sizePolicy4);
        b_bracket_left->setMinimumSize(QSize(68, 68));
        b_bracket_left->setMaximumSize(QSize(68, 68));
        b_bracket_left->setSizeIncrement(QSize(0, 0));
        b_bracket_left->setBaseSize(QSize(68, 68));
        b_bracket_left->setFont(font1);
        b_bracket_left->setFocusPolicy(Qt::NoFocus);
        b_bracket_left->setToolTipDuration(0);
        b_bracket_left->setAutoDefault(false);
        b_bracket_left->setFlat(false);

        gridLayout_3->addWidget(b_bracket_left, 1, 4, 1, 1);

        b_mul = new QPushButton(widget);
        b_mul->setObjectName(QString::fromUtf8("b_mul"));
        sizePolicy4.setHeightForWidth(b_mul->sizePolicy().hasHeightForWidth());
        b_mul->setSizePolicy(sizePolicy4);
        b_mul->setMinimumSize(QSize(68, 68));
        b_mul->setMaximumSize(QSize(68, 68));
        b_mul->setSizeIncrement(QSize(0, 0));
        b_mul->setBaseSize(QSize(68, 68));
        b_mul->setFont(font1);
        b_mul->setFocusPolicy(Qt::NoFocus);
        b_mul->setToolTipDuration(0);
        b_mul->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));
        b_mul->setAutoDefault(false);
        b_mul->setFlat(false);

        gridLayout_3->addWidget(b_mul, 3, 3, 1, 1);

        b_sqrt = new QPushButton(widget);
        b_sqrt->setObjectName(QString::fromUtf8("b_sqrt"));
        sizePolicy4.setHeightForWidth(b_sqrt->sizePolicy().hasHeightForWidth());
        b_sqrt->setSizePolicy(sizePolicy4);
        b_sqrt->setMinimumSize(QSize(68, 68));
        b_sqrt->setMaximumSize(QSize(68, 68));
        b_sqrt->setSizeIncrement(QSize(0, 0));
        b_sqrt->setBaseSize(QSize(68, 68));
        b_sqrt->setFont(font1);
        b_sqrt->setFocusPolicy(Qt::NoFocus);
        b_sqrt->setToolTipDuration(0);
        b_sqrt->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 171, 171);"));
        b_sqrt->setAutoDefault(false);
        b_sqrt->setFlat(false);

        gridLayout_3->addWidget(b_sqrt, 4, 4, 1, 1);

        b_atan = new QPushButton(widget);
        b_atan->setObjectName(QString::fromUtf8("b_atan"));
        sizePolicy4.setHeightForWidth(b_atan->sizePolicy().hasHeightForWidth());
        b_atan->setSizePolicy(sizePolicy4);
        b_atan->setMinimumSize(QSize(68, 68));
        b_atan->setMaximumSize(QSize(68, 68));
        b_atan->setSizeIncrement(QSize(0, 0));
        b_atan->setBaseSize(QSize(68, 68));
        b_atan->setFont(font1);
        b_atan->setFocusPolicy(Qt::NoFocus);
        b_atan->setToolTipDuration(0);
        b_atan->setAutoDefault(false);
        b_atan->setFlat(false);

        gridLayout_3->addWidget(b_atan, 4, 7, 1, 1);

        b_1 = new QPushButton(widget);
        b_1->setObjectName(QString::fromUtf8("b_1"));
        sizePolicy4.setHeightForWidth(b_1->sizePolicy().hasHeightForWidth());
        b_1->setSizePolicy(sizePolicy4);
        b_1->setMinimumSize(QSize(68, 68));
        b_1->setMaximumSize(QSize(68, 68));
        b_1->setSizeIncrement(QSize(0, 0));
        b_1->setBaseSize(QSize(68, 68));
        b_1->setFont(font1);
        b_1->setFocusPolicy(Qt::NoFocus);
        b_1->setToolTipDuration(0);
        b_1->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_1->setAutoDefault(false);
        b_1->setFlat(false);

        gridLayout_3->addWidget(b_1, 1, 0, 1, 1);

        b_log = new QPushButton(widget);
        b_log->setObjectName(QString::fromUtf8("b_log"));
        sizePolicy4.setHeightForWidth(b_log->sizePolicy().hasHeightForWidth());
        b_log->setSizePolicy(sizePolicy4);
        b_log->setMinimumSize(QSize(68, 68));
        b_log->setMaximumSize(QSize(68, 68));
        b_log->setSizeIncrement(QSize(0, 0));
        b_log->setBaseSize(QSize(68, 68));
        b_log->setFont(font1);
        b_log->setFocusPolicy(Qt::NoFocus);
        b_log->setToolTipDuration(0);
        b_log->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 171, 171);"));
        b_log->setAutoDefault(false);
        b_log->setFlat(false);

        gridLayout_3->addWidget(b_log, 2, 6, 1, 1);

        b_asin = new QPushButton(widget);
        b_asin->setObjectName(QString::fromUtf8("b_asin"));
        sizePolicy4.setHeightForWidth(b_asin->sizePolicy().hasHeightForWidth());
        b_asin->setSizePolicy(sizePolicy4);
        b_asin->setMinimumSize(QSize(68, 68));
        b_asin->setMaximumSize(QSize(68, 68));
        b_asin->setSizeIncrement(QSize(0, 0));
        b_asin->setBaseSize(QSize(68, 68));
        b_asin->setFont(font1);
        b_asin->setFocusPolicy(Qt::NoFocus);
        b_asin->setToolTipDuration(0);
        b_asin->setAutoDefault(false);
        b_asin->setFlat(false);

        gridLayout_3->addWidget(b_asin, 4, 6, 1, 1);

        b_graph = new QPushButton(widget);
        b_graph->setObjectName(QString::fromUtf8("b_graph"));
        sizePolicy4.setHeightForWidth(b_graph->sizePolicy().hasHeightForWidth());
        b_graph->setSizePolicy(sizePolicy4);
        b_graph->setMinimumSize(QSize(68, 136));
        b_graph->setMaximumSize(QSize(68, 136));
        b_graph->setSizeIncrement(QSize(0, 0));
        b_graph->setBaseSize(QSize(68, 136));
        b_graph->setFont(font);
        b_graph->setFocusPolicy(Qt::NoFocus);
        b_graph->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 153, 30);"));
        b_graph->setAutoDefault(false);
        b_graph->setFlat(false);

        gridLayout_3->addWidget(b_graph, 1, 7, 2, 1);

        b_tan = new QPushButton(widget);
        b_tan->setObjectName(QString::fromUtf8("b_tan"));
        sizePolicy4.setHeightForWidth(b_tan->sizePolicy().hasHeightForWidth());
        b_tan->setSizePolicy(sizePolicy4);
        b_tan->setMinimumSize(QSize(68, 68));
        b_tan->setMaximumSize(QSize(68, 68));
        b_tan->setSizeIncrement(QSize(0, 0));
        b_tan->setBaseSize(QSize(68, 68));
        b_tan->setFont(font1);
        b_tan->setFocusPolicy(Qt::NoFocus);
        b_tan->setToolTipDuration(0);
        b_tan->setAutoDefault(false);
        b_tan->setFlat(false);

        gridLayout_3->addWidget(b_tan, 3, 7, 1, 1);

        b_mod = new QPushButton(widget);
        b_mod->setObjectName(QString::fromUtf8("b_mod"));
        sizePolicy4.setHeightForWidth(b_mod->sizePolicy().hasHeightForWidth());
        b_mod->setSizePolicy(sizePolicy4);
        b_mod->setMinimumSize(QSize(68, 68));
        b_mod->setMaximumSize(QSize(68, 68));
        b_mod->setSizeIncrement(QSize(0, 0));
        b_mod->setBaseSize(QSize(68, 68));
        b_mod->setFont(font1);
        b_mod->setFocusPolicy(Qt::NoFocus);
        b_mod->setToolTipDuration(0);
        b_mod->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 171, 171);"));
        b_mod->setAutoDefault(false);
        b_mod->setFlat(false);

        gridLayout_3->addWidget(b_mod, 2, 4, 1, 1);

        b_9 = new QPushButton(widget);
        b_9->setObjectName(QString::fromUtf8("b_9"));
        sizePolicy4.setHeightForWidth(b_9->sizePolicy().hasHeightForWidth());
        b_9->setSizePolicy(sizePolicy4);
        b_9->setMinimumSize(QSize(68, 68));
        b_9->setMaximumSize(QSize(68, 68));
        b_9->setSizeIncrement(QSize(0, 0));
        b_9->setBaseSize(QSize(68, 68));
        b_9->setFont(font1);
        b_9->setFocusPolicy(Qt::NoFocus);
        b_9->setToolTipDuration(0);
        b_9->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_9->setAutoDefault(false);
        b_9->setFlat(false);

        gridLayout_3->addWidget(b_9, 3, 2, 1, 1);

        b_bracket_right = new QPushButton(widget);
        b_bracket_right->setObjectName(QString::fromUtf8("b_bracket_right"));
        sizePolicy4.setHeightForWidth(b_bracket_right->sizePolicy().hasHeightForWidth());
        b_bracket_right->setSizePolicy(sizePolicy4);
        b_bracket_right->setMinimumSize(QSize(68, 68));
        b_bracket_right->setMaximumSize(QSize(68, 68));
        b_bracket_right->setSizeIncrement(QSize(0, 0));
        b_bracket_right->setBaseSize(QSize(68, 68));
        b_bracket_right->setFont(font1);
        b_bracket_right->setFocusPolicy(Qt::NoFocus);
        b_bracket_right->setToolTipDuration(0);
        b_bracket_right->setAutoDefault(false);
        b_bracket_right->setFlat(false);

        gridLayout_3->addWidget(b_bracket_right, 1, 5, 1, 1);

        b_x = new QPushButton(widget);
        b_x->setObjectName(QString::fromUtf8("b_x"));
        sizePolicy4.setHeightForWidth(b_x->sizePolicy().hasHeightForWidth());
        b_x->setSizePolicy(sizePolicy4);
        b_x->setMinimumSize(QSize(68, 68));
        b_x->setMaximumSize(QSize(68, 68));
        b_x->setSizeIncrement(QSize(0, 0));
        b_x->setBaseSize(QSize(68, 68));
        b_x->setFont(font1);
        b_x->setFocusPolicy(Qt::NoFocus);
        b_x->setToolTipDuration(0);
        b_x->setAutoDefault(false);
        b_x->setFlat(false);

        gridLayout_3->addWidget(b_x, 1, 6, 1, 1);

        b_ln = new QPushButton(widget);
        b_ln->setObjectName(QString::fromUtf8("b_ln"));
        sizePolicy4.setHeightForWidth(b_ln->sizePolicy().hasHeightForWidth());
        b_ln->setSizePolicy(sizePolicy4);
        b_ln->setMinimumSize(QSize(68, 68));
        b_ln->setMaximumSize(QSize(68, 68));
        b_ln->setSizeIncrement(QSize(0, 0));
        b_ln->setBaseSize(QSize(68, 68));
        b_ln->setFont(font1);
        b_ln->setFocusPolicy(Qt::NoFocus);
        b_ln->setToolTipDuration(0);
        b_ln->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 171, 171);"));
        b_ln->setAutoDefault(false);
        b_ln->setFlat(false);

        gridLayout_3->addWidget(b_ln, 2, 5, 1, 1);

        b_cos = new QPushButton(widget);
        b_cos->setObjectName(QString::fromUtf8("b_cos"));
        sizePolicy4.setHeightForWidth(b_cos->sizePolicy().hasHeightForWidth());
        b_cos->setSizePolicy(sizePolicy4);
        b_cos->setMinimumSize(QSize(68, 68));
        b_cos->setMaximumSize(QSize(68, 68));
        b_cos->setSizeIncrement(QSize(0, 0));
        b_cos->setBaseSize(QSize(68, 68));
        b_cos->setFont(font1);
        b_cos->setFocusPolicy(Qt::NoFocus);
        b_cos->setToolTipDuration(0);
        b_cos->setAutoDefault(false);
        b_cos->setFlat(false);

        gridLayout_3->addWidget(b_cos, 3, 5, 1, 1);

        b_acos = new QPushButton(widget);
        b_acos->setObjectName(QString::fromUtf8("b_acos"));
        sizePolicy4.setHeightForWidth(b_acos->sizePolicy().hasHeightForWidth());
        b_acos->setSizePolicy(sizePolicy4);
        b_acos->setMinimumSize(QSize(68, 68));
        b_acos->setMaximumSize(QSize(68, 68));
        b_acos->setSizeIncrement(QSize(0, 0));
        b_acos->setBaseSize(QSize(68, 68));
        b_acos->setFont(font1);
        b_acos->setFocusPolicy(Qt::NoFocus);
        b_acos->setToolTipDuration(0);
        b_acos->setAutoDefault(false);
        b_acos->setFlat(false);

        gridLayout_3->addWidget(b_acos, 4, 5, 1, 1);

        b_3 = new QPushButton(widget);
        b_3->setObjectName(QString::fromUtf8("b_3"));
        sizePolicy4.setHeightForWidth(b_3->sizePolicy().hasHeightForWidth());
        b_3->setSizePolicy(sizePolicy4);
        b_3->setMinimumSize(QSize(68, 68));
        b_3->setMaximumSize(QSize(68, 68));
        b_3->setSizeIncrement(QSize(0, 0));
        b_3->setBaseSize(QSize(68, 68));
        b_3->setFont(font1);
        b_3->setFocusPolicy(Qt::NoFocus);
        b_3->setToolTipDuration(0);
        b_3->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_3->setAutoDefault(false);
        b_3->setFlat(false);

        gridLayout_3->addWidget(b_3, 1, 2, 1, 1);

        b_8 = new QPushButton(widget);
        b_8->setObjectName(QString::fromUtf8("b_8"));
        sizePolicy4.setHeightForWidth(b_8->sizePolicy().hasHeightForWidth());
        b_8->setSizePolicy(sizePolicy4);
        b_8->setMinimumSize(QSize(68, 68));
        b_8->setMaximumSize(QSize(68, 68));
        b_8->setSizeIncrement(QSize(0, 0));
        b_8->setBaseSize(QSize(68, 68));
        b_8->setFont(font1);
        b_8->setFocusPolicy(Qt::NoFocus);
        b_8->setToolTipDuration(0);
        b_8->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_8->setAutoDefault(false);
        b_8->setFlat(false);

        gridLayout_3->addWidget(b_8, 3, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_xmin = new QLabel(widget);
        label_xmin->setObjectName(QString::fromUtf8("label_xmin"));
        sizePolicy.setHeightForWidth(label_xmin->sizePolicy().hasHeightForWidth());
        label_xmin->setSizePolicy(sizePolicy);
        label_xmin->setMinimumSize(QSize(70, 35));
        label_xmin->setMaximumSize(QSize(70, 35));
        label_xmin->setStyleSheet(QString::fromUtf8(""));
        label_xmin->setFrameShape(QFrame::NoFrame);
        label_xmin->setFrameShadow(QFrame::Plain);
        label_xmin->setTextFormat(Qt::AutoText);
        label_xmin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_xmin, 0, 0, 1, 1);

        lineEdit_xmin = new QLineEdit(widget);
        lineEdit_xmin->setObjectName(QString::fromUtf8("lineEdit_xmin"));
        sizePolicy.setHeightForWidth(lineEdit_xmin->sizePolicy().hasHeightForWidth());
        lineEdit_xmin->setSizePolicy(sizePolicy);
        lineEdit_xmin->setMinimumSize(QSize(65, 25));
        lineEdit_xmin->setMaximumSize(QSize(65, 25));
        QFont font2;
        font2.setPointSize(10);
        lineEdit_xmin->setFont(font2);
        lineEdit_xmin->setStyleSheet(QString::fromUtf8(""));
        lineEdit_xmin->setMaxLength(8);
        lineEdit_xmin->setEchoMode(QLineEdit::Normal);
        lineEdit_xmin->setCursorPosition(0);
        lineEdit_xmin->setAlignment(Qt::AlignCenter);
        lineEdit_xmin->setClearButtonEnabled(false);

        gridLayout_2->addWidget(lineEdit_xmin, 0, 1, 1, 1);

        label_ymin = new QLabel(widget);
        label_ymin->setObjectName(QString::fromUtf8("label_ymin"));
        sizePolicy.setHeightForWidth(label_ymin->sizePolicy().hasHeightForWidth());
        label_ymin->setSizePolicy(sizePolicy);
        label_ymin->setMinimumSize(QSize(70, 35));
        label_ymin->setMaximumSize(QSize(70, 35));
        label_ymin->setStyleSheet(QString::fromUtf8(""));
        label_ymin->setFrameShape(QFrame::NoFrame);
        label_ymin->setFrameShadow(QFrame::Plain);
        label_ymin->setTextFormat(Qt::AutoText);
        label_ymin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_ymin, 1, 0, 1, 1);

        label_ymax = new QLabel(widget);
        label_ymax->setObjectName(QString::fromUtf8("label_ymax"));
        sizePolicy.setHeightForWidth(label_ymax->sizePolicy().hasHeightForWidth());
        label_ymax->setSizePolicy(sizePolicy);
        label_ymax->setMinimumSize(QSize(70, 35));
        label_ymax->setMaximumSize(QSize(70, 35));
        label_ymax->setStyleSheet(QString::fromUtf8(""));
        label_ymax->setFrameShape(QFrame::NoFrame);
        label_ymax->setFrameShadow(QFrame::Plain);
        label_ymax->setTextFormat(Qt::AutoText);
        label_ymax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_ymax, 1, 2, 1, 1);

        label_xmax = new QLabel(widget);
        label_xmax->setObjectName(QString::fromUtf8("label_xmax"));
        sizePolicy.setHeightForWidth(label_xmax->sizePolicy().hasHeightForWidth());
        label_xmax->setSizePolicy(sizePolicy);
        label_xmax->setMinimumSize(QSize(70, 35));
        label_xmax->setMaximumSize(QSize(70, 35));
        label_xmax->setStyleSheet(QString::fromUtf8(""));
        label_xmax->setFrameShape(QFrame::NoFrame);
        label_xmax->setFrameShadow(QFrame::Plain);
        label_xmax->setTextFormat(Qt::AutoText);
        label_xmax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_xmax, 0, 2, 1, 1);

        lineEdit_ymin = new QLineEdit(widget);
        lineEdit_ymin->setObjectName(QString::fromUtf8("lineEdit_ymin"));
        sizePolicy.setHeightForWidth(lineEdit_ymin->sizePolicy().hasHeightForWidth());
        lineEdit_ymin->setSizePolicy(sizePolicy);
        lineEdit_ymin->setMinimumSize(QSize(65, 25));
        lineEdit_ymin->setMaximumSize(QSize(65, 25));
        lineEdit_ymin->setFont(font2);
        lineEdit_ymin->setStyleSheet(QString::fromUtf8(""));
        lineEdit_ymin->setMaxLength(8);
        lineEdit_ymin->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_ymin, 1, 1, 1, 1);

        lineEdit_xmax = new QLineEdit(widget);
        lineEdit_xmax->setObjectName(QString::fromUtf8("lineEdit_xmax"));
        sizePolicy.setHeightForWidth(lineEdit_xmax->sizePolicy().hasHeightForWidth());
        lineEdit_xmax->setSizePolicy(sizePolicy);
        lineEdit_xmax->setMinimumSize(QSize(65, 25));
        lineEdit_xmax->setMaximumSize(QSize(65, 25));
        lineEdit_xmax->setFont(font2);
        lineEdit_xmax->setLayoutDirection(Qt::RightToLeft);
        lineEdit_xmax->setAutoFillBackground(false);
        lineEdit_xmax->setStyleSheet(QString::fromUtf8(""));
        lineEdit_xmax->setMaxLength(8);
        lineEdit_xmax->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_xmax, 0, 3, 1, 1);

        lineEdit_ymax = new QLineEdit(widget);
        lineEdit_ymax->setObjectName(QString::fromUtf8("lineEdit_ymax"));
        sizePolicy.setHeightForWidth(lineEdit_ymax->sizePolicy().hasHeightForWidth());
        lineEdit_ymax->setSizePolicy(sizePolicy);
        lineEdit_ymax->setMinimumSize(QSize(65, 25));
        lineEdit_ymax->setMaximumSize(QSize(65, 25));
        lineEdit_ymax->setFont(font2);
        lineEdit_ymax->setStyleSheet(QString::fromUtf8(""));
        lineEdit_ymax->setMaxLength(8);
        lineEdit_ymax->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_ymax, 1, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 4);

        b_6 = new QPushButton(widget);
        b_6->setObjectName(QString::fromUtf8("b_6"));
        sizePolicy4.setHeightForWidth(b_6->sizePolicy().hasHeightForWidth());
        b_6->setSizePolicy(sizePolicy4);
        b_6->setMinimumSize(QSize(68, 68));
        b_6->setMaximumSize(QSize(68, 68));
        b_6->setSizeIncrement(QSize(0, 0));
        b_6->setBaseSize(QSize(68, 68));
        b_6->setFont(font1);
        b_6->setFocusPolicy(Qt::NoFocus);
        b_6->setToolTipDuration(0);
        b_6->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_6->setAutoDefault(false);
        b_6->setFlat(false);

        gridLayout_3->addWidget(b_6, 2, 2, 1, 1);

        b_2 = new QPushButton(widget);
        b_2->setObjectName(QString::fromUtf8("b_2"));
        sizePolicy4.setHeightForWidth(b_2->sizePolicy().hasHeightForWidth());
        b_2->setSizePolicy(sizePolicy4);
        b_2->setMinimumSize(QSize(68, 68));
        b_2->setMaximumSize(QSize(68, 68));
        b_2->setSizeIncrement(QSize(0, 0));
        b_2->setBaseSize(QSize(68, 68));
        b_2->setFont(font1);
        b_2->setFocusPolicy(Qt::NoFocus);
        b_2->setToolTipDuration(0);
        b_2->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_2->setAutoDefault(false);
        b_2->setFlat(false);

        gridLayout_3->addWidget(b_2, 1, 1, 1, 1);

        b_enter = new QPushButton(widget);
        b_enter->setObjectName(QString::fromUtf8("b_enter"));
        sizePolicy4.setHeightForWidth(b_enter->sizePolicy().hasHeightForWidth());
        b_enter->setSizePolicy(sizePolicy4);
        b_enter->setMinimumSize(QSize(68, 68));
        b_enter->setMaximumSize(QSize(68, 68));
        b_enter->setSizeIncrement(QSize(0, 0));
        b_enter->setBaseSize(QSize(68, 68));
        b_enter->setFont(font1);
        b_enter->setFocusPolicy(Qt::NoFocus);
        b_enter->setToolTipDuration(0);
        b_enter->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 153, 30);"));
        b_enter->setAutoDefault(false);
        b_enter->setFlat(false);

        gridLayout_3->addWidget(b_enter, 4, 2, 1, 1);

        b_dot = new QPushButton(widget);
        b_dot->setObjectName(QString::fromUtf8("b_dot"));
        sizePolicy4.setHeightForWidth(b_dot->sizePolicy().hasHeightForWidth());
        b_dot->setSizePolicy(sizePolicy4);
        b_dot->setMinimumSize(QSize(68, 68));
        b_dot->setMaximumSize(QSize(68, 68));
        b_dot->setSizeIncrement(QSize(0, 0));
        b_dot->setBaseSize(QSize(68, 68));
        b_dot->setFont(font1);
        b_dot->setFocusPolicy(Qt::NoFocus);
        b_dot->setToolTipDuration(0);
        b_dot->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 219, 219);"));
        b_dot->setAutoDefault(false);
        b_dot->setFlat(false);

        gridLayout_3->addWidget(b_dot, 4, 0, 1, 1);

        b_div = new QPushButton(widget);
        b_div->setObjectName(QString::fromUtf8("b_div"));
        sizePolicy4.setHeightForWidth(b_div->sizePolicy().hasHeightForWidth());
        b_div->setSizePolicy(sizePolicy4);
        b_div->setMinimumSize(QSize(68, 68));
        b_div->setMaximumSize(QSize(68, 68));
        b_div->setSizeIncrement(QSize(0, 0));
        b_div->setBaseSize(QSize(68, 68));
        b_div->setFont(font1);
        b_div->setFocusPolicy(Qt::NoFocus);
        b_div->setToolTipDuration(0);
        b_div->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 145, 145);"));
        b_div->setAutoDefault(false);
        b_div->setFlat(false);

        gridLayout_3->addWidget(b_div, 4, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setMargin(5);

        horizontalLayout_2->addWidget(label);

        line_x = new QLineEdit(widget);
        line_x->setObjectName(QString::fromUtf8("line_x"));
        sizePolicy.setHeightForWidth(line_x->sizePolicy().hasHeightForWidth());
        line_x->setSizePolicy(sizePolicy);
        line_x->setMinimumSize(QSize(65, 25));
        line_x->setMaximumSize(QSize(65, 25));
        line_x->setFont(font2);
        line_x->setStyleSheet(QString::fromUtf8(""));
        line_x->setMaxLength(8);
        line_x->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(line_x);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 4, 1, 2);

        b_del = new QPushButton(widget);
        b_del->setObjectName(QString::fromUtf8("b_del"));
        sizePolicy4.setHeightForWidth(b_del->sizePolicy().hasHeightForWidth());
        b_del->setSizePolicy(sizePolicy4);
        b_del->setMinimumSize(QSize(68, 68));
        b_del->setMaximumSize(QSize(68, 68));
        b_del->setSizeIncrement(QSize(0, 0));
        b_del->setBaseSize(QSize(68, 68));
        b_del->setFont(font1);
        b_del->setFocusPolicy(Qt::NoFocus);
        b_del->setToolTipDuration(0);

        gridLayout_3->addWidget(b_del, 0, 6, 1, 1);

        b_clear = new QPushButton(widget);
        b_clear->setObjectName(QString::fromUtf8("b_clear"));
        sizePolicy4.setHeightForWidth(b_clear->sizePolicy().hasHeightForWidth());
        b_clear->setSizePolicy(sizePolicy4);
        b_clear->setMinimumSize(QSize(68, 68));
        b_clear->setMaximumSize(QSize(68, 68));
        b_clear->setSizeIncrement(QSize(0, 0));
        b_clear->setBaseSize(QSize(68, 68));
        b_clear->setFont(font1);
        b_clear->setFocusPolicy(Qt::NoFocus);
        b_clear->setToolTipDuration(0);
        b_clear->setAutoFillBackground(false);
        b_clear->setStyleSheet(QString::fromUtf8("background-color: rgb(242, 113, 114);"));

        gridLayout_3->addWidget(b_clear, 0, 7, 1, 1);

        gridLayout_3->setRowMinimumHeight(0, 73);
        gridLayout_3->setRowMinimumHeight(1, 73);
        gridLayout_3->setRowMinimumHeight(2, 73);
        gridLayout_3->setRowMinimumHeight(3, 73);
        gridLayout_3->setRowMinimumHeight(4, 73);

        verticalLayout->addWidget(widget, 0, Qt::AlignHCenter|Qt::AlignTop);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(lineEdit_xmin, lineEdit_xmax);
        QWidget::setTabOrder(lineEdit_xmax, lineEdit_ymin);
        QWidget::setTabOrder(lineEdit_ymin, lineEdit_ymax);
        QWidget::setTabOrder(lineEdit_ymax, line_x);

        retranslateUi(MainWindow);

        b_sin->setDefault(false);
        b_exp->setDefault(false);
        b_5->setDefault(false);
        b_7->setDefault(false);
        b_4->setDefault(false);
        b_sub->setDefault(false);
        b_0->setDefault(false);
        b_add->setDefault(false);
        b_bracket_left->setDefault(false);
        b_mul->setDefault(false);
        b_sqrt->setDefault(false);
        b_atan->setDefault(false);
        b_1->setDefault(false);
        b_log->setDefault(false);
        b_asin->setDefault(false);
        b_graph->setDefault(false);
        b_tan->setDefault(false);
        b_mod->setDefault(false);
        b_9->setDefault(false);
        b_bracket_right->setDefault(false);
        b_x->setDefault(false);
        b_ln->setDefault(false);
        b_cos->setDefault(false);
        b_acos->setDefault(false);
        b_3->setDefault(false);
        b_8->setDefault(false);
        b_6->setDefault(false);
        b_2->setDefault(false);
        b_enter->setDefault(false);
        b_dot->setDefault(false);
        b_div->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc", nullptr));
        creditButton->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        depositButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        comments->setText(QString());
        display->setPlainText(QCoreApplication::translate("MainWindow", "0", nullptr));
        b_sin->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        b_exp->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        b_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        b_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        b_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        b_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        b_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        b_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        b_bracket_left->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_bracket_left->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        b_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        b_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        b_atan->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        b_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        b_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        b_asin->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        b_graph->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        b_tan->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        b_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        b_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        b_bracket_right->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_bracket_right->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        b_x->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        b_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        b_cos->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        b_acos->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        b_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        b_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        label_xmin->setText(QCoreApplication::translate("MainWindow", "Xmin:  ", nullptr));
        lineEdit_xmin->setInputMask(QString());
        label_ymin->setText(QCoreApplication::translate("MainWindow", "Ymin:  ", nullptr));
        label_ymax->setText(QCoreApplication::translate("MainWindow", "Ymax:  ", nullptr));
        label_xmax->setText(QCoreApplication::translate("MainWindow", "Xmax:  ", nullptr));
        b_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        b_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        b_enter->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        b_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        b_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        b_del->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgb(145, 145, 145);", nullptr));
        b_del->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        b_clear->setText(QCoreApplication::translate("MainWindow", "\320\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
