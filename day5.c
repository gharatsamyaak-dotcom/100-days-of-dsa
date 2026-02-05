p = int(input())
log1 = list(map(int, input().split()))

q = int(input())
log2 = list(map(int, input().split()))

i = j = 0
merged_log = []

while i < p and j < q:
    if log1[i] <= log2[j]:
        merged_log.append(log1[i])
        i += 1
    else:
        merged_log.append(log2[j])
        j += 1

while i < p:
    merged_log.append(log1[i])
    i += 1

while j < q:
    merged_log.append(log2[j])
    j += 1

print(*merged_log)
