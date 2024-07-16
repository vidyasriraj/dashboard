#include "users.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>

#include "customDelegate.h"

Users::Users(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Create the table widget
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(6); // Set the number of columns
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->verticalHeader()->setVisible(false); // Hide vertical header
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Stretch to fit the container
    tableWidget->setShowGrid(false);
    tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->verticalHeader()->setDefaultSectionSize(70); // Set default row height
    tableWidget->setColumnWidth(0, 50);
    tableWidget->setColumnWidth(1, 150);  // Set width of column 1 to 150 pixels
    tableWidget->setColumnWidth(2, 350);
    tableWidget->setColumnWidth(3, 200);
    tableWidget->setColumnWidth(4, 150);
    tableWidget->setColumnWidth(5, 50);
    tableWidget->setStyleSheet(
        "QTableWidget {"
        "    background-color: rgba(0,0,0,0);"
        "    border:none;"
        "    color: white;"

        "}"

        );
    tableWidget->setItemDelegate(new customDelegate(tableWidget));
    tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Add the table widget to the main layout
    mainLayout->addWidget(tableWidget);
    mainLayout->setAlignment(Qt::AlignCenter | Qt::AlignRight);
}

void Users::addUser(const QString &name, const QString &ip, QLabel *status, const QString &connectedTime) {
    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);

    QCheckBox *checkbox = new QCheckBox(this);
    checkbox->setStyleSheet(
        "QCheckBox {"
        "    background-color: transparent;"
        "    color: white;"
        "    margin-left: 40px;"
        "}"
        "QCheckBox::indicator {"
        "    border: 1px solid white;"
        "    border-radius: 3px;"
        "    width: 15px;"
        "    height: 15px;"
        "    background-color: transparent;"
        "}"
        "QCheckBox::indicator:checked {"
        "    image: url(:/logos/new.png);"
        "    background-color: transparent;"
        "    border: 1px solid white;"
        "}"
        "QCheckBox::indicator:unchecked {"
        "    background-color: transparent;"
        "    border: 1px solid white;"
        "}"
        );
    checkBoxes.append(checkbox);
    connect(checkbox, &QCheckBox::toggled, this, &Users::onIndividualCheckBoxToggled);

    // Add a checkbox to the first column
    tableWidget->setCellWidget(row, 0, checkbox);

    // Create and add a non-editable name item
    QTableWidgetItem *nameItem = new QTableWidgetItem(name);
    nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable); // Make it non-editable
    tableWidget->setItem(row, 1, nameItem);

    // Create and add a non-editable IP item
    QTableWidgetItem *ipItem = new QTableWidgetItem(ip);
    ipItem->setFlags(ipItem->flags() & ~Qt::ItemIsEditable); // Make it non-editable
    tableWidget->setItem(row, 2, ipItem);

    // Add a status widget to the fourth column
    status->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    tableWidget->setCellWidget(row, 3, status);


    // Create and add a non-editable connected time item
    QTableWidgetItem *connectedTimeItem = new QTableWidgetItem(connectedTime);
    connectedTimeItem->setFlags(connectedTimeItem->flags() & ~Qt::ItemIsEditable); // Make it non-editable
    tableWidget->setItem(row, 4, connectedTimeItem);

    // Add a delete button to the sixth column
    QPushButton *deleteButton = new QPushButton(QIcon(":/logos/Delete.png"), "", this);
    tableWidget->setCellWidget(row, 5, deleteButton);

    connect(deleteButton, &QPushButton::clicked, [=]() mutable {
        // Create a message box for confirmation
        QMessageBox msgBox;
        msgBox.setWindowTitle("Delete User");
        msgBox.setText("Are you sure you want to delete this user?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        QRect parentRect = tableWidget->geometry();
        QPoint x = parentRect.center() ;
        msgBox.move(x);

        // Apply black color stylesheet
        msgBox.setStyleSheet(
            "QMessageBox {"
            "    background-color: #2D3233;"    // Dark background
            "    color: #FFFFFF;"               // White text
            "}"
            "QPushButton {"
            "    background-color: #333333;"    // Dark grey button
            "    color: #FFFFFF;"               // White text
            "    border: 1px solid #555555;"    // Border color
            "    padding: 5px 10px;"            // Button padding
            "}"
            "QPushButton:hover {"
            "    background-color: #444444;"    // Slightly lighter button on hover
            "}"
            "QPushButton:pressed {"
            "    background-color: #555555;"    // Even lighter button on press
            "}"
            );

        // Execute the message box and handle the response
        if (msgBox.exec() == QMessageBox::Yes) {
            emit userDeleted(nameItem->text(), ipItem->text(), connectedTimeItem->text());

            int currentRow = tableWidget->row(nameItem); // Get the current row index

            // Remove the row from the table
            tableWidget->removeRow(currentRow);

            // No need to delete checkbox or other widgets, they are managed by the table
        }
    });
}

QList<QCheckBox*> Users::getCheckBoxes() const {
    return checkBoxes;
}

void Users::setAllCheckBoxes(bool checked) {
    for (QCheckBox* checkbox : checkBoxes) {
        checkbox->setChecked(checked);
    }
}

void Users::onIndividualCheckBoxToggled() {
    emit checkBoxStateChanged();
}
