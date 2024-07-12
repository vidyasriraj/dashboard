#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <QWidget>
#include <QtQuickWidgets/QtQuickWidgets>
#include <QGraphicsDropShadowEffect>
#include <QButtonGroup>
#include <QPropertyAnimation>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),previousPage(nullptr),previousSettingsPage(nullptr)
{
    ui->setupUi(this);
    setDashboardPage();
    ui->sidebar_2->hide();

    ui->connectIcon->setIcon(QIcon(":/logos/connect_icon.png"));
    ui->connectsym->setPixmap(QPixmap(":/logos/red.png"));
    ui->mapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->mapWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));

    connect(ui->connectIcon, SIGNAL(clicked(bool)), this, SLOT(on_connectIcon_clicked()));


    connect(ui->menu, SIGNAL(clicked()), this, SLOT(setSidebar()));
    connect(ui->menu_1, SIGNAL(clicked()), this, SLOT(setSidebar2()));
    connect(ui->logsButton, SIGNAL(clicked()), this, SLOT(setLogsPage()));
    connect(ui->dashboardButton, SIGNAL(clicked()), this, SLOT(setDashboardPage()));
    connect(ui->settingsButton, SIGNAL(clicked()), this, SLOT(setSettingsPage()));
    connect(ui->profileButton, SIGNAL(clicked()), this, SLOT(setProfilePage()));
    connect(ui->aboutButton, SIGNAL(clicked()), this, SLOT(setAboutUsPage()));
    applyBlurEffect(ui->op1, true);
    applyBlurEffect(ui->op2, true);
    ui->op1->setEnabled(false);
    ui->op2->setEnabled(false);
    applyBlurEffect(ui->add, true);
    applyBlurEffect(ui->add_inp, true);
    ui->add->setEnabled(false);
    ui->add_inp->setEnabled(false);
    applyBlurEffect(ui->port, true);
    applyBlurEffect(ui->port_inp, true);
    ui->port->setEnabled(false);
    ui->port_inp->setEnabled(false);

    setGeneralSettings();
    connect(ui->generalButton, SIGNAL(clicked()), this, SLOT(setGeneralSettings()));
    connect(ui->proxyButton, SIGNAL(clicked()), this, SLOT(setProxySettings()));
    connect(ui->advancedButton, SIGNAL(clicked()), this, SLOT(setAdvancedSettings()));

    connect(ui->browse1, SIGNAL(clicked()), this, SLOT(on_browse1_clicked()));
    connect(ui->browse2, SIGNAL(clicked()), this, SLOT(on_browse2_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QPixmap MainWindow::setPixmapOpacity(const QPixmap &pixmap, qreal opacity) {
    QPixmap newPixmap(pixmap.size());
    newPixmap.fill(Qt::transparent);

    QPainter painter(&newPixmap);
    painter.setOpacity(opacity);
    painter.drawPixmap(0, 0, pixmap);
    painter.end();

    return newPixmap;
}

// method to change the image of connected button after connecting and disconnecting
void MainWindow::setConnectedIcon(const QPixmap &pixmap, qreal opacity) {
    QPixmap newPixmap = setPixmapOpacity(pixmap, opacity);
    ui->connectIcon->setIcon(QIcon(newPixmap));

}

// method to establish connection with the server


void MainWindow::on_connectIcon_clicked()
{
    QPixmap pixmap,pixmap2;

    QString connectText;
    if (ui->connectIcon->isChecked()) {
        connectText = "Connected";
        pixmap = QPixmap(":/logos/connected_icon.png");
        pixmap2 = QPixmap(":/logos/green.png");

    } else {
        connectText = "Disconnected";
        pixmap = QPixmap(":/logos/connect_icon.png");
        pixmap2 = QPixmap(":/logos/red.png");
    }
    pixmap = pixmap.scaled(ui->connectIcon->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    qreal opacity = 0.3;
    QPixmap newPixmap = setPixmapOpacity(pixmap, opacity);
    QPixmap newPixmap2 = setPixmapOpacity(pixmap2, 1);
    ui->connectIcon->setIcon(QIcon(newPixmap));
    ui->connectsym->setPixmap(newPixmap2);

    for (int i = 0; i <= 7; ++i) {
        QTimer::singleShot(60 * i, this, [this, pixmap, opacity, i]() {
            setConnectedIcon(pixmap, opacity + 0.1 * i);
        });
    }
    ui->connectText->setText(connectText);
    ui->connectText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

}

void MainWindow::setViewPage(int index, QPushButton *clickedButton) {
    ui->stackedWidget->setCurrentIndex(index);

    if (clickedButton != nullptr) {
        clickedButton->setStyleSheet("background-color: rgb(121,121,121);border-radius:8px;color: rgb(255, 255, 255);border:  none;text-align:left;QPushButton::focus { background-color:rgb(217, 217, 217); }");
    }

    if (previousPage != nullptr && previousPage != clickedButton) {
        previousPage->setStyleSheet("background-color: rgba(0, 0, 0,0);color: rgb(255, 255, 255);border:  none;text-align:left;");
    }

    previousPage = clickedButton;

}


void MainWindow::setSidebar()
{
    ui->sidebar->hide();
    ui->sidebar_2->show();
}


void MainWindow::setSidebar2()
{
    ui->sidebar_2->hide();
    ui->sidebar->show();
}


void MainWindow::setLogsPage()
{
    setViewPage(1,ui->logsButton);
    ui->menu_1->setEnabled(false);
}


void MainWindow::setDashboardPage()
{
    ui->menu_1->setEnabled(true);
    setViewPage(0,ui->dashboardButton);
}


void MainWindow::setSettingsPage()
{
    setViewPage(2,ui->settingsButton);
    ui->menu_1->setEnabled(false);
}


void MainWindow::setProfilePage()
{
    setViewPage(3,ui->profileButton);
    ui->menu_1->setEnabled(false);
}


void MainWindow::setAboutUsPage()
{
    setViewPage(4,ui->aboutButton);
    ui->menu_1->setEnabled(false);
}

void MainWindow::setSettings(int index, QPushButton *clickedButton) {
    ui->stackedWidget_2->setCurrentIndex(index);

    if (clickedButton != nullptr) {
        clickedButton->setStyleSheet("background-color: rgb(121,121,121);border-radius:8px;color: rgb(255, 255, 255);border:  none;text-align:left;QPushButton::focus { background-color:rgb(217, 217, 217); }");
    }

    if (previousSettingsPage != nullptr && previousPage != clickedButton) {
        previousSettingsPage->setStyleSheet("background-color: rgba(0, 0, 0,0);color: rgb(255, 255, 255);border:  none;text-align:left;");
    }

    previousSettingsPage = clickedButton;

}


void MainWindow::setGeneralSettings()
{
    setSettings(0,ui->generalButton);
}


void MainWindow::setProxySettings()
{
    setSettings(1,ui->proxyButton);
}


void MainWindow::setAdvancedSettings()
{
    setSettings(2,ui->advancedButton);
}


void MainWindow::on_man_toggled(bool checked)
{
    applyBlurEffect(ui->op1, !checked);
    applyBlurEffect(ui->op2, !checked);
    applyBlurEffect(ui->add, !checked);
    applyBlurEffect(ui->port, !checked);
    applyBlurEffect(ui->add_inp, !checked);
    applyBlurEffect(ui->port_inp, !checked);
    ui->op1->setEnabled(checked);
    ui->op2->setEnabled(checked);
    ui->add->setEnabled(checked);
    ui->add_inp->setEnabled(checked);
    ui->port->setEnabled(checked);
    ui->port_inp->setEnabled(checked);
}


void MainWindow::on_browse2_clicked()
{
    QFileDialog fileDialog(this, "Select .ovpn File");

    // Set options for the file dialog to only show files
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setNameFilter("Text Files (*.txt)");
    QString styleSheet = "QFileDialog { background-color: #2D3233; }"
                         "QFileDialog QLabel { color: #FFFFFF; }"
                         "QFileDialog QToolButton { background-color: #2D3233; color: #FFFFFF; }"
                         "QFileDialog QPushButton { background-color: #2D3233; color: #FFFFFF; border: 1px solid #FFFFFF; }"
                         "QFileDialog QListView { background-color: #1C1F1F; color: #FFFFFF; }"
                         "QFileDialog QTreeView { background-color: #1C1F1F; color: #FFFFFF; }";
    fileDialog.setStyleSheet(styleSheet);

    // Show the dialog and get the selected file
    QString fileName = fileDialog.getOpenFileName(this, "Select .txt File", "", "Text Files (*.txt)");

    // Check if a file was selected
    if (!fileName.isEmpty()) {
        // Set the selected file path to the UI element
        ui->path_2->setText(fileName);
    }

    // Close the dialog explicitly (though it closes automatically when the selection is made)
    fileDialog.close();
}


void MainWindow::on_browse1_clicked()
{
    QFileDialog fileDialog(this, "Select .ovpn File");

    // Set options for the file dialog to only show files
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setNameFilter("OpenVPN Files (*.ovpn)");
    QString styleSheet = "QFileDialog { background-color: #ffffff; }"
                         "QFileDialog QLabel { color: #FFFFFF; }"
                         "QFileDialog QToolButton { background-color: #2D3233; color: #FFFFFF; }"
                         "QFileDialog QPushButton { background-color: #2D3233; color: #FFFFFF; border: 1px solid #FFFFFF; }"
                         "QFileDialog QListView { background-color: #1C1F1F; color: #FFFFFF; }"
                         "QFileDialog QTreeView { background-color: #1C1F1F; color: #FFFFFF; }";
    fileDialog.setStyleSheet(styleSheet);

    // Show the dialog and get the selected file
    QString fileName = fileDialog.getOpenFileName(this, "Select .ovpn File", "", "OpenVPN Files (*.ovpn)");

    // Check if a file was selected
    if (!fileName.isEmpty()) {
        // Set the selected file path to the UI element
        ui->path->setText(fileName);
    }

    // Close the dialog explicitly (though it closes automatically when the selection is made)
    fileDialog.close();
}

