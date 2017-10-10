#ifndef FREIGHTCAR_H
#define FREIGHTCAR_H

#include "Car.h"

class FreightCar : public Car {
protected:
    double _capacity = 0; // Tons for open and cubic meters for covered
public:
    FreightCar() {}
    virtual ~FreightCar() {}

    // -------- GETTERS --------
    virtual double getCapacity() const { return _capacity; } // Identical implementation for covered and open

    // -------- SETTERS --------
    virtual void setCapacity(double capacity) { _capacity = capacity; }
};

#endif // !FREIGHTCAR_H
