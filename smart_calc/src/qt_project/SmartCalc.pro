QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../c_calc_polish.c \
    c_validate_input.c \
    creditwindow.cpp \
    depositwindow.cpp \
    graphwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    lib_qcustomplot/qcustomplot.cpp

HEADERS += \
    ../c_calc_polish.h \
    c_validate_input.h \
    creditwindow.h \
    depositwindow.h \
    graphwindow.h \
    mainwindow.h \
    lib_qcustomplot/qcustomplot.h

FORMS += \
    creditwindow.ui \
    depositwindow.ui \
    graphwindow.ui \
    mainwindow.ui

TRANSLATIONS += \
#    SmartCalc_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


