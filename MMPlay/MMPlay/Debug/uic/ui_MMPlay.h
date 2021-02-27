/********************************************************************************
** Form generated from reading UI file 'MMPlay.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MMPLAY_H
#define UI_MMPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MMPlayClass
{
public:
    QWidget *centralWidget;
    QSlider *progressBar;
    QPushButton *openFileBtn;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QPushButton *fullScrBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MMPlayClass)
    {
        if (MMPlayClass->objectName().isEmpty())
            MMPlayClass->setObjectName(QString::fromUtf8("MMPlayClass"));
        MMPlayClass->resize(600, 400);
        centralWidget = new QWidget(MMPlayClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        progressBar = new QSlider(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 290, 441, 22));
        progressBar->setOrientation(Qt::Horizontal);
        openFileBtn = new QPushButton(centralWidget);
        openFileBtn->setObjectName(QString::fromUtf8("openFileBtn"));
        openFileBtn->setGeometry(QRect(21, 314, 75, 23));
        playBtn = new QPushButton(centralWidget);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        playBtn->setGeometry(QRect(102, 314, 75, 23));
        stopBtn = new QPushButton(centralWidget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        stopBtn->setGeometry(QRect(183, 314, 75, 23));
        fullScrBtn = new QPushButton(centralWidget);
        fullScrBtn->setObjectName(QString::fromUtf8("fullScrBtn"));
        fullScrBtn->setGeometry(QRect(264, 314, 75, 23));
        MMPlayClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MMPlayClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        MMPlayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MMPlayClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MMPlayClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MMPlayClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MMPlayClass->setStatusBar(statusBar);

        retranslateUi(MMPlayClass);

        QMetaObject::connectSlotsByName(MMPlayClass);
    } // setupUi

    void retranslateUi(QMainWindow *MMPlayClass)
    {
        MMPlayClass->setWindowTitle(QApplication::translate("MMPlayClass", "MMPlay", nullptr));
        openFileBtn->setText(QApplication::translate("MMPlayClass", "open", nullptr));
        playBtn->setText(QApplication::translate("MMPlayClass", "start", nullptr));
        stopBtn->setText(QApplication::translate("MMPlayClass", "stop", nullptr));
        fullScrBtn->setText(QApplication::translate("MMPlayClass", "fullScr", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MMPlayClass: public Ui_MMPlayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MMPLAY_H
