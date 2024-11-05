# import pandas as pd
# import seaborn as sns
# import matplotlib.pyplot as plt

# # 示例数据
# data = {
#     'A': [1, 2, 3, 4, 5],
#     'B': [2, 3, 5, 6, 8],
#     'C': [5, 4, 3, 2, 1]
# }
# df = pd.DataFrame(data)

# # 计算皮尔逊相关系数矩阵
# corr_matrix = df.corr(method='pearson')

# # 可视化相关系数矩阵
# plt.figure(figsize=(8, 6))
# sns.heatmap(corr_matrix, annot=True, cmap='coolwarm', fmt=".2f")
# plt.title('Pearson Correlation Matrix')
# plt.show()
# """
# 1:  表示完全正相关,即一个变量增加时,另一个变量也线性增加。
# 0:  表示无相关性,即两个变量之间没有线性关系。
# -1: 表示完全负相关,即一个变量增加时,另一个变量线性减少。
# """


# # 导入必要的库
# from xgboost import XGBClassifier
# import matplotlib.pyplot as plt

# # 假设 train 是你的训练数据 DataFrame
# # 准备数据
# X_data_feature = train.drop(columns=['Traffic Situation'], axis=1)  # 移除目标列，得到特征矩阵
# y_data_feature = train['Traffic Situation']  # 提取目标列作为目标变量

# # 创建并训练模型
# model = [XGBClassifier()]  # 创建一个包含一个 XGBClassifier 实例的列表
# model = [model[i].fit(X_data_feature, y_data_feature) for i in range(len(model))]  # 训练模型

# # 定义特征重要性截断长度
# num_chr = [12, 12, 10]  # 用于打印模型名称时截取的字符长度

# # 打印特征重要性并绘制图形
# for i in range(len(model)):  # 遍历模型列表
#     print(str(model[i])[:num_chr[i]] + ': \n', model[i].feature_importances_)  # 打印模型名称和特征重要性
#     feat_importances = pd.Series(model[i].feature_importances_, index=X_data_feature.columns)  # 将特征重要性转换为 Pandas Series
#     feat_importances.nlargest(10).plot(kind='barh', color='royalblue')  # 绘制前 10 个最重要的特征的水平条形图
#     plt.xlim(0, 1.0)  # 设置 x 轴的范围为 0 到 1
#     plt.show()  # 显示图形

# import numpy as np
# import seaborn as sns
# import matplotlib.pyplot as plt
# from scipy.stats import kurtosis

# # 生成一个均匀分布的数据集
# data = np.random.uniform(low=0, high=10, size=1000)

# # 计算峰度
# kurt = kurtosis(data)
# print(f"Kurtosis: {kurt}")

# # 设置 Seaborn 样式
# sns.set_style("whitegrid")

# # 绘制直方图
# plt.figure(figsize=(10, 6))
# sns.histplot(data, kde=True, color='skyblue')

# # 添加标题和标签
# plt.title(f'Histogram of Uniform Distribution (Kurtosis: {kurt:.2f})')
# plt.xlabel('Value')
# plt.ylabel('Frequency')

# # 显示图形
# plt.show()






