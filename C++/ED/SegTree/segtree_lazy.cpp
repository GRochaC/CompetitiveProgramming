template <typename T> class SegTreeLazy{
  private:
    vector<T> st, lz;
    T elemNeutro;
    int n;
    T merge(const T & a, const T & b){ // #!
      return a + b; 
    }
    void prop(int l, int r, int no){ // #!
      st[no] += (r - l + 1)*lz[no]; 
      if(l != r){
        lz[2*no] += lz[no]; 
        lz[2*no + 1] += lz[no]; 
      }
      lz[no] = 0; 
    }
    void update(int gl, int gr, T x, int l, int r, int no){
      prop(l, r, no);
      if(l >= gl && r <= gr){
        lz[no] += x; // #!
        prop(l, r, no);
      } else if(l > gr || r < gl) return;
      else {
        int mid = (l + r) >> 1;
        update(gl, gr, x, l, mid, 2*no);
        update(gl, gr, x, mid + 1, r, 2*no + 1);
        st[no] = merge(st[2*no], st[2*no + 1]);
      }
    }
    T query(int gl, int gr, int l, int r, int no){
      prop(l, r, no);
      if(l >= gl && r <= gr) return st[no];
      else if(l > gr || r < gl) return elemNeutro;
      else {
        int mid = (l + r) >> 1;
        return merge(query(gl, gr, l, mid, 2*no), query(gl, gr, mid + 1, r, 2*no + 1));
      }
    }
  public:
    SegTreeLazy(int _n, T _elemNeutro){
      n = _n;
      elemNeutro = _elemNeutro;
      st.resize(4*n);
      lz.resize(4*n);
    }
    void update(int l, int r, T x){
      update(l, r, x, 0, n - 1, 1);
    }
    T query(int l, int r){
      return query(l, r, 0, n - 1, 1);
    }
};

