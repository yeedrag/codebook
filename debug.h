// template from https://github.com/sanathkumarx/Competitive-Coding/blob/master/CodeForces/practice/algo/debug.h
#undef _GLIBCXX_DEBUG
 
#include <bits/stdc++.h>
 
using namespace std;
 
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A>
string to_string(queue<A> q) {
    vector<A> v;
    while(q.size()) {
        v.push_back(q.front());
        q.pop();
    }
    return to_string(v);
}

template <typename A>
string to_string(stack<A> stk) {
    vector<A> v;
    while(stk.size()) {
        v.push_back(stk.top());
        stk.pop();
    }
    return to_string(v);
}

template <typename A>
string to_string(deque<A> deq) {
    vector<A> v;
    while(deq.size()) {
        v.push_back(deq.front());
        deq.pop_front();
    }
    return to_string(v);
}

template <typename A>
string to_string(priority_queue<A> pq) {
    vector<A> v;
    while(pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }
    return to_string(v);
}

template <typename A>
string to_string(A arr[]) {
    vector<A> v;
    for(int i = 0; i < sizeof(arr); i++) {
        v.pb(arr[i]);
    }
    return to_string(v);
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)