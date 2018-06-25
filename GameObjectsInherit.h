#pragma once

namespace inherit
{

    struct IVehicle
    {
        virtual void accelerate(float a) = 0;

        virtual float getSpeed() const = 0;
    };

    struct Car : IVehicle
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

    struct Moto : IVehicle
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

}