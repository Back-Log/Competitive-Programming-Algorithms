int toDecimal(string s)
{
int value = 0;
int indexCounter = 0;
for(int i=s.length()-1;i>=0;i--){

    if(s[i]=='1'){
        value += pow(2, indexCounter);
    }
    indexCounter++;
}
return value;

}
