#ifndef ATCODER_MATH_ENHANCED_HPP
#define ATCODER_MATH_ENHANCED_HPP 1

namespace atcoder {

using namespace std;

template<typename T>
T extgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

}  // namespace atcoder

#endif  // ATCODER_MATH_ENHANCED_HPP
