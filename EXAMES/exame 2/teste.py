a = []
for i in range(1,6):
    for j in range(1,6):
        if(i> j):
            a.append([i,j])

print(len(a))
for c in a:
    print(f"({c[0]}, {c[1]})", end=", ")