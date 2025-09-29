n = int(input())
t = 1
while (t < n) :         
    t *= 2

result = []
for _ in range(t):
    result.append(1)

k = int(t / 2)

for i in range(1,k) :
    if i % 2 == 1:
        result[i] = result[i - 1] + k
    else: result[i] = (result[0] + result[int(i / 2)]) / 2
    
for i in range(k,t):
    result[i] = result[int(i - t / 2)] + 1

for i in range(0,t):
    if (result[i] <= n):
        print (int(result[i]), end=" ")