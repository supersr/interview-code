
def Matrix(n):
    a = []
    value = 1
    for b in range(n):
        c = [0 for i in range(n)]
        a.append(c)
    num = 0
    while num < (n+1)/2:
        j = num
        i = num
        if j == n - num - 1 and i == n - num - 1:
            a[i][j] = value
            value += 1
        while j < n - num - 1:
            a[i][j] = value
            value += 1
            j += 1
        while i < n - num - 1:
            a[i][j] = value
            value += 1
            i += 1
        while j > 0 + num:
            a[i][j] = value
            value += 1
            j -= 1
        while i > 0 + num:
            a[i][j] = value
            value += 1
            i -= 1
        num += 1
    return a
n = 5
a = Matrix(5)