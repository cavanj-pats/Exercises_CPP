//
//
bool isPrime(int num){
    int countDivs=0;
    for(int i=1; i<= num; i++){
        if(num % i == 0)
        countDivs++;
    }
    if(countDivs==2)
        return true;
    else
        return false;
}