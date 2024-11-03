def solve(values, weights, capacity):
    n = len(values)

    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w],
                               dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]

    # 在 dp 数组中找到最大价值
    max_value = dp[n][capacity]
    
    # 回溯查找具体物品组合
    w = capacity
    chosen_group = [0] * n
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:  
            chosen_group[i - 1] = 1
            w -= weights[i - 1]

    return max_value, chosen_group

values = [20, 15, 25]
weights = [10, 5, 15]
capacity = 20

max_value, chosen_group = solve(values, weights, capacity)
print("最大价值为:", max_value)
print("相关物品组合为:", chosen_group)