#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 1001;

struct Point{
  int x,y;
  void read(){
    cin>>x>>y;
  }
  Point operator +(const Point& b) const {return Point{x+b.x, y+b.y};}
  Point operator -(const Point& b) const {return Point{x-b.x, y-b.y};}
  ll operator *(const Point& b)
}

