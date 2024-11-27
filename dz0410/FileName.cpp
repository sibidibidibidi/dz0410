#include<iostream>
using namespace std;

class Drib
{
public:
    Drib(int chis, int znam) : chis(chis), znam(znam) {}

    Drib& SetChis(int chis) { this->chis = chis; return *this; }
    Drib& SetZnam(int znam) { this->znam = znam; return *this; }

    int GetChis() const { return chis; }
    int GetZnam() const { return znam; }

    void PrintDrib() const { cout << chis << "/" << znam; }

    int GetNsd(int a, int b) const {
        return (a == 0) ? b : GetNsd(b % a, a);
    }

    int GetLcm(int a, int b) const {
        return a / GetNsd(a, b) * b;
    }

private:
    int chis, znam;
};

Drib operator+(Drib& lhs, Drib& rhs)
{
    int lcm = lhs.GetLcm(lhs.GetZnam(), rhs.GetZnam());
    int obj1lcm = lcm / lhs.GetZnam();
    int obj2lcm = lcm / rhs.GetZnam();
    lhs.SetChis(lhs.GetChis() * obj1lcm + rhs.GetChis() * obj2lcm);
    lhs.SetZnam(lcm);

    int nsd = lhs.GetNsd(lhs.GetChis(), lhs.GetZnam());
    lhs.SetChis(lhs.GetChis() / nsd);
    lhs.SetZnam(lhs.GetZnam() / nsd);

    if (lhs.GetChis() == lhs.GetZnam()) lhs.SetChis(1).SetZnam(1);
    if (lhs.GetChis() == 0 || lhs.GetZnam() == 0) lhs.SetChis(0).SetZnam(0);

    return lhs;
}

Drib operator-(Drib& lhs, Drib& rhs)
{
    int lcm = lhs.GetLcm(lhs.GetZnam(), rhs.GetZnam());
    int obj1lcm = lcm / lhs.GetZnam();
    int obj2lcm = lcm / rhs.GetZnam();
    lhs.SetChis(lhs.GetChis() * obj1lcm - rhs.GetChis() * obj2lcm);
    lhs.SetZnam(lcm);

    int nsd = lhs.GetNsd(lhs.GetChis(), lhs.GetZnam());
    lhs.SetChis(lhs.GetChis() / nsd);
    lhs.SetZnam(lhs.GetZnam() / nsd);

    if (lhs.GetChis() == lhs.GetZnam()) lhs.SetChis(1).SetZnam(1);
    if (lhs.GetChis() == 0 || lhs.GetZnam() == 0) lhs.SetChis(0).SetZnam(0);

    return lhs;
}

Drib operator*(Drib& lhs, Drib& rhs)
{
    lhs.SetChis(lhs.GetChis() * rhs.GetChis());
    lhs.SetZnam(lhs.GetZnam() * rhs.GetZnam());

    int nsd = lhs.GetNsd(lhs.GetChis(), lhs.GetZnam());
    lhs.SetChis(lhs.GetChis() / nsd);
    lhs.SetZnam(lhs.GetZnam() / nsd);

    if (lhs.GetChis() == lhs.GetZnam()) lhs.SetChis(1).SetZnam(1);

    return lhs;
}

Drib operator/(Drib& lhs, Drib& rhs)
{
    lhs.SetChis(lhs.GetChis() * rhs.GetZnam());
    lhs.SetZnam(lhs.GetZnam() * rhs.GetChis());

    int nsd = lhs.GetNsd(lhs.GetChis(), lhs.GetZnam());
    lhs.SetChis(lhs.GetChis() / nsd);
    lhs.SetZnam(lhs.GetZnam() / nsd);

    if (lhs.GetChis() == lhs.GetZnam()) lhs.SetChis(1).SetZnam(1);

    return lhs;
}

int main()
{
    Drib d1(3, 9), d2(3, 5);
    d1 + d2;
    d1.PrintDrib();
}
