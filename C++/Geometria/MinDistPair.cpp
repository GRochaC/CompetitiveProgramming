ll MinDistPair(vector<point> &vet){
    int n = vet.size();
    sort(vet.begin(), vet.end());
    set<point> s;

    ll best_dist = LLINF;
    int j = 0;
    for (int i=0;i<n;i++) {
        int d = ceil(sqrt(best_dist));
        while (j<n and vet[i].x-vet[j].x >= best_dist){
            s.erase({vet[j].y, vet[j].x});
            j++;
        }

        auto it1 = s.lower_bound({vet[i].y - d, vet[i].x});
        auto it2 = s.upper_bound({vet[i].y + d, vet[i].x});
        
        for (auto it=it1; it!=it2; it++){
            ll dx = vet[i].x - it->y;
            ll dy = vet[i].y - it->x;
            if(best_dist > dx*dx + dy*dy){
                best_dist = dx*dx + dy*dy;
            }   
        }

        s.insert({vet[i].y, vet[i].x}); 
    }
    return best_dist;
}