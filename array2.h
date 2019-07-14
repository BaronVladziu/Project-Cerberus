#ifndef ARRAY2_H
#define ARRAY2_H

#include "vector2.h"


template<typename T>
class Array2
{
private:
    const Vector2<int> _SIZE;

    T ** _array;

private:
    void buildArray() {
        _array = new T*[_SIZE.y];
        for (int i = 0; i < _SIZE.y; i++)
        {
            _array[i] = new T[_SIZE.x];
        }
    }

public:
    Array2(const Vector2<int> & size)
        : _SIZE(size)
    {
        buildArray();
    }
    Array2(int sizeX, int sizeY)
        : _SIZE(sizeX, sizeY)
    {
        buildArray();
    }
    const Vector2<int> & getSize() const {
        return _SIZE;
    }
    T & get(const Vector2<int> & position) const {
        assert(position.x >= 0);
        assert(position.x < _SIZE.x);
        assert(position.y >= 0);
        assert(position.y < _SIZE.y);
        return _array[position.y][position.x];
    }
    T & get(int x, int y) const {
        assert(x >= 0);
        assert(x < _SIZE.x);
        assert(y >= 0);
        assert(y < _SIZE.y);
        return _array[y][x];
    }
    ~Array2() {
        for (int i = 0; i < _SIZE.y; i++)
        {
            delete[] _array[i];
        }
        delete[] _array;
    }
};

#endif // ARRAY2_H
