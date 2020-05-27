#include <iostream>

class safe_l {

private:
    long long val;

public:
    safe_l(long long l) {
        val = l;
    }

    safe_l(safe_l const &l) {
        val = l.val;
    }

    safe_l() {
        val = 0;
    }

    long long get_l() {
        return val;
    }

    void operator=(safe_l l1) {
        val = l1.val;
    }

    safe_l operator++() {
        return safe_l(++val);
    }

    safe_l operator++(int) {
        return safe_l(val++);
    }

    safe_l operator--() {
        return safe_l(--val);
    }

    safe_l operator--(int) {
        return safe_l(val--);
    }

    void operator+=(safe_l long1) {
        val += long1.val;
    }

    void operator-=(safe_l long1) {
        val -= long1.val;
    }

    void operator*=(safe_l long1) {
        val *= long1.val;
    }

    void operator/=(safe_l long1) {
        val /= long1.val;
    }

    void operator%=(safe_l long1) {
        val %= long1.val;
    }

    ~safe_l() = default;
};

safe_l operator+(safe_l l1, safe_l l2) {
    safe_l current = l1;
    current += l2;
    return current;
}

safe_l operator-(safe_l l1, safe_l l2) {
    safe_l current = l1;
    current -= l2;
    return current;
}

safe_l operator*(safe_l l1, safe_l l2) {
    safe_l current = l1;
    current *= l2;
    return current;
}

safe_l operator/(safe_l l1, safe_l l2) {
    safe_l current = l1;
    current /= l2;
    return current;
}

safe_l operator%(safe_l &l1, safe_l &l2) {
    safe_l current = l1;
    current %= l2;
    return current;
}

bool operator==(safe_l l1, safe_l l2) {
    return l1.get_l() == l2.get_l();
}

bool operator<(safe_l l1, safe_l l2) {
    return l1.get_l() < l2.get_l();
}

bool operator>(safe_l l1, safe_l l2) {
    return l1.get_l() > l2.get_l();
}

bool operator<=(safe_l l1, safe_l l2) {
    return l1.get_l() <= l2.get_l();
}

bool operator>=(safe_l l1, safe_l l2) {
    return l1.get_l() >= l2.get_l();
}


std::ostream &operator<<(std::ostream &s, safe_l l1) {
    s << l1.get_l();
    return s;
}

std::istream &operator>>(std::istream &s, safe_l &l1) {
    long long num;
    s >> num;
    l1 = num;
    return s; 
}


int main() {
    safe_l l_1 = 10;
    safe_l l_2 = 5;
    std:: cout << l_1 + l_2;
    return 0;
}

