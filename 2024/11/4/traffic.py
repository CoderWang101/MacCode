import pandas as pd
import numpy as np
import seaborn as sns
import os
# %matplotlib inline
from IPython.display import display, HTML

import matplotlib.pyplot as plt
import matplotlib.pyplot as plotter
from sklearn.model_selection import cross_val_score
from sklearn import metrics
from sklearn.base import BaseEstimator, TransformerMixin, ClassifierMixin, clone
from sklearn.model_selection import KFold
from scipy import stats
from scipy.stats import norm, skew 
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, accuracy_score
from sklearn.feature_selection import SelectFromModel
from sklearn.metrics import classification_report
import warnings
warnings.filterwarnings('ignore')

train = pd.read_csv('Traffic.csv')

train, test = train_test_split(train,test_size=0.1,random_state=1992)
print("Shape of train: ",train.shape)
print("Shape of test",test.shape)

train.isnull().sum()
test.isnull().sum()

print('train')
display(train.info())

print('test')
display(test.info())

# train['Time'] = pd.to_datetime(train['Time']).dt.minute
# "step" 参数则指定了直方图的样式为阶梯图
sns.histplot(train, x="Time", hue="Traffic Situation", element="step")
# "bins"柱状格个数
sns.histplot(train, x="Date", hue="Traffic Situation", bins=31)

# 使用 Seaborn 的 catplot 创建计数图
sns.catplot(
    data=train,                  # 使用的数据集是 train
    x='Day of the week',         # X 轴表示一周中的天数
    hue='Traffic Situation',     # 根据交通情况分类并着色
    kind='count',                # 使用计数图类型
    palette='tab10',             # 选择调色板
    height=6,                    # 设置图的高度
    aspect=2                     # 设置宽高比
)

# 添加标题和标签
plt.title('Distribution of Traffic Situation by Day of the Week')  # 标题
plt.xlabel('Day of the Week')                                    # X 轴标签
plt.ylabel('Count')                                              # Y 轴标签
plt.xticks(rotation=45)                                          # 旋转 X 轴标签，以提高可读性
plt.legend(title='Traffic Situation')                            # 添加图例，并设置标题
plt.show()                                                       # 显示图

# 将 train DataFrame 赋值给 train_temp，以便进行操作
train_temp = train
# 导入 LabelEncoder 用于标签编码
from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()
# 将 'Time' 列中的分类值转换为数值编码
train_temp['Time'] = le.fit_transform(train_temp['Time'])
# 计算皮尔逊相关系数矩阵
corr = train_temp.corr(method='pearson')
# 创建一个图形和坐标轴对象
fig, ax = plt.subplots(figsize=(20, 20))
# 使用 Seaborn 的 heatmap 函数绘制相关系数矩阵的热力图
sns.heatmap(corr, cmap='RdBu', annot=True, fmt=".2f")
# 设置 X 轴和 Y 轴的标签
plt.xticks(range(len(corr.columns)), corr.columns)
plt.yticks(range(len(corr.columns)), corr.columns)
# 显示图
plt.show()
"""
1:  表示完全正相关,即一个变量增加时,另一个变量也线性增加。
0:  表示无相关性,即两个变量之间没有线性关系。
-1: 表示完全负相关,即一个变量增加时,另一个变量线性减少。
"""

# 导入必要的库和模块
from xgboost import XGBClassifier  # 导入 XGBoost 分类器
# 准备特征和目标变量
X_data_feature = train.drop(columns=['Traffic Situation'], axis=1)  # 从数据集中移除目标列 'Traffic Situation'，得到特征数据
y_data_feature = train['Traffic Situation']  # 提取目标列 'Traffic Situation'，得到目标数据
# 创建模型列表
model = [XGBClassifier()]  # 创建一个包含一个 XGBClassifier 实例的列表
# 训练模型
model = [model[i].fit(X_data_feature, y_data_feature) for i in range(len(model))]  # 使用列表推导式训练模型列表中的每一个模型
# 定义特征重要性显示的字符长度
num_chr = [12, 12, 10]  # 定义了模型名称显示的字符长度，但由于只有一个模型，实际上只有第一个值会被使用
# 打印特征重要性并绘制条形图
for i in range(len(model)):  # 遍历模型列表
    print(str(model[i])[:num_chr[i]] + ': \n', model[i].feature_importances_)  # 打印模型的名称（截取前 num_chr[i] 个字符）和特征重要性
    feat_importances = pd.Series(model[i].feature_importances_, index=X_data_feature.columns)  # 将模型的特征重要性转换为 pandas.Series，索引为特征列的名称
    feat_importances.nlargest(10).plot(kind='barh', color='royalblue')  # 选择前 10 个最重要的特征，并绘制水平条形图
    plt.xlim(0, 1.0)  # 设置 x 轴的范围为 0 到 1
    plt.show()  # 显示绘制的图表
"""展示哪些特征对模型的预测结果影响最大"""

