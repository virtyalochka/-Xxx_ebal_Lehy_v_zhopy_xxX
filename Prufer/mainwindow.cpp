#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug> // Распечатать консоль
#include <iostream>


using namespace std;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Node* root = new Node(2);
    Tree *pTree = new Tree(root); //Выделяем область памяти
    this->tree = *pTree; // Из указателя сделали объект(Разименование указателя)
    tree.create();
    tree.print(root,0);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //При нажатии этой кнопки должно быть созданно дерево
    //Для этого дерева должен быть подсчитан код прюфера
    // 1 Здесь мы должны взять информацию из окна редактирования, +
    // 2 преобразовать её в вектор, +
    // 3 и передать её программе chenge_info +
    QString s = ui->lineEdit->text(); //Получаем строку
    qDebug() << s;
    QStringList w=s.split(",");
    qDebug() << w;
    QVector<QString> vs=w.toVector();
    qDebug() << vs;
    vector <int> v_new;
    for (int i = 0; i<vs.size();i++){
        v_new.push_back(vs[i].toInt());

    }
    qDebug() << v_new.size();
    for (int i = 0; i<v_new.size();i++){
        qDebug() << v_new[i];

    }
    cout << endl;
    tree.change_info(v_new);
    cout << "-----------------------------------\n";
    tree.print(tree.root,0);
    tree.get_pruf_cod();
    // Поместим код Прюфера во второе окошко
    // Преобразовать элементы вектора в строку: В строку будем добавлять поэлементно
    QString spr;// Это строка в укоторую будем добавлять числа
    qDebug() << tree.prufer.size();
    for(int i = 0; i < tree.prufer.size();i++){
        spr+=QString::number(tree.prufer[i]);
    }
    qDebug() << spr;
    ui->lineEdit_2->setText(spr); // Выведем строку в окно

}


void MainWindow::on_pushButton_2_clicked()
{
    QString ss = ui->lineEdit_3->text(); //Получаем строку
    qDebug() << ss;
    QStringList ww=ss.split(",");
    qDebug() << ww;
    QVector<QString> vss=ww.toVector();
    qDebug() << vss;
    vector <int> vv_new;
    for (int i = 0; i<vss.size();i++){
        vv_new.push_back(vss[i].toInt());

    }
    qDebug() << vv_new.size();
    for (int i = 0; i<vv_new.size();i++){
        qDebug() << vv_new[i];
     }
    vector <vector <int>> smeg = get_smeg_by_cod_prufer(vv_new);
    QString s1;// Это строка в укоторую будем добавлять числа
    QString s2;
    QString s3;
    QString s4;
    QString s5;
    QString s6;
    QString s7;
    QString s8;
    QString s9;

    for(int i = 0; i < smeg[0].size();i++){
        s1+=QString::number(smeg[0][i]);
    }
    for(int i = 0; i < smeg[1].size();i++){
        s2+=QString::number(smeg[1][i]);
    }
    for(int i = 0; i < smeg[2].size();i++){
        s3+=QString::number(smeg[2][i]);
    }
    for(int i = 0; i < smeg[3].size();i++){
        s4+=QString::number(smeg[3][i]);
    }
    for(int i = 0; i < smeg[4].size();i++){
        s5+=QString::number(smeg[4][i]);
    }
    for(int i = 0; i < smeg[5].size();i++){
        s6+=QString::number(smeg[5][i]);
    }
    for(int i = 0; i < smeg[6].size();i++){
        s7+=QString::number(smeg[6][i]);
    }
    for(int i = 0; i < smeg[7].size();i++){
        s8+=QString::number(smeg[7][i]);
    }
    for(int i = 0; i < smeg[8].size();i++){
        s9+=QString::number(smeg[8][i]);
    }
    get_smeg_by_cod_prufer(vv_new);
    print_smeg(get_smeg_by_cod_prufer(vv_new));
    ui->lineEdit_4->setText(s1);
    ui->lineEdit_5->setText(s2);
    ui->lineEdit_6->setText(s3);
    ui->lineEdit_7->setText(s4);
    ui->lineEdit_8->setText(s5);
    ui->lineEdit_9->setText(s6);
    ui->lineEdit_10->setText(s7);
    ui->lineEdit_12->setText(s8);
    ui->lineEdit_13->setText(s9);





}

