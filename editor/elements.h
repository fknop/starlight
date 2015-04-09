#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QWidget>

#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QDoubleSpinBox>

#include "obs/observable.h"
#include "model/level.h"

class Elements : public QWidget, public Observable
{
    Q_OBJECT
public:
    explicit Elements(QWidget *parent = 0);
    Level * level();

private:
    void setupUi();
    void add_connections();

    QVBoxLayout *verticalLayout;
    QGroupBox * groupBox;
    QLabel * level_height_label;
    QLabel * level_width_label;
    QPushButton *level_apply_pb;
    QPushButton *level_reset_pb;
    QDoubleSpinBox *level_height_dsb;
    QDoubleSpinBox *level_width_dsb;
    QPushButton *add_mirror_pb;
    QPushButton *add_nuke_pb;
    QPushButton *add_lens_pb;

    Level * level_;


signals:

public slots:
    void add_mirror();
    void create_level();
    void reset_level();

};

#endif // ELEMENTS_H
