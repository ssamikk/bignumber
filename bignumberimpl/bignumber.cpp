#include "bignumber.h"
#include <QDebug>

BigNumber::BigNumber(const QString &value)
{
    valid = false;
    QString nValue = value.trimmed();
    if(!nValue.isEmpty()){
        int len = nValue.length();
        valid = true;
        reverseNumber.reserve(nValue.length());
        for(int i=0;i<len;i++){
            if(value[i].isDigit()){
                reverseNumber.append(int(nValue[len - i - 1].unicode()) - 48);
            }else{
                valid = false;
                reverseNumber.clear();
                break;
            }
        }
        trimmed();
    }
}

BigNumber::BigNumber(const BigNumber &other)
{
    setReverseNumber(other.getReverseNumber());
}

BigNumber::~BigNumber()
{

}

BigNumber BigNumber::operator+(const BigNumber &other) const
{
    BigNumber sum;
    if(other.isValid() && isValid()){
        QVector<int> otherNumber = other.getReverseNumber();
        int length;
        if (reverseNumber.length() > otherNumber.length()){
            length = reverseNumber.length() + 1;
            otherNumber+=QVector<int>(length-otherNumber.size(), 0);
        }else{
            length = otherNumber.length() + 1;
            otherNumber.append(0);
        }
        for (int i = 0; i < length; i++)
        {
            if(reverseNumber.length()>i){
                otherNumber[i] += reverseNumber[i]; // суммируем последние разряды чисел
                otherNumber[i + 1] += (otherNumber[i] / 10); // если есть разряд для переноса, переносим его в следующий разряд
                otherNumber[i] %= 10; // если есть разряд для переноса он отсекается
            }else{
                break;
            }
        }
        sum.setReverseNumber(otherNumber);
    }else if (other.isValid()) {
        sum.setReverseNumber(other.getReverseNumber());
    }else{
        sum.setReverseNumber(getReverseNumber());
    }
    return sum;
}

QVector<int> BigNumber::getReverseNumber() const
{
    return reverseNumber;
}

void BigNumber::setReverseNumber(const QVector<int> &value)
{
    reverseNumber = value;
    valid = !reverseNumber.isEmpty();
    trimmed();
}

QString BigNumber::toString() const
{
    QString value;
    if(valid){
        QVectorIterator<int> i(reverseNumber);
        i.toBack();
        while(i.hasPrevious()){
            value.append(QChar(i.previous()+48));
        }
    }
    return value;
}

bool BigNumber::isValid() const
{
    return valid;
}

void BigNumber::trimmed()
{
    if(valid){
        while(reverseNumber.endsWith(0)){
            reverseNumber.removeAt(reverseNumber.length()-1);
        }
        valid = !reverseNumber.isEmpty();
    }
}

