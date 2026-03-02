#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged,
            this, [=]() {

                QList<QTableWidgetItem*> selected = ui->tableWidget->selectedItems();

                // If no selection OR multiple rows selected
                if(selected.isEmpty() || ui->tableWidget->selectionModel()->selectedRows().count() != 1) {

                    ui->nameEdit->clear();
                    ui->rollEdit->clear();
                    ui->courseEdit->clear();
                    ui->yearEdit->clear();
                    return;
                }

                int row = ui->tableWidget->currentRow();

                ui->nameEdit->setText(ui->tableWidget->item(row,0)->text());
                ui->rollEdit->setText(ui->tableWidget->item(row,1)->text());
                ui->courseEdit->setText(ui->tableWidget->item(row,2)->text());
                ui->yearEdit->setText(ui->tableWidget->item(row,3)->text());
            });
    connect(ui->editBtn, &QPushButton::clicked, this, [=]() {

        int row = ui->tableWidget->currentRow();

        if(row < 0){
            QMessageBox::warning(this,"Edit","Select a row first");
            return;
        }

        QString name = ui->nameEdit->text().trimmed();
        QString roll = ui->rollEdit->text().trimmed();
        QString course = ui->courseEdit->text().trimmed();
        QString year = ui->yearEdit->text().trimmed();

        // Prevent empty update
        if(name.isEmpty() || roll.isEmpty() || course.isEmpty() || year.isEmpty()){
            QMessageBox::warning(this,"Edit","Fields cannot be empty");
            return;
        }

        // Update table
        ui->tableWidget->item(row,0)->setText(name);
        ui->tableWidget->item(row,1)->setText(roll);
        ui->tableWidget->item(row,2)->setText(course);
        ui->tableWidget->item(row,3)->setText(year);

        // Remove selection //Remove the highlighted part
        ui->tableWidget->clearSelection();

        // Clear input fields
        ui->nameEdit->clear();
        ui->rollEdit->clear();
        ui->courseEdit->clear();
        ui->yearEdit->clear();

    });
    // set table columns
    ui->tableWidget->setColumnCount(4);
    QStringList headers;
    headers << "Name" << "Roll No" << "Course" << "Year";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QFile file("students.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);// Reading data from file

        while(!in.atEnd()) {
            QString line = in.readLine();
            QStringList data = line.split(",");

            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(data[0]));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(data[1]));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(data[2]));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(data[3]));
        }

        file.close();
    }
    updateStudentCount();
    ui->tableWidget->clearSelection();
    connect(ui->saveBtn, &QPushButton::clicked, this, [=]() {

        QFile file("students.txt");

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);//writing data to the file

            for(int row = 0; row < ui->tableWidget->rowCount(); row++) {

                QString name = ui->tableWidget->item(row,0)->text();
                QString roll = ui->tableWidget->item(row,1)->text();
                QString course = ui->tableWidget->item(row,2)->text();
                QString year = ui->tableWidget->item(row,3)->text();

                out << name << "," << roll << "," << course << "," << year << "\n";
            }

            file.close();
        }
    });
    // DELETE BUTTON
    connect(ui->deleteBtn, &QPushButton::clicked, this, [=]() {

        // 🔥 Check if anything is selected
        if(ui->tableWidget->selectedItems().isEmpty()) {
            QMessageBox::warning(this, "Delete", "Please select a student first");
            return;
        }

        int row = ui->tableWidget->currentRow();

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,
                                      "Confirm Delete",
                                      "Are you sure you want to delete this student?",
                                      QMessageBox::Yes | QMessageBox::No);

        if(reply == QMessageBox::Yes) {

            ui->tableWidget->removeRow(row);

            ui->nameEdit->clear();
            ui->rollEdit->clear();
            ui->courseEdit->clear();
            ui->yearEdit->clear();

            ui->tableWidget->clearSelection();
            updateStudentCount();
        }
    });
    // SEARCH BUTTON
    // SEARCH BUTTON
    connect(ui->searchBtn, &QPushButton::clicked, this, [=]() {

        QString searchRoll   = ui->rollSearchEdit->text().trimmed();
        QString searchCourse = ui->sCourseEdit->text().trimmed();
        QString searchYear   = ui->yearSearchEdit->text().trimmed();

        if(searchRoll.isEmpty() && searchCourse.isEmpty() && searchYear.isEmpty()) {
            QMessageBox::warning(this, "Search", "Enter at least one field to search");
            return;
        }

        ui->tableWidget->blockSignals(true);   // 🔥 IMPORTANT
        ui->tableWidget->clearSelection();

        bool found = false;

        for(int row = 0; row < ui->tableWidget->rowCount(); row++) {

            QString roll   = ui->tableWidget->item(row,1)->text().trimmed();
            QString course = ui->tableWidget->item(row,2)->text().trimmed();
            QString year   = ui->tableWidget->item(row,3)->text().trimmed();

            bool rollMatch =
                searchRoll.isEmpty() || (roll == searchRoll);

            bool courseMatch =
                searchCourse.isEmpty() ||
                (course.compare(searchCourse, Qt::CaseInsensitive) == 0);

            bool yearMatch =
                searchYear.isEmpty() ||
                (year.compare(searchYear, Qt::CaseInsensitive) == 0);

            if(rollMatch && courseMatch && yearMatch) {
                // for highlighting of the row
                ui->tableWidget->selectionModel()->select(
                    ui->tableWidget->model()->index(row, 0),
                    QItemSelectionModel::Select | QItemSelectionModel::Rows
                    );

                found = true;
            }
        }

        ui->tableWidget->blockSignals(false);   // 🔥 IMPORTANT

        if(!found) {
            QMessageBox::information(this, "Search", "No matching student found");
        }

        ui->rollSearchEdit->clear();
        ui->sCourseEdit->clear();
        ui->yearSearchEdit->clear();
    });
    // add student button click
    connect(ui->addBtn, &QPushButton::clicked, this, [=]() {

        QString name = ui->nameEdit->text().trimmed();
        QString roll = ui->rollEdit->text().trimmed();
        QString course = ui->courseEdit->text().trimmed();
        QString year = ui->yearEdit->text().trimmed();
        // 🔹 Check duplicate roll number
        for(int i = 0; i < ui->tableWidget->rowCount(); i++) {

            QString existingRoll = ui->tableWidget->item(i,1)->text().trimmed();

            if(existingRoll == roll) {
                QMessageBox::warning(this, "Duplicate Error",
                                     "Roll number already exists!");
                return;
            }
        }

        if(name.isEmpty() || roll.isEmpty() || course.isEmpty() || year.isEmpty()) {
            QMessageBox::warning(this, "Input Error", "All fields are required!");
            return;
        }

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row,0,new QTableWidgetItem(name));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(roll));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(course));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(year));

        // 🔹 Clear fields after adding
        ui->nameEdit->clear();
        ui->rollEdit->clear();
        ui->courseEdit->clear();
        ui->yearEdit->clear();
        ui->tableWidget->clearSelection();
        updateStudentCount();
    });
    connect(ui->clearBtn, &QPushButton::clicked, this, [=]() {

        // Clear input fields
        ui->nameEdit->clear();
        ui->rollEdit->clear();
        ui->courseEdit->clear();
        ui->yearEdit->clear();

        // Remove table selection
        ui->tableWidget->clearSelection();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (!ui->tableWidget->underMouse()) {
        ui->tableWidget->clearSelection();
    }

    QMainWindow::mousePressEvent(event);
}
void MainWindow::updateStudentCount()
{
    int total = ui->tableWidget->rowCount();
    ui->totalLabel->setText("Total Students: " + QString::number(total));
}
