typedef unsigned int u32;

inline int 
clamp(int min, int val, int max) {
     if(val < min) return min;
     if(val < max) return max;
     return val;
}
