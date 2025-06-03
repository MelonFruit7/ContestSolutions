#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-4;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

template<class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T> struct Point {
    typedef Point P;
    T x,y;
    explicit Point(T x = 0, T y = 0): x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x,y) < tie(p.x,p.y);
    }
    bool operator==(P p) const {
        return tie(x,y) == tie(p.x,p.y);
    }
    bool operator!=(P p) const {
        return tie(x,y) != tie(p.x,p.y);
    }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x+y*p.y;}
    T cross(P p) const { return x*p.y-y*p.x; }
    T cross(P a, P b) const {
        return (a-*this).cross(b-*this);
    }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
    return P(x * cos(a) - y * sin(a),
             x * sin(a) + y * cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")"; }
};
typedef Point<double> P;

pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    if (d == 0)return {-(s1.cross(e1, s2) == 0), P(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}
vector<P> circleLine(P c, double r, P a, P b) {
  P ab = b - a, p = a + ab*(c - a).dot(ab) / ab.dist2();
  double s = a.cross(b, c), h2 = r * r - s * s / ab.dist2();
  if (h2 < 0) return {};
  if (h2 == 0) return {p};
  P h = ab.unit() * sqrt(h2);
  return {p - h, p + h}; 
}
template<class P> vector<P> segInter(P a, P b, P c, P d) {
  auto oa = c.cross(d, a), ob = c.cross(d, b),
       oc = a.cross(b, c), od = a.cross(b, d);
  // Checks if intersection is single non-endpoint point.
  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    return {(a * ob - b * oa) / (ob - oa)};
  set<P> s;
  if (onSegment(c, d, a)) s.insert(a);
  if (onSegment(c, d, b)) s.insert(b);
  if (onSegment(a, b, c)) s.insert(c);
  if (onSegment(a, b, d)) s.insert(d);
  return {all(s)};
}
double segDist(P& s, P& e, P& p) {
  if (s == e) return (p - s).dist();
  auto d = (e - s).dist2(),
       t = min(d, max(.0, (p - s).dot(e - s)));
  return ((p - s) * d - (e - s) * t).dist() / d;
}

bool onSegment(P s, P e, P p) {
  return (segDist(s,e,p)<=EPS);
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, r; cin >> n >> m >> r;
    vector<P> candles;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        candles.push_back(P(x, y));
    }
    vector<pair<P, P>> lines;

    int cake_slices = 1;
    for (int i = 0; i < m; i++) {
        double a, b, c; cin >> a >> b >> c;
        P p1, p2;
        if (b == 0) {
            p1 = P(-c/a, 0);
            p2 = P((-c-b)/a, 1);
        } else {
            p1 = P(0, -c/b);
            p2 = P(1, (-c-a)/b);
        }

        int additions = 1;
        for (int j = 0; j < lines.size(); j++) {
            auto [flag, loc] = lineInter(p1, p2, lines[j].first, lines[j].second);
            if (flag == 0) continue;
            if (loc.x*loc.x + loc.y*loc.y <= r*r) additions++;
        }
        cake_slices += additions;
        lines.push_back({p1, p2});
    }


    if (cake_slices != n) {
        cout << "no" << endl;
        return 0;
    }
    for (int i = 0; i < candles.size(); i++) {
        P p1 = candles[i];
        for (int j = i+1; j < candles.size(); j++) {
            P p2 = candles[j];

            bool failed = true;
            for (int k = 0; k < lines.size(); k++) {
                vector<P> cut_seg = circleLine(P(0, 0), r, lines[k].first, lines[k].second);
                vector<P> intersection = segInter(p1, p2, cut_seg[0], cut_seg[1]);
                if (intersection.size() > 0) {
                    failed = false;
                    break;
                }
            }
            if (failed) {
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;
    return 0;
}