# 假设 train 是你的训练数据 DataFrame
# 准备数据
X_data_feature = train.drop(columns=['Traffic Situation'], axis=1)  # 移除目标列，得到特征矩阵
y_data_feature = train['Traffic Situation']  # 提取目标列作为目标变量
# 创建并训练模型
model = [XGBClassifier()]  # 创建一个包含一个 XGBClassifier 实例的列表
model = [model[i].fit(X_data_feature, y_data_feature) for i in range(len(model))]  # 训练模型
# 定义特征重要性截断长度
num_chr = [12, 12, 10]  # 用于打印模型名称时截取的字符长度
# 打印特征重要性并绘制图形
for i in range(len(model)):  # 遍历模型列表
    print(str(model[i])[:num_chr[i]] + ': \n', model[i].feature_importances_)  # 打印模型名称和特征重要性
    feat_importances = pd.Series(model[i].feature_importances_, index=X_data_feature.columns)  # 将特征重要性转换为 Pandas Series
    feat_importances.nlargest(10).plot(kind='barh', color='royalblue')  # 绘制前 10 个最重要的特征的水平条形图
    plt.xlim(0, 1.0)  # 设置 x 轴的范围为 0 到 1
    plt.show()  # 显示图形

train = train.drop(columns=["Day of the week","Date"],axis=1) #axis沿着行方向进行操作
X= train.drop(columns=["Traffic Situation"],axis=1) #去除列
y= train["Traffic Situation"] #提取列

# 将数据集分为特征矩阵和目标变量
X_train = X  # 特征矩阵
y_train = y  # 目标变量

# 导入 StandardScaler 用于数据标准化
from sklearn.preprocessing import StandardScaler
# 创建 StandardScaler 实例
StandardScaler = StandardScaler()  
# 使用 StandardScaler 对特征矩阵 X_train 进行标准化处理，并返回标准化后的数据
X_train = StandardScaler.fit_transform(X_train)
# 将标准化后的数据重新转换为 DataFrame 格式
X_train = pd.DataFrame(X_train)
'''正态分布
标准化处理通过将数据转换为均值为0,标准差为1
消除了特征之间的尺度差异，从而提高了机器学习算法的性能和稳定性
'''

# 计算频率统计
counts = np.bincount(y_train)  # 计算 y_train 中每个类别的频率
# 定义标签
class_labels = ['1', '2', '3', '4']  # 定义类别标签的列表
labels = [class_labels[i] for i in range(len(counts))]  # 根据 counts 的长度，生成对应的标签列表
# 设置 Seaborn 样式
sns.set_style("whitegrid")  # 设置 Seaborn 的绘图样式为 "whitegrid"，即带有白色网格的背景
# 创建一个包含两个子图的画布
fig, axs = plt.subplots(1, 2, figsize=(14, 6))  # 创建一个包含两个子图的画布，宽度为 14 英寸，高度为 6 英寸
# 绘制饼图
axs[0].pie(
    counts,  # 频率统计结果
    labels=labels,  # 类别标签
    autopct='%1.1f%%',  # 显示百分比，保留一位小数
    startangle=90,  # 设置起始角度为 90 度
    colors=sns.color_palette('pastel', len(labels))  # 使用 Seaborn 的 pastel 调色板
)
centre_circle = plt.Circle((0, 0), 0.70, fc='white')  # 创建一个白色的中心圆
fig.gca().add_artist(centre_circle)  # 将中心圆添加到饼图中
axs[0].set_title('Pie Chart of y_train')  # 设置饼图的标题
axs[0].axis('equal')  # 确保饼图绘制为圆形
# 绘制柱状图
sns.barplot(x=labels, y=counts, palette='pastel', ax=axs[1])  # 使用 Seaborn 绘制柱状图
axs[1].set_title('Bar Plot of y_train')  # 设置柱状图的标题
axs[1].set_xlabel('Category')  # 设置 x 轴标签
axs[1].set_ylabel('Count')  # 设置 y 轴标签
# 调整布局
plt.tight_layout()  # 自动调整子图参数，使子图之间的间距合适
# 显示图形
plt.show()  # 显示图形
# 计算偏度和峰度
print("Skewness: %f" % y_train.skew())  # 打印 y_train 的偏度（skewness），用于衡量数据的偏斜程度
print("Kurtosis: %f" % y_train.kurt())  # 打印 y_train 的峰度（kurtosis），用于衡量数据的峰值和尾部厚度
# 两个图表示出了拥堵的情况,1-4表示拥堵情况
"""
正偏度(skewness > 0)数据分布偏向右侧，右侧有更多极端值。

负偏度(skewness < 0)数据分布偏向左侧，左侧有更多极端值。

零偏度(skewness = 0)数据分布对称，类似于正态分布。

正峰度(kurtosis > 0)数据分布的尾部更重,峰值更尖锐,称为“尖峰态”leptokurtic。

负峰度(kurtosis < 0)数据分布的尾部更轻,峰值更平缓,称为“低峰态”platykurtic。

零峰度(kurtosis = 0)数据分布的尾部和峰值类似于正态分布,称为“常峰态”mesokurtic。
峰度为零(kurtosis = 0)表示数据分布的峰值和尾部类似于正态分布。峰度不为零表示数据分布的峰值和尾部与正态分布不同
"""

