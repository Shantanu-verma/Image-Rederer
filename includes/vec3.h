#ifndef VEC
#define VEC
template <class T>
class vec3 {
public:
  	T x, y, z;

  	vec3() : x{0}, y{0}, z{0} {}
  	vec3(const T &x, const T &y, const T &z) : x{x}, y{y}, z{z} {}
  	explicit vec3(const vec3 &other) : vec3(other.x, other.y, other.z) {}
  	explicit vec3(const vec3 &&other) noexcept : vec3(other.x, other.y, other.z) {}

  	const T length() const { 
  		return sqrt(x * x + y * y + z * z); 
  	}
  	const vec3<T> &normalize() {
    	T len = length();
    	if (len > 0) {
      		T inv = 1 / len;
      		x *= inv;
      		y *= inv;
      		z *= inv;
    	}
    return *this;
  	}
  	vec3<T> operator+(const vec3<T> &v) const {
    	return vec3<T>(x + v.x, y + v.y, z + v.z);
  	}
  	vec3<T> operator-(const vec3<T> &v) const {
    	return vec3<T>(x - v.x, y - v.y, z - v.z);
  	}
  	vec3<T> operator-() { 
  		return vec3<T>(-x, -y, -z); 
  	}
  	vec3<T> operator*(const T &n) const { 
  		return vec3<T>(n * x, n * y, n * z); 
  	}
  	vec3<T> operator/(const T &n) const {
    	if (n) {
     	 	T i = 1 / n;
      		return vec3<T>(x * i, y * i, z * i);
    	} else
      		return *this;
  	}

  	friend std::ostream &operator<<(std::ostream &os, const vec3<T> &rhs) {
    	os << "[ " << rhs.x << ' ' << rhs.y << ' ' << rhs.z << " ]";
    	return os;
  	}
  	friend std::istream &operator>>(std::istream &is, vec3<T> &rhs) {
    	is >> rhs.x >> rhs.y >> rhs.z;
    	return is;
  	}
  	friend const T dot(const vec3<T> &v1, const vec3<T> &v2) {
    	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
  	}
  	friend vec3<T> cross(const vec3<T> &a, const vec3<T> &b) {
    	return vec3<T>(a.y * b.z - a.z * b.y,
    					 a.z * b.x - a.x * b.z,
                   			a.x * b.y - a.y * b.x);
  	}
  	friend const T dot(const vec3<T> &v) { 
  		return dot(v, v); 
  	}
  	vec3<T> unit() const { 
  		return *this / dot(*this); 
  	}
  	bool operator==(const vec3<T> &v) const {
    	return (x == v.x && y == v.y && z == v.z);
  	}
  	bool operator!=(const vec3<T> &v) const {
  		 return !(*this == v); 
  	}
  	vec3<T> &operator=(const vec3<T> &v) = default;
  	vec3<T> &operator=(const vec3<T> &&v) noexcept {
    	*this = v;
    	return *this;
  	}
};
typedef vec3<float> vec3f;
#endif
