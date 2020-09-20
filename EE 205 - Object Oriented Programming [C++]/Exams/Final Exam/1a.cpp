class Vehicle {

    protected:
        float fuelUsage;
        float load;
        float fuelMeter;
        float odoMeter;

    public:
        Vehicle(float usage);

        float getLoad();
        void setLoad(float l);
        float getFuelMeter();
        void setFuelMeter(float fm);
        void setOdometer(float o);

};

Vehicle::Vehicle(float usage) {
    this->fuelUsage = usage;
    this->load = 0f;
    this->fuelMeter = 0f;
    this->odoMeter = 0f;
}

float Vehicle::getLoad() {
    return load;
}

void Vehicle::setLoad(float l) {
    this->load = l;
}

float Vehicle::getFuelMeter() {
    return fuelMeter;
}

void Vehicle::setFuelMeter(float fm) {
    this->fuelMeter = fm;
}

void Vehicle::setOdometer(float o) {
    this->odoMeter = o;
}