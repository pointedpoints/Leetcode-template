const int maxN = 4000000;
bool is_prime[maxN+1];
vector<int> prime;

int init = [](){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    for(int i=2; i<=maxN; i++){
        if(is_prime[i])
            prime.push_back(i);
        
        for(int j = 0; j<prime.size() && prime[j]*i <=maxN; j++){
            is_prime[ prime[j]*i ] = false;
            if(i % prime[j]==0)
                break;
        }
    }
    return 0;
}();
