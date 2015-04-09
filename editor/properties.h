#ifndef PREFS_H
#define PREFS_H

#include <QWidget>

#include <QGridLayout>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QPushButton>

#include "obs/observable.h"

class Properties : public QWidget, public Observable
{
    Q_OBJECT

public:
    Properties(QWidget *parent = 0);
    void setupUi();
    void set_element_prop();



private:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
//    QDialogButtonBox *buttonBox;

    QPushButton *apply_pb;
    QPushButton *reset_pb;

    void add_connections();

signals:

public slots:

};

#endif // PREFS_H
