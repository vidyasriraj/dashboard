#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QGraphicsBlurEffect>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QLabel>
#include <QMessageBox>
#include <QMap>
#include <QVBoxLayout>
#include <QTableWidget>
#include  "users.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:

    void clickConnect();
    void setConnectedIcon(const QPixmap &pixmap, qreal opacity);
    void setViewPage(int index, QPushButton *clickedButton);
    void setSettings(int index, QPushButton *clickedButton);
    void setSidebar();
    void setSidebar2();
    void setLogsPage();
    void setDashboardPage();
    void setSettingsPage();
    // void setProfilePage();
    void setAboutUsPage();


    void setGeneralSettings();

    void setProxySettings();

    void setAdvancedSettings();

    void on_man_toggled(bool checked);
    void applyBlurEffect(QWidget* widget, bool apply) {
        if (apply) {
            QGraphicsBlurEffect* blurEffect = new QGraphicsBlurEffect(this);
            blurEffect->setBlurRadius(1.6);
            widget->setGraphicsEffect(blurEffect);
        } else {
            widget->setGraphicsEffect(nullptr);
        }
    }

    void setovpnFile();

    void setlogsFile();
    QMap<QString, QString> readKeyValuePairsFromFile(const QString &filePath) {
        QMap<QString, QString> keyValuePairs;
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Handle file open error
            return keyValuePairs;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" ");
            if (parts.size() == 2) {
                keyValuePairs.insert(parts[0].trimmed(), parts[1].trimmed());
            }
        }
        file.close();
        return keyValuePairs;
    }
    void value_read();
    void addUser();
    void handleDeletedUser(const QString &name, const QString &ip,  const QString &connectedTime);
    void processCheckBoxes();
    void onMainCheckBoxToggled(bool checked);
    void updateMainCheckBox();

    void setConfigurationPage();

    void setUsersPage();

    void details_box_update();



    void configSettings();

private:
    Ui::MainWindow *ui;

    QPixmap setPixmapOpacity(const QPixmap &pixmap, qreal opacity);

    QPushButton *previousPage;
    QPushButton *previousSettingsPage;
    Users *currentUsers;

};
#endif // MAINWINDOW_H
