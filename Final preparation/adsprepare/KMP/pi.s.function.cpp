/*
when suffix.len == prefix.len && 
suffix == prefix && suffix.len ! = totals.size ; 
*/

int pi (string s){
    int n = s.size() ; 
    for(int suffix_len = n-1 ; suffix_len >= 0 ; suffix_len --){
        string suffix = s.substr(n - suffix_len , suffix_len) ; 
        string prefix = s.substr(0 , suffix_len) ; 
        if(suffix == prefix){
            return suffix_len ;  
        }
    }
    return 0 ; 
}