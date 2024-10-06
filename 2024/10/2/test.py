#%%1
print("{0:=^20}".format("PYTHON"))
print("{0:*>20}".format("BIT"))
print("{0:=^20}{1:*<20}".format("PYTHON", "BIT"))

print("{:-^10}".format("BIT"))
print("{0:,.2f}".format(12345.6789))
print("{0:b},{0:c},{0:d},{0:o},{0:x},{0:X}".format(425))
print("{0:e},{0:E},{0:f},{0:%}".format(3.14))

#%%2
#进度条
import time

scale=10
print("{0:-^20}".format("开始执行"),'\n')
for i in range(scale+1):
    a='*'*i
    b='.'*(scale-1)
    c=(i/scale)*100
    print("{:^3.0f}%[{}-->{}]".format(c,a,b))
    time.sleep(0.3)
print("{0:-^20}".format("结束执行"))

# %%3
import time

scale = 50  # 进度条的总宽度
print("执行开始".center(scale // 2, "-"))  # 打印开始信息

start = time.perf_counter()  # 记录开始时间

# 更新进度条
for i in range(scale + 1):
    a = "■" * i  # 已完成部分
    b = "□" * (scale - i)  # 未完成部分
    c = (i / scale) * 100  # 当前进度的百分比
    dur = time.perf_counter() - start  # 计算已经花费的时间

    # 使用 \r 在同一行更新输出
    print("\r当前进度: {:>3.0f}% | {}{} | {:.2f}s".format(c, a, b, dur), end="")
    time.sleep(0.1)  # 暂停0.1秒

print("\n" + "执行结束".center(scale // 2, "-"))  # 打印结束信息
# %%
