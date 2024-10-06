#%%1
a="寒雨连江夜入吴，平明送客楚山孤"
print(a)
print(a.encode()) #默认utf-8编码, 中文3个字节

f=open("/Users/white/Desktop/Code/c++/mac-code/2024/10/3/f.txt","w")
f.writelines(a)
f.close()
# %%
tf=open("/Users/white/Desktop/Code/c++/mac-code/2024/10/3/f.txt","rt") #"rt" 组合起来表示以文本形式读取文件的模式
print(tf.readline())# 读取文件的第一行。如果文件为空，则返回空字符串
tf.close()
# %%
# 使用 with 语句打开文件，这样可以确保文件会在读完后自动关闭
file_path = "/Users/white/Desktop/Code/c++/mac-code/2024/10/3/f.txt"

try:
    with open(file_path, "rb") as bf:  # 以二进制模式打开文件
        first_line = bf.readline()  # 读取第一行
        print(first_line.decode('utf-8'))  # 解码并打印第一行
except FileNotFoundError:
    print(f"文件未找到：{file_path}")  # 如果未找到文件，捕获异常并打印消息
except Exception as e:
    print(f"发生错误：{e}")  # 捕获其他异常并打印错误信息
# %%
