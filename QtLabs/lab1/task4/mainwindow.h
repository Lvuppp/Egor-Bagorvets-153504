#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtWidgets>
#include"member.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_membersList_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_name_editingFinished();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_age_editingFinished();

    void on_growth_editingFinished();

    void on_partnerAgeMax_editingFinished();

    void on_weight_editingFinished();

    void on_partnerAgeMin_editingFinished();

    void on_partnerGrowthMin_editingFinished();

    void on_partnerWeightMin_editingFinished();

    void on_partnerGrowthMax_editingFinished();

    void on_partnerWeightMax_editingFinished();

    void on_aboutYourself_editingFinished();

    void on_sex_currentIndexChanged(int index);

    void on_membersList_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFile _file;
    QVector<Member> _listOfMembers;
    QVector<int> _startPositions;
    QString  _operationType;
    QVector<QPair<Member,Member>> _pairs;
    QVector<QPair<int,int>> _pairsIndex;
    QString _storage = "C:/Users/User/Documents/task4/memb.txt";
    bool isTableExist = false;

    void drawTable();
    bool intValueIsCorrect(QLineEdit *widget,const int &minValue, const int &maxValue);
    bool strValueIsCorrect(QLineEdit *widget,const int &minValue, const int &maxValue);
    bool sexValueIsCorrect(QComboBox *widget,const int &index);
    bool isFormCorrect();


};
#endif // MAINWINDOW_H
