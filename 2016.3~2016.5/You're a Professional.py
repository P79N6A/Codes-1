F,I,T=map(int,input().split())
a=[0]*F
for i in range(F):
    a[i]=input()
b=0
for i in range(I):
    sum=0
    for j in range(F):
        sum+=(a[j][i]=='Y')
    b+=(sum>=T)
print(b)
#kitten
