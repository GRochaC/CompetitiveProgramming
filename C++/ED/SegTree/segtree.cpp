template <typename T> class SegTree{
  private:
    vector<T> st;
    T elemNeutro;
    int n;
    T merge(const T & a, const T & b){
      return a + b; // #!
    }
    void update(int i, T x, int l, int r, int no){
      if(l == r) st[no] += x;
      else {
        int mid = (l + r) >> 1;
        if(i <= mid) update(i, x, l, mid, 2*no);
        else update(i, x, mid + 1, r, 2*no + 1);
        st[no] = merge(st[2*no], st[2*no + 1]);
      }
    }
    T query(int gl, int gr, int l, int r, int no){
      if(l >= gl && r <= gr) return st[no];
      else if(l > gr || r < gl) return elemNeutro;
      else {
        int mid = (l + r) >> 1;
        return merge(query(gl, gr, l, mid, 2*no), query(gl, gr, mid + 1, r, 2*no + 1));
      }
    }
  public:
    SegTree(int _n, T _elemNeutro){
      n = _n;
      elemNeutro = _elemNeutro;
      st.resize(4*n);
    }
    void update(int i, T x){
      update(i, x, 0, n - 1, 1);
    }
    T query(int l, int r){
      return query(l, r, 0, n - 1, 1);
    }
};
