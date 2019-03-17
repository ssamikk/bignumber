#include <QCoreApplication>
#include "bignumber.h"
#include <QString>
#include <QTextStream>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QTextStream cin(stdin);
    bool flag;
    do{
        std::cout<<"Enter first number:";
        QString s1 = cin.readLine();
        std::cout<<"Enter second number:";
        QString s2 = cin.readLine();
        BigNumber bn1(s1);
        BigNumber bn2(s2);
        bn1 = bn1 + bn2;
        qDebug()<<"Sum = "<<(bn1.isValid()? bn1.toString():"number is not valid");
        std::cout<<"Enter Y for repeat [No]:";
        s1 = cin.readLine();
        flag = (s1.toLower() == "y");
    }while(flag);
    return 0;
}
