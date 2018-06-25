#pragma once
#include <utility>

template <typename T>
struct Span
{
public:
    Span(T * p, size_t size)
        : m_p(p)
        , m_size(size)
    {}

    template <typename ContiguousIterable>
    Span(ContiguousIterable & v)
        : Span(v.data(), v.size())
    {
    }

    template <std::size_t N>
    Span(T(&a)[N])
        : Span(a, N)
    {}

    std::size_t size()
    {
        return m_size;
    }

    T * begin() const
    {
        return m_p;
    }

    T * end() const
    {
        return m_p + m_size;
    }

private:
    T * m_p;
    std::size_t m_size;
};





