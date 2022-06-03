#pragma once

template <typename T>
T* resizeArray(T* arr, int oldSize, int newSize)
{
    if(oldSize == newSize) return arr;

    T* new_arr = new T[newSize];
    for (int i = 0; i < oldSize; i++)
    {
        new_arr[i] = arr[i];
    }
    
    delete[] arr;
    return new_arr;
}
