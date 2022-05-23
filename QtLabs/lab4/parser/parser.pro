QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    function.cpp \
    main.cpp \
    mainwindow.cpp \
    pair.cpp \
    parser.cpp \
    variable.cpp

HEADERS += \
    function.h \
    mainwindow.h \
    pair.h \
    parser.h \
    variable.h

FORMS += \
    mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-MyString-Desktop_Qt_6_2_3_MinGW_64_bit-Release/release/ -lMyString
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-MyString-Desktop_Qt_6_2_3_MinGW_64_bit-Release/debug/ -lMyString

INCLUDEPATH += $$PWD/../../MyString
DEPENDPATH += $$PWD/../../MyString

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-MyString-Desktop_Qt_6_2_3_MinGW_64_bit-Release/release/ -lMyString
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-MyString-Desktop_Qt_6_2_3_MinGW_64_bit-Release/debug/ -lMyString

INCLUDEPATH += $$PWD/../../MyString
DEPENDPATH += $$PWD/../../MyString
