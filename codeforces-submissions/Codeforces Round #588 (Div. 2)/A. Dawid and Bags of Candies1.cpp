l=list(map(int,input().split()))
l.sort()
if sum(l)-max(l) == max(l) :
    print("YES")
elif l[0]+l[3]==l[2]+l[1]:
    print("YES")
else:
    print("NO")