from sklearn.model_selection import train_test_split
X_train, X_eval, y_train, y_eval = train_test_split(X_train, y_train,test_size=0.2,random_state=2019)
print("Shape of X_train: ",X_train.shape)
print("Shape of X_eval: ", X_eval.shape)
print("Shape of y_train: ",y_train.shape)
print("Shape of y_eval",y_eval.shape)

y_train =pd.DataFrame(y_train)
y_eval =pd.DataFrame(y_eval)
#转换为 Pandas DataFrame 格式

from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression,SGDClassifier,RidgeClassifier
from sklearn.ensemble import RandomForestClassifier,ExtraTreesClassifier,HistGradientBoostingClassifier,BaggingClassifier
from sklearn.ensemble import  AdaBoostClassifier, GradientBoostingClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.dummy import DummyClassifier
from sklearn.svm import SVC

from sklearn.ensemble import VotingClassifier
from lightgbm import LGBMClassifier
from catboost import CatBoostClassifier
clf1 = AdaBoostClassifier()
clf2 = SGDClassifier()
clf3 = XGBClassifier()
clf4 = RandomForestClassifier()
clf5 = ExtraTreesClassifier()
clf6 = CatBoostClassifier(logging_level='Silent')
clf7 = KNeighborsClassifier()
clf8 = LogisticRegression()
clf9=  RidgeClassifier()
clf10= HistGradientBoostingClassifier()
clf11= BaggingClassifier()
clf12= GradientBoostingClassifier()
clf13= GaussianNB()
clf14= LGBMClassifier()
clf15= DummyClassifier()
clf16= SVC()

eclf = VotingClassifier(estimators=[('ADA', clf1), ('SGD', clf2), ('XGB', clf3), ('RF', clf4), ('ET', clf5),('KN', clf7),
                                   ('LG', clf8), ('RC', clf9), ('HBC', clf10), ('BC', clf11), ('GBC', clf12), ('GNB', clf13), 
                                    ('DC', clf15),('SVC', clf16)],voting='hard')

for clf, label in zip([clf1,clf2,clf3,clf4,clf5,clf7,clf8,clf9,clf10,clf11,clf12,clf13,clf15,clf16], 
                      ['ADA', 'SGD','XGB','RF','ET','KN','LG','RC','HBC','BC','GBC','GNB','DC','SVC']):
    scores = cross_val_score(clf, X_train, y_train, scoring='accuracy', cv=5)
    print("Accuracy: %0.2f (+/- %0.2f) [%s]" % (scores.mean(), scores.std(), label))


class StackingAveragedModels(BaseEstimator, ClassifierMixin, TransformerMixin):
    def __init__(self, base_models, meta_model, n_folds=5):
        """
        初始化堆叠模型。

        参数:
        base_models (list): 基础模型列表，这些模型将用于第一层预测。
        meta_model (estimator): 元模型，用于根据基础模型的预测结果进行第二层预测。
        n_folds (int): K折交叉验证的折数,默认为5。
        """
        self.base_models = base_models
        self.meta_model = meta_model
        self.n_folds = n_folds

    def fit(self, X, y):
        """
        训练堆叠模型。

        参数:
        X (numpy array or pandas DataFrame): 特征矩阵。
        y (numpy array or pandas Series): 目标变量。

        返回:
        self
        """
        # 为每个基础模型创建一个空的列表，用于存储克隆后的模型实例
        self.base_models_ = [list() for x in self.base_models]
        # 克隆元模型，以便在训练过程中不改变原始模型
        self.meta_model_ = clone(self.meta_model)
        # 创建K折交叉验证对象
        kfold = KFold(n_splits=self.n_folds, shuffle=True, random_state=156)

        # 创建一个数组用于存储每个基础模型的预测结果
        out_of_fold_predictions = np.zeros((X.shape[0], len(self.base_models)))
        for i, model in enumerate(self.base_models):
            for train_index, holdout_index in kfold.split(X, y):
                # 克隆并训练基础模型
                instance = clone(model)
                self.base_models_[i].append(instance)
                instance.fit(X[train_index], y[train_index])
                # 对验证集进行预测并将结果存储
                y_pred = instance.predict(X[holdout_index])
                out_of_fold_predictions[holdout_index, i] = y_pred

        # 使用基础模型的预测结果作为特征，训练元模型
        self.meta_model_.fit(out_of_fold_predictions, y)
        return self

    def predict(self, X):
        """
        使用训练好的堆叠模型进行预测。

        参数:
        X (numpy array or pandas DataFrame): 特征矩阵。

        返回:
        numpy array: 预测结果。
        """
        # 计算每个基础模型的预测结果的平均值
        meta_features = np.column_stack([
            np.column_stack([model.predict(X) for model in base_models]).mean(axis=1)
            for base_models in self.base_models_ ])
        # 使用元模型进行最终预测
        return self.meta_model_.predict(meta_features)
    
