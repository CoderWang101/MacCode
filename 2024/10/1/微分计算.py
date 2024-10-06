# import sys

# MAX_INT=sys.maxsize
# a=6;

# print(MAX_INT**a)
# ''' 
# 615656346818663737291362432329573325363859439854215515892590030606645220018700810278654093633374614700204645941249
# 以消耗内存换来无上限
# '''
from sympy import symbols, Rational, diff, integrate

# 定义符号
t, v0, g = symbols('t v0 g')

# 定义函数y，表示物体的高度
y = v0 * t - Rational(1, 2) * g * t**2

# 计算y对t的一阶导数
dydt = diff(y, t)
print(dydt)  # 输出结果是 v0 - g*t

# 计算y对t的二阶导数
dydt2 = diff(y, t, t)
print(dydt2)  # 输出结果是 -g

# 将dydt进行积分，注意这里传入的t为自变量，需要注意积分常数的处理
y2 = integrate(dydt, t)
print(y2)  # 这行实际上应该输出y的积分结果，可以加上常数C