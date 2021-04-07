string toBinary(int n)
{
    string r="";
    while (n > 0){
        r+=((n%2)+'0');
        n/=2;
    }
    reverse(r.begin(),r.end());
    return r;
}
