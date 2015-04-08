#ifndef PREFS_H
#define PREFS_H

#include <QWidget>

#include <QGridLayout>
#include <QGroupBox>
#include <QDialogButtonBox>

class Properties : public QWidget
{
    Q_OBJECT

public:
    Properties(QWidget *parent = 0);
    void setupUi();
    void set_element_prop();

private:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QDialogButtonBox *buttonBox;

signals:

public slots:

};

#endif // PREFS_H
