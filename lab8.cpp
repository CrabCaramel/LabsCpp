#include "HeapInt.h"

HeapInt::HeapInt(const HeapInt& other)
    : heapValue(new int{ *other.heapValue })
{
}

HeapInt::HeapInt(HeapInt&& other)
    : heapValue(other.heapValue)
{
    other.heapValue = nullptr;
}

void HeapInt::operator=(const HeapInt& other)
{
    *heapValue = *other.heapValue;
}

void HeapInt::operator=(HeapInt&& other)
{
    delete heapValue;
    heapValue = other.heapValue;
    other.heapValue = nullptr;
}
