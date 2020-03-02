### https://www.hackerearth.com/problem/algorithm/rectange-to-squares/

m,n = map(int,input().split())

a = max(m,n)
b = min(m,n)
c = a - b

while(c > 1):
    a = max(b,c)
    b = min(b,c)
    c = a - b
    
    if(a%2 == 0 and b%2 == 0):
        c=0
    
if(c == 0):
    print('Yes')
else:
    print('No')
