# # 定义一个函数substr，用于返回字符串s中从索引i到索引j的字符串
# def substr(s,i,j):
#     # 获取字符串s的长度
#     n=s.length
#     # 判断索引i和j是否有效
#     if i<1 or i>n or i+j>n+1:
#         print("i or j is invalid.")
#         return False
#     # 创建一个长度为j的字符串
#     sbs=String(j)
#     # 设置sbs的长度为j
#     sbs.length=j
#     # 遍历索引i到索引j+i的字符
#     for k in range(i,j+i):
#         # 将sbs中索引k-i的字符设置为s中索引k-1的字符
#         sbs.ch[k-i]=s.ch[k-1]
#     # 返回sbs
#     return sbs

s1='students'
s1='tea'
concat(substr(s1,4,4),substr(s1,1,length(s2)))