#ifndef USERS_H
#define USERS_H

#include <QWidget>
#include <QTableWidget>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>

class Users : public QWidget
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    void addUser(const QString &name, const QString &ip, QLabel *status, const QString &connectedTime);
    QList<QCheckBox*> getCheckBoxes() const;
    void setAllCheckBoxes(bool checked);

signals:
    void userDeleted(const QString &name, const QString &ip, const QString &connectedTime);
    void checkBoxStateChanged();

private slots:
    void onIndividualCheckBoxToggled();

private:
    QTableWidget *tableWidget;
    QList<QCheckBox*> checkBoxes;
};

#endif // USERS_H

