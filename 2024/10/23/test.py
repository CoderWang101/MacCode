# import matplotlib.pyplot as plt
# import numpy as np
# from scipy import stats

# # 设置字体为SimHei（黑体）或其他中文字体
# plt.rcParams['font.sans-serif'] = ['汉文宋体']  # 使用黑体
# plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# # 数据
# math_scores = [81, 90, 91, 74, 70, 73, 85, 60, 83, 81, 77, 60, 66, 84, 70, 54]
# stats_scores = [72, 90, 96, 68, 82, 78, 81, 71, 78, 94, 68, 66, 58, 87, 82, 46]

# # (1) 绘制散点图
# plt.scatter(math_scores, stats_scores)
# plt.xlabel('数学成绩')
# plt.ylabel('统计学成绩')
# plt.title('数学成绩与统计学成绩的关系')
# plt.grid(True)
# plt.show()

# # (2) 计算相关系数
# correlation = np.corrcoef(math_scores, stats_scores)[0, 1]
# print(f"l: {correlation:.2f}")

# # (3) 相关系数的显著性检验
# n = len(math_scores)
# t_statistic = correlation * np.sqrt((n-2) / (1-correlation**2))
# critical_value = stats.t.ppf(1-0.025, n-2)  # 双尾检验
# print(f"t统计量: {t_statistic:.2f}, 临界值: {critical_value:.2f}")
# if abs(t_statistic) > critical_value:
#     print("相关系数显著")
# else:
#     print("相关系数不显著")

# # (4) 拟合线性回归方程
# slope, intercept, r_value, p_value, std_err = stats.linregress(math_scores, stats_scores)
# print(f" y = {intercept:.2f} + {slope:.2f}x")

# # (5) 检验回归的显著性
# print(f"回归p值: {p_value:.5f}")
# if p_value < 0.05:
#     print("回归方程显著")
# else:
#     print("回归方程不显著")

# # (6) 预测区间
# confidence_interval = 0.95
# t_multiplier = stats.t.ppf((1 + confidence_interval) / 2, n - 2)
# predicted_value = intercept + slope * 80
# se_pred = std_err * np.sqrt(1 + 1/n + (80 - np.mean(math_scores))**2 / np.sum((math_scores - np.mean(math_scores))**2))
# interval = t_multiplier * se_pred
# print(f"预测区间: ({predicted_value - interval:.2f}, {predicted_value + interval:.2f})")