#pragma once

namespace explicitVTbl
{

    template <typename T>
    inline void accelerate(T & o, float a)
    {
        return o.accelerate(a);
    }

    template <typename T>
    inline float getSpeed(const T & o)
    {
        return o.getSpeed();
    }

    struct VTable
    {
        void(*accelerate)(void* _this, float a);
        float(*getSpeed)(const void* _this);
    };

    template <typename T>
    static inline const VTable vtableFor =
    {
        [](void* _this, float a)
        {
            accelerate(*static_cast<T*>(_this), a);
        },
        [](const void* _this)
        {
            return getSpeed(*static_cast<const T*>(_this));
        }
    };

    struct VehicleRef
    {
        VehicleRef() = delete;

        template <typename T>
        VehicleRef(T & t)
            : m_obj(&t)
            , m_vtable(&vtableFor<T>)
        {
        }

        void accelerate(float a)
        {
            m_vtable->accelerate(m_obj, a);
        }

        float getSpeed() const
        {
            return m_vtable->getSpeed(m_obj);
        }

    private:
        void * m_obj;
        const VTable * m_vtable;
    };

}