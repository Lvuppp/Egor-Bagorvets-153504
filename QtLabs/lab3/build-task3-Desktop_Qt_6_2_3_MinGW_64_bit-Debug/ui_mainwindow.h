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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *def;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QLineEdit *numA;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_12;
    QLineEdit *numB;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_11;
    QLineEdit *numC;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_10;
    QLineEdit *numD;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QLineEdit *numE;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_13;
    QLineEdit *answer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *opz;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1212, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 510, 101, 29));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 132, 1011, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        def = new QLineEdit(layoutWidget);
        def->setObjectName(QString::fromUtf8("def"));

        verticalLayout->addWidget(def);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(50, 16777215));

        verticalLayout_8->addWidget(label_8);

        numA = new QLineEdit(layoutWidget);
        numA->setObjectName(QString::fromUtf8("numA"));
        numA->setMaximumSize(QSize(50, 16777215));

        verticalLayout_8->addWidget(numA);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(50, 16777215));

        verticalLayout_12->addWidget(label_12);

        numB = new QLineEdit(layoutWidget);
        numB->setObjectName(QString::fromUtf8("numB"));
        numB->setMaximumSize(QSize(50, 16777215));

        verticalLayout_12->addWidget(numB);


        horizontalLayout->addLayout(verticalLayout_12);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(50, 16777215));

        verticalLayout_11->addWidget(label_11);

        numC = new QLineEdit(layoutWidget);
        numC->setObjectName(QString::fromUtf8("numC"));
        numC->setMaximumSize(QSize(50, 16777215));

        verticalLayout_11->addWidget(numC);


        horizontalLayout->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(50, 16777215));

        verticalLayout_10->addWidget(label_10);

        numD = new QLineEdit(layoutWidget);
        numD->setObjectName(QString::fromUtf8("numD"));
        numD->setMaximumSize(QSize(50, 16777215));

        verticalLayout_10->addWidget(numD);


        horizontalLayout->addLayout(verticalLayout_10);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(50, 16777215));

        verticalLayout_9->addWidget(label_9);

        numE = new QLineEdit(layoutWidget);
        numE->setObjectName(QString::fromUtf8("numE"));
        numE->setMaximumSize(QSize(50, 16777215));

        verticalLayout_9->addWidget(numE);


        horizontalLayout->addLayout(verticalLayout_9);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(50, 16777215));

        verticalLayout_13->addWidget(label_13);

        answer = new QLineEdit(layoutWidget);
        answer->setObjectName(QString::fromUtf8("answer"));
        answer->setMaximumSize(QSize(70, 16777215));
        answer->setReadOnly(true);

        verticalLayout_13->addWidget(answer);


        horizontalLayout->addLayout(verticalLayout_13);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        opz = new QLineEdit(layoutWidget);
        opz->setObjectName(QString::fromUtf8("opz"));
        opz->setMinimumSize(QSize(100, 0));
        opz->setReadOnly(true);

        verticalLayout_2->addWidget(opz);


        horizontalLayout->addLayout(verticalLayout_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 210, 581, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1212, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\213\321\207\320\275\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "a", nullptr));
        numA->setInputMask(QString());
        numA->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
        numB->setInputMask(QString());
        numB->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "c", nullptr));
        numC->setInputMask(QString());
        numC->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "d", nullptr));
        numD->setInputMask(QString());
        numD->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        numE->setInputMask(QString());
        numE->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\236\320\237\320\227", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\225\321\201\320\273\320\270 \320\262 \321\217\321\207\320\265\320\271\320\272\321\203 \320\275\320\270\321\207\320\265\320\263\320\276 \320\275\320\265 \320\262\320\262\320\276\320\264\320\270\321\202\321\214\321\201\321\217 \321\202\320\276 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\320\260\321\217 \321\201\321\207\320\270\321\202\320\260\320\265\321\202\321\214\321\201\321\217 \321\200\320\260\320\262\320\275\320\260\321\217 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
