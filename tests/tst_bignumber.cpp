#include <QtTest>
#include "bignumber.h"

class TestBigNumber : public QObject
{
    Q_OBJECT

public:
    TestBigNumber();
    ~TestBigNumber();

private slots:
    void sum_data();
    void sum();

};

TestBigNumber::TestBigNumber()
{

}

TestBigNumber::~TestBigNumber()
{

}

void TestBigNumber::sum_data()
{
    QTest::addColumn<QString>("first");
    QTest::addColumn<QString>("second");
    QTest::addColumn<QString>("result");

    QTest::newRow("sum_data_1")
            << "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
            << "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
            << "24691357802469135780246913578024691357802469135780246913578024691357802469135780";
    QTest::newRow("sum_data_2")
            << "bad number1"
            << "2"
            << "2";
    QTest::newRow("sum_data_3")
            << "1"
            << "bad number2"
            << "1";
    QTest::newRow("sum_data_4")
            << "bad number1"
            << "bad number2"
            << "";
    //Для упрощения работает только с положительными числами
    QTest::newRow("sum_data_5")
            << "-1" << "-551" << "";

    QTest::newRow("sum_data_6") << "10" << "" << "10";
}

void TestBigNumber::sum()
{
    QFETCH(QString, first);
    QFETCH(QString, second);
    QFETCH(QString, result);
    QCOMPARE(BigNumber(BigNumber(first) + BigNumber(second)).toString(), result);
}

QTEST_APPLESS_MAIN(TestBigNumber)

#include "tst_bignumber.moc"
