#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <QString>
#include <QVector>

class BigNumber
{
public:
    BigNumber(const QString &value = QString());
    BigNumber(const BigNumber &other);
    virtual ~BigNumber();
    BigNumber operator+(const BigNumber &other) const;
    QVector<int> getReverseNumber() const;
    void setReverseNumber(const QVector<int> &value);
    QString toString() const;
    bool isValid() const;
private:
    void trimmed();

    QVector<int> reverseNumber;
    bool valid;
};

#endif // BIGNUMBER_H
