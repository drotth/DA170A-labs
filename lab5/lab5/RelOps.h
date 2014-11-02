//template <typename T, typename R> bool operator==(const T& lhs, const R& rhs) { return (P == rhs.P  && Q == rhs.Q); }
template <typename T, typename R> bool operator!=(const T& lhs, const R& rhs) { return !(lhs == rhs); }
template <typename T, typename R> bool operator>(const T& lhs, const R& rhs) { return (rhs<lhs); }
template <typename T, typename R> bool operator>=(const T& lhs, const R& rhs) { return !(lhs<rhs); }
template <typename T, typename R> bool operator<=(const T& lhs, const R& rhs) { return !(rhs<lhs); }