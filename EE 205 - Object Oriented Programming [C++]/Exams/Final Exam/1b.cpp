class GroundV : public Vehicle {

    public:
        GroundV(float usage) : Vehicle(usage) {};

        float Drive(float mi);

};

class AirV : public Vehicle {

    public:
        AirV(float usage) : Vehicle(usage) {};

        float Fly(float mi);

};

class SeaV : public Vehicle {

    public:
        SeaV(float usage) : Vehicle(usage) {};

        float Sail(float mi);

};