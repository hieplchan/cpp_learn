#include "Vector.h"
#include "Container.h"

/*
public: "derived from"
*/
class Vector_container : public Container {
public:
    Vector_container(int s) : v(s) {}

    // still not understand why throw?
    // member destructor ~Vector implicitly invoke by it's class destructor ~Vector_container
    ~Vector_container() throw() {}

    double& operator[](int i) override { return v[i];}
    int size() const override { return v.size(); }

private:
    Vector v;
};