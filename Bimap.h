//==============================================================================
// Name        : Bimap.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (18/03/2022)
// Description : Header file of the bidirectional map template
//==============================================================================

#ifndef BIMAP_H
#define BIMAP_H

#include <map>
#include <string>
#include <utility>
#include <vector>

template <typename T1, typename T2> class Bimap
{
  public:
    Bimap() = default;
    virtual ~Bimap() = default;
    Bimap(const Bimap& other) = default;
    Bimap(Bimap&& other) noexcept = default;
    Bimap& operator=(const Bimap& other) = default;
    Bimap& operator=(Bimap&& other) noexcept = default;

    explicit Bimap(const std::map<T1, T2>& map)
    {
        add(map);
    }
    explicit Bimap(const std::map<T2, T1>& map)
    {
        add(map);
    }
    Bimap& operator=(const std::map<T1, T2>& map)
    {
        clear();
        add(map);
    }
    Bimap& operator=(const std::map<T2, T1>& map)
    {
        clear();
        add(map);
    }

    bool has(const T1& left) const
    {
        return _left.count(left);
    }
    bool has(const T2& right) const
    {
        return _right.count(right);
    }
    const T2& at(const T1& left) const
    {
        return _left.at(left);
    }
    const T1& at(const T2& right) const
    {
        return _right.at(right);
    }
    const std::map<T1, T2>& left() const
    {
        return _left;
    }
    const std::map<T2, T1>& right() const
    {
        return _right;
    }

    std::vector<T2> items(const std::vector<T1>& leftItems) const
    {
        std::vector<T2> rightItems;
        rightItems.reserve(leftItems.size());
        for (const T1& leftItem : leftItems)
        {
            rightItems.emplace_back(has(leftItem) ? at(leftItem) : T2());
        }
        return rightItems;
    }
    std::vector<T1> items(const std::vector<T2>& rightItems) const
    {
        std::vector<T1> leftItems;
        leftItems.reserve(rightItems.size());
        for (const T2& rightItem : rightItems)
        {
            leftItems.emplace_back(has(rightItem) ? at(rightItem) : T1());
        }
        return leftItems;
    }

    void add(const T1& left, const T2& right)
    {
        _left[left] = right;
        _right[right] = left;
    }
    void add(const T2& right, const T1& left)
    {
        _right[right] = left;
        _left[left] = right;
    }
    void add(const std::pair<T1, T2>& item)
    {
        add(item.first, item.second);
    }
    void add(const std::pair<T2, T1>& item)
    {
        add(item.first, item.second);
    }
    void add(const std::map<T1, T2>& map)
    {
        for (const std::pair<T1, T2>& item : map)
        {
            add(item);
        }
    }
    void add(const std::map<T2, T1>& map)
    {
        for (const std::pair<T2, T1>& item : map)
        {
            add(item);
        }
    }

    void clear()
    {
        _left.clear();
        _right.clear();
    }

  private:
    std::map<T1, T2> _left;
    std::map<T2, T1> _right;
};

#endif /* BIMAP_H */
