#ifndef TEST_STACK_H
#define TEST_STACK_H

#include "stack.h"
#include <QtTest/QTest>
#include <QObject>

class test_stack : public QObject
{
    Q_OBJECT
public:
    explicit test_stack(QObject *parent = 0);
private slots:
    void tests();
};

#endif // TEST_STACK_H
