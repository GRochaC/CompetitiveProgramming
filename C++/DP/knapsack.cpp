// Caso base, como i == n
dp[0][0] = 0;

// Itera por todos os estados 
for(int i = 1; i <= n; ++i)
    for(int P = 0; P <= w; ++P){
        int &temp = dp[i][P];
        // Primeira possibilidade, não pega i
        temp = dp[i - 1][P];

        // Segunda possibilidade, se puder, pega o item 
        if(P - p[i] >= 0)
            temp = max(temp, dp[i - 1][P - p[i]] + v[i]);

        ans = max(ans, temp);
    }