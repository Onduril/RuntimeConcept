#pragma once

struct Car
{
    void accelerate(float a)
    {
        m_speed += a;
    }

    float getSpeed() const
    {
        return m_speed;
    }

    float m_speed = 0;
};

struct Moto
{
    void accelerate(float a)
    {
        m_speed += a;
    }

    float getSpeed() const
    {
        return m_speed;
    }

    float m_speed = 0;
};

