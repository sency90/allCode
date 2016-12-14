//koosaga made
void fft(vector<base> &v, bool inv){
    vector<base> w(v.size()), aux(v.size());
    for(int i=0; i<v.size(); i++){
        int k = i&-i;
        if(i == k){
            double ang = 2 * M_PI * i / v.size();
            w[i] = base(cos(ang), sin(ang));
        }
        else w[i] = w[i-k] * w[k];
    }
    for(int i=2; i<=v.size(); i<<=1){
        int bsz = v.size() / i;
        for(int j=0; j<bsz; j++){
            for(int k=0; k<i; k++){
                aux[k] = v[bsz * k + j];
            }
            for(int k=0; k<i/2; k++){
                base a = aux[2*k], b = aux[2*k+1] * (inv ? conj(w[bsz * k]) : w[bsz * k]);
                v[bsz * k + j] = a + b;
                v[bsz * k + j + v.size()/2] = a - b;
            }
        }
    }
    if(inv){
        for(int i=0; i<v.size(); i++){
            v[i] /= v.size();
        }
    }
}
