struct Matrix {
    vector<vl> m;
    int r, c;

    Matrix(vector<vl> mat) {
        m = mat;
        r = mat.size();
        c = mat[0].size();
    }

    Matrix(int row, int col, bool ident=false) {
        r = row; c = col;
        m = vector<vl>(r, vl(c, 0));
        if(ident) {
            assert(r == c);
            for(int i = 0; i < min(r, c); i++) {
                m[i][i] = 1;
            }
        }
    }

    Matrix operator+(const Matrix &o) const {
        assert(r == o.r and c == o.c);

        vector<vl> res(r, vl(c, 0));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i][j] = (m[i][j] + o.m[i][j]) % MOD;
            }
        }

        return Matrix(res);
    }

    Matrix operator-(const Matrix &o) const {
        assert(r == o.r and c == o.c);

        vector<vl> res(r, vl(c, 0));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i][j] = (m[i][j] - o.m[i][j] + MOD) % MOD;
            }
        }

        return Matrix(res);
    }

    Matrix operator*(const int k) const {
        vector<vl> res(r, vl(c, 0));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i][j] = (k * m[i][j]) % MOD;
            }
        }

        return Matrix(res);
    }

    Matrix operator*(const Matrix &o) const {
        assert(c == o.r); // garantir que da pra multiplicar
        vector<vl> res(r, vl(o.c, 0));

        for(int i = 0; i < r; i++) {
            for(int k = 0; k < c; k++) {
                for(int j = 0; j < o.c; j++) {
                    res[i][j] = (res[i][j] + m[i][k]*o.m[k][j]) % MOD;
                }
            }
        }

        return Matrix(res);
    }

    Matrix transpose() const {
        vector<vl> res(c, vl(r,0));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[j][i] = m[i][j];
            }
        }

        return Matrix(res);
    }
};

Matrix fexp(Matrix b, int e, int n) {
    if(e == 0) return Matrix(n, n, true); // identidade
    Matrix res = fexp(b, e/2, n);
    res = (res * res);
    if(e%2) res = (res * b);

    return res;
}
