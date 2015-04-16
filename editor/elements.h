#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>


#include "model/level.h"

#include "obs/observable.h"


class Elements : public QWidget, public Observable
{
    Q_OBJECT
public:
    explicit Elements(QWidget * parent = 0);
    Level * level();

    void set_height(int h);
    void set_width(int w);

    void enable_pushbuttons(bool b);

private:
    void setupUi();
    void add_connections();

    QVBoxLayout * verticalLayout;
    QGroupBox * groupBox;
    QLabel * level_height_label;
    QLabel * level_width_label;
    QPushButton * level_apply_pb;
    QPushButton * level_reset_pb;
    QDoubleSpinBox * level_height_dsb;
    QDoubleSpinBox * level_width_dsb;
    QPushButton * add_crystal_pb;
    QPushButton * add_mirror_pb;
    QPushButton * add_nuke_pb;
    QPushButton * add_lens_pb;
    QPushButton * add_wall_pb;

    Level * level_;


signals:

public slots:
    void add_crystal();
    void add_lens();
    void add_mirror();
    void add_nuke();
    void add_wall();
    void create_level();
    void reset_level();

};

#endif // ELEMENTS_H
