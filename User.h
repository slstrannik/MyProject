#include <QString>

#pragma once


class User
{
private:
    long id;
    QString name;
    QString old;
public:
    User();
    inline QString getOld() const { return old; };
    inline void setOld(const QString &value){ old = value; };
    inline QString getName() const { return name; };
    inline void setName(const QString &value) { name = value; };
    inline long getId() const { return id; };
    inline void setId(long value) { id = value; };
};

