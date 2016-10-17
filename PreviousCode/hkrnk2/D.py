import random

n = int(input())
inp = map(int,input().split())

maxvalue = max(inp)

Next = [0]*(maxvalue+3)
Index = [0]*(maxvalue+3)


cnt = 0

for i in range(2,maxvalue+1):
	if Next[i]==0:
		for j in range(i , maxvalue+1 , i):
			Next[j] = j/i 
			Index[j] = cnt;
			pass
		cnt += 1
		pass
	pass

max_h = pow(2,60)
base = [0]*cnt
for i in range(cnt):
	base[i] = random.randrange(0,max_h)
	pass


from collections import defaultdict


_map = defaultdict(int)
ans = 0

hashvalue = 0

for i in range(n):
	while inp[i]>1:
		hashvalue ^= base[Index[inp[i]]]
		inp[i] = Next[inp[i]]
		pass
	ans += _map[hashvalue]
	_map[hashvalue] += 1;
	pass

print ans
