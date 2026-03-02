/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *rollEdit;
    QLabel *label_3;
    QLineEdit *courseEdit;
    QLabel *label_4;
    QLineEdit *yearEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *rollSearchEdit;
    QLabel *label_6;
    QLineEdit *sCourseEdit;
    QLabel *label8;
    QLineEdit *yearSearchEdit;
    QPushButton *searchBtn;
    QTableWidget *tableWidget;
    QLabel *totalLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveBtn;
    QPushButton *addBtn;
    QPushButton *deleteBtn;
    QPushButton *editBtn;
    QPushButton *clearBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(685, 600);
        QFont font;
        font.setBold(false);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(0, 0));
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        centralwidget->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_7->setWordWrap(true);

        verticalLayout->addWidget(label_7);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        rollEdit = new QLineEdit(centralwidget);
        rollEdit->setObjectName("rollEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, rollEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        courseEdit = new QLineEdit(centralwidget);
        courseEdit->setObjectName("courseEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, courseEdit);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        yearEdit = new QLineEdit(centralwidget);
        yearEdit->setObjectName("yearEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, yearEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        rollSearchEdit = new QLineEdit(centralwidget);
        rollSearchEdit->setObjectName("rollSearchEdit");

        horizontalLayout_2->addWidget(rollSearchEdit);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        horizontalLayout_2->addWidget(label_6);

        sCourseEdit = new QLineEdit(centralwidget);
        sCourseEdit->setObjectName("sCourseEdit");

        horizontalLayout_2->addWidget(sCourseEdit);

        label8 = new QLabel(centralwidget);
        label8->setObjectName("label8");

        horizontalLayout_2->addWidget(label8);

        yearSearchEdit = new QLineEdit(centralwidget);
        yearSearchEdit->setObjectName("yearSearchEdit");

        horizontalLayout_2->addWidget(yearSearchEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        searchBtn = new QPushButton(centralwidget);
        searchBtn->setObjectName("searchBtn");

        verticalLayout->addWidget(searchBtn);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget->setColumnCount(4);

        verticalLayout->addWidget(tableWidget);

        totalLabel = new QLabel(centralwidget);
        totalLabel->setObjectName("totalLabel");

        verticalLayout->addWidget(totalLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        saveBtn = new QPushButton(centralwidget);
        saveBtn->setObjectName("saveBtn");

        horizontalLayout->addWidget(saveBtn);

        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName("addBtn");

        horizontalLayout->addWidget(addBtn);

        deleteBtn = new QPushButton(centralwidget);
        deleteBtn->setObjectName("deleteBtn");

        horizontalLayout->addWidget(deleteBtn);

        editBtn = new QPushButton(centralwidget);
        editBtn->setObjectName("editBtn");

        horizontalLayout->addWidget(editBtn);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");

        horizontalLayout->addWidget(clearBtn);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(4, 1);

        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 685, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Student Management System", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "STUDENT MANAGEMENT SYSTEM", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Roll No:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Course:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Year:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Search Roll No:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Search Course:", nullptr));
        label8->setText(QCoreApplication::translate("MainWindow", "Search Year:", nullptr));
        searchBtn->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        totalLabel->setText(QCoreApplication::translate("MainWindow", "Total Student:", nullptr));
        saveBtn->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "Add Student", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        editBtn->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
