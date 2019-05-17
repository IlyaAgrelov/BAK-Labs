#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <vector>

namespace Ui {
class dialog2;
}

class dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit dialog2(QWidget *parent = nullptr);
    std::vector<double> getmass();
    std::vector<double> getcoordx();
    std::vector<double> getcoordy();
    std::vector<double> getspeedx();
    std::vector<double> getspeedy();
    ~dialog2();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::dialog2 *ui;
    std::vector<double> mass;
    std::vector<double> coordx;
    std::vector<double> coordy;
    std::vector<double> speedx;
    std::vector<double> speedy;
};

#endif // DIALOG2_H
