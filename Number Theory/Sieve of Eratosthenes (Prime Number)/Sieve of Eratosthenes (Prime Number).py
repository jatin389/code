## https://www.hackerearth.com/practice/notes/number-theory-1/

def SieveofEratosthenes(n):
    for i in range(2,n+1):
        if(prime[i]==0):
            prime[i]=1
            tmp=i*2
            while(tmp<=n):
                prime[tmp]=-1
                tmp+=i

def countNoOfPrimes(n):
    count=0
    for i in range(1,n+1):
        if(prime[i]==1):
            count+=1
        noOfPrimes[i]=count

prime=[0 for i in range(101)]
noOfPrimes=[0 for i in range(101)]
SieveofEratosthenes(100)
countNoOfPrimes(100)

for i in range(2,101):
	print(i,prime[i],noOfPrimes[i])
