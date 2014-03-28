class Primes
{
public void printPrimes(int n) {  
   if (n < 2)  return; // A prime number must be >= 2.
   boolean[] flags = new boolean[n+1]; // by default initialized to false  
   
   int rootN = (int)Math.sqrt(n);  
   for (int i=2; i<=rootN; ++i) {  // [1]
     // flags[i]==true means it has been marked before and thus all its multiples can be skipped
     if (!flags[i]) {  
       // Note: if we get here, i itself is a prime number

       // mark its multiples
       for (int j=i*i; j<=n; j+=i) {  // [2]
         flags[j] = true;  
       }  
     }  
   }  
   
   // print all primes  
   System.out.println("Prime numbers less than " + n + ":");  
   for (int i=2; i<=n; ++i) {  
     if (!flags[i]) System.out.print(i + ", ");  
   }  
 }  
 
 public boolean isPrime(int n) {  
   if (n < 2) return false; // prime must >=2  
   if (n == 2) return true;  
   if ((n & 1) == 0) return false; // prime must not be even  
   
   int rootN = (int)Math.sqrt(n);  
   for (int i=2; i<=rootN; ++i) {  
     if (n % i == 0) return false;  
   }  
   return true;  
 }  
 
 public static void printPrimeFactors(int n) {  
   if (n < 2) return ; // prime must >=2  
     
   System.out.println("Prime factors of " + n + ":");  
   
   while ((n & 1) == 0) {  
     System.out.print(2 + " ");  
     n /= 2;  
   }  
   
   int rootN = (int)Math.sqrt(n);  
   for (int i=3; i<=rootN; ++i) {  
     while (n % i == 0) {  
       System.out.print(i + " ");  
       n /= i;  
     }  
   }  
   
   if (n > 2) { // there is at most one prime factor > sqrt(n)  
     System.out.print(n);  
   }  
 }  
 
 }
