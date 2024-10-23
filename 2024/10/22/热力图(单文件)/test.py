import pandas as pd
import numpy as np

# DTW算法实现
def dtw(s, t):
    n, m = len(s), len(t)
    dtw_matrix = np.zeros((n + 1, m + 1))
    for i in range(n + 1):
        for j in range(m + 1):
            dtw_matrix[i, j] = np.inf
    dtw_matrix[0, 0] = 0

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            cost = abs(s[i - 1] - t[j - 1])
            dtw_matrix[i, j] = cost + min(dtw_matrix[i - 1, j], dtw_matrix[i, j - 1], dtw_matrix[i - 1, j - 1])

    return dtw_matrix

# 从excel文件中读取时间序列
def read_time_series_from_excel(file_name, start_col, end_col):
    # 读取Excel中的所有行，指定列范围为 start_col 到 end_col
    df = pd.read_excel(file_name, sheet_name='Sheet1')
    
    # 读取从 start_col 到 end_col 列的所有行数据
    time_series_U = df.iloc[:, start_col].values  # 读取第 1 列（即 start_col=0）
    time_series_V = df.iloc[:, end_col].values    # 读取第 2 列（即 end_col=1）
    
    return time_series_U, time_series_V

file_name = r'2024/10/22/test/6.xlsx'
time_series_U, time_series_V = read_time_series_from_excel(file_name, 0, 1)  # 读取第 1 列和第 2 列
print("Time Series U length:", len(time_series_U))
print(time_series_U)
print("Time Series V length:", len(time_series_V))
print(time_series_V)

# 计算DTW距离矩阵
distance_matrix = dtw(time_series_U, time_series_V)

# 打印DTW矩阵的大小
print("DTW Distance Matrix:", distance_matrix)