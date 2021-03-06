// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include <vector>

#include "Span.h"
#include "GameObjects.h"
#include "GameObjectsInherit.h"
#include "ExplicitVTbl.h"

// from https://youtu.be/gVGtNFg4ay0?list=PLHTh1InhhwT6bwIpRk0ZbCA0N2p1taxd6

using namespace std;

template <typename RefType>
__declspec(noinline) void setVehicleSpeedR(Span<RefType> _vehicles, float _wantedSpeed)
{
    for (auto & v : _vehicles)
    {
        float speed = v.getSpeed();
        v.accelerate(_wantedSpeed - speed);
    }
}

template <typename PtrType>
__declspec(noinline) void setVehicleSpeedP(Span<PtrType> _vehicles, float _wantedSpeed)
{
    for (auto & v : _vehicles)
    {
        float speed = v->getSpeed();
        v->accelerate(_wantedSpeed - speed);
    }
}

template <typename RefType, typename MotoT = Moto, typename CarT = Car>
void testRuntimePolymorphismR()
{
    MotoT m;
    CarT c;
    vector<RefType> vehicles;
    vehicles.emplace_back(m);
    vehicles.emplace_back(c);
    setVehicleSpeedR<RefType>(vehicles, 3.f);
}

template <typename PtrType, typename MotoT = Moto, typename CarT = Car>
void testRuntimePolymorphismP()
{
    MotoT m;
    CarT c;
    vector<PtrType> vehicles;
    vehicles.emplace_back(&m);
    vehicles.emplace_back(&c);
    setVehicleSpeedP<PtrType>(vehicles, 3.f);
}

int main()
{
    testRuntimePolymorphismP<inherit::IVehicle*, inherit::Moto, inherit::Car>();
    testRuntimePolymorphismR<explicitVTbl::VehicleRef>();
    return 0;
}

