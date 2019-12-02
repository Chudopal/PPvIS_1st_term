#include "test_stack.h"


test_stack::test_stack(QObject *parent) :
    QObject(parent)
{}

void test_stack::tests() {
    stack a;
    QCOMPARE(a.theFirstEl(1), a.getValue() = 1);
    QCOMPARE(a.max(-1,  1), 1);
    QCOMPARE(a.max(4,   8), 8);
    QCOMPARE(a.max(0,   0), 0);
    QCOMPARE(a.max(1,   1), 1);
    QCOMPARE(a.max(-10,-5), -5);
}
