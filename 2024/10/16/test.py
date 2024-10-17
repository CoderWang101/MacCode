def harmonic_number(n):
    if n == 1:
        return 1
    else:
        return harmonic_number(n - 1) + 1 / n

# 测试
n = 5
print("第{}个调和数为：{:.2f}".format(n, harmonic_number(n)))