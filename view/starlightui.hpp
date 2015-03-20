#ifndef STARLIGHTUI_HPP
#define STARLIGHTUI_HPP

#include <QMainWindow>

namespace Ui {
class StarlightUI;
}

class StarlightUI : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit StarlightUI(QWidget *parent = 0);
    ~StarlightUI();
    
private:
    Ui::StarlightUI *ui;
};

#endif // STARLIGHTUI_HPP
