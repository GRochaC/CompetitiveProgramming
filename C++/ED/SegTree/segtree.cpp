template <typename T> struct SegTree{
	vector<T> st;
	int n;
	T zero;

	SegTree(int n, T zero):  n(n),  zero(zero) {
		st.resize(4*n);
	}

	T merge(const T & a, const T & b){
		return a + b;
	}

	void update(int i, int x, int l, int r, int no){
		if(l == r){
			st[no] = x;
		} else {
			int mid = (l + r) >> 1;
			if(i <= mid) update(i, x, l, mid, 2*no);
			else update(i, x, mid + 1, r, 2*no + 1);
			st[no] = merge(st[2*no], st[2*no + 1]);
		}
	}


	T query(int gl, int gr, int l, int r, int no){
		if(l >= gl && r <= gr) return st[no];
		else if(l > gr || r < gl) return zero;
		else {
			int mid = (l + r) >> 1;
			return merge(query(gl, gr, l, mid, 2*no), query(gl, gr, mid + 1, 2*no + 1));
		}
	}


	void update(int i, int x){
		update(i, x, 0, n - 1, 1);
	}

	T query(int l, int r){
		return query(l, r, 0, n - 1, 1);
	}

};
