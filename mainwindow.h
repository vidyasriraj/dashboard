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

    void on_connectIcon_clicked();
    void setConnectedIcon(const QPixmap &pixmap, qreal opacity);
    void setViewPage(int index, QPushButton *clickedButton);
    void setSettings(int index, QPushButton *clickedButton);
    void setSidebar();
    void setSidebar2();
    void setLogsPage();
    void setDashboardPage();
    void setSettingsPage();
    void setProfilePage();
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

    void on_browse2_clicked();

    void on_browse1_clicked();

private:
    Ui::MainWindow *ui;

    QPixmap setPixmapOpacity(const QPixmap &pixmap, qreal opacity);

    QPushButton *previousPage;
    QPushButton *previousSettingsPage;
};
#endif // MAINWINDOW_H
