import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import pandas as pd

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

# 从文件中读取时间序列的第二列
def read_time_series_from_file(file_name, row_range=None):
    if file_name.endswith('.csv'):
        df = pd.read_csv(file_name)
    elif file_name.endswith('.xlsx'):
        df = pd.read_excel(file_name, sheet_name='Sheet1')
    else:
        raise ValueError("Unsupported file format. Use either .csv or .xlsx")

    if row_range is not None:
        return df.iloc[row_range[0]:row_range[1], 1].values  # 读取第二列
    else:
        return df.iloc[:, 1].values  # 默认读取第二列

# 文件路径
file_name_U = '2024/10/22/热力图2(双文件)/1.csv'
file_name_V = '2024/10/22/热力图2(双文件)/2.csv'

# 读取时间序列U和V
time_series_U = read_time_series_from_file(file_name_U, row_range=(0, 1440))
time_series_V = read_time_series_from_file(file_name_V, row_range=(0, 1440))

print(len(time_series_U))
print(time_series_U)
print(len(time_series_V))
print(time_series_V)

print("Length of Time Series U:", len(time_series_U))
print("Length of Time Series V:", len(time_series_V))

# 计算DTW距离矩阵
distance_matrix = dtw(time_series_U, time_series_V)

# 创建布局
fig = plt.figure(figsize=(10, 10))
gs = gridspec.GridSpec(2, 2, width_ratios=[1, 4], height_ratios=[4, 1])

ax0 = plt.subplot(gs[0])
ax1 = plt.subplot(gs[1])
ax2 = plt.subplot(gs[3])

# 绘制时间序列V（垂直）
ax0.plot(time_series_V, range(len(time_series_V)), marker='x', color='orange')
ax0.set_title("Time Series V")
ax0.invert_yaxis()

# 绘制时间序列U（水平）
ax2.plot(time_series_U, marker='o')
ax2.set_title("Time Series U")

# 缩小热力图和热力图矩形框的大小
extent = [0, len(time_series_V), 0, len(time_series_U)]
cax = ax1.imshow(distance_matrix[1:, 1:], interpolation='nearest', origin='lower', aspect='auto', cmap='jet',
                 extent=extent, vmin=0, vmax=40000)
plt.colorbar(cax, ax=ax1, fraction=0.046, pad=0.04)

# 获取最佳路径
n, m = distance_matrix.shape
path = []
i, j = n - 1, m - 1
path.append((i, j))

# 修改此处的路径回溯逻辑
while i > 0 or j > 0:
    if i == 0:
        j -= 1
    elif j == 0:
        i -= 1
    else:
        min_neighbor = min(distance_matrix[i - 1, j - 1], distance_matrix[i - 1, j], distance_matrix[i, j - 1])
        if distance_matrix[i - 1, j - 1] == min_neighbor:
            i -= 1
            j -= 1
        elif distance_matrix[i - 1, j] == min_neighbor:
            i -= 1
        else:
            j -= 1
    path.append((i, j))

# 确保路径从(0, 0)开始
path.append((0, 0))

# 绘制路径
path = np.array(path)[::-1]
ax1.plot(path[:, 1], path[:, 0], color='black', linewidth=2)
ax1.set_title("DTW Distance Matrix")

# 调整布局
plt.tight_layout()
plt.show()