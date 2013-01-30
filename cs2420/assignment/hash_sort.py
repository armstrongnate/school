# hash sort

# create a frequency chart

# data member to index

A = [5,4,2,6,4,2,3]
print A
F = []
for i in range(len(A)):
  F.append(0)
for n in A:
  F[n] += 1

i = 0
for n in range(len(F)):
  if F[n] > 0:
    for j in range(i, i+F[n]):
      A[j] = n
    i += F[n]

print A