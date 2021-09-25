#ifndef _BASEDERIVE_
#define _BASEDERIVE_

class Base {
    public:
    Base() = default;

    int pub_val;

    protected:
    int pro_val;

    private:
    int pri_val;
};

class Derive: public Base {
    public:
    Derive(): Base() { }
};

class Derive2: public Derive {
    public:
    Derive2(): Derive() { }
};

#endif