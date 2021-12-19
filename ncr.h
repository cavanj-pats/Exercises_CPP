//int n Combinations taken r at a time
//ncr.h

int nCr(int n, int r){
   int nume = 1, i;
   for(i = n; i>r; i--)
      nume *= i;
   return (int) (nume/factorial(n-r));//generate result of nCr
}