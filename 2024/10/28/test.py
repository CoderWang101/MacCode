def step_activation(x):
    return 1 if x > 0 else 0

W1 = [[0.3, 0.2],  # 权重矩阵从输入到隐藏层
      [0.4, 0.5]]
b1 = [0.1, 0.2]   # 隐藏层的偏置

W2 = [[0.6],      # 权重矩阵从隐藏层到输出层
      [0.7]]
b2 = [0.1]        # 输出层的偏置

# 输入数据
x = [1, 0]  # 假设输入 x1 = 1, x2 = 0

# 计算隐藏层
hidden_layer_input = [x[0]*W1[0][0] + x[1]*W1[0][1] + b1[0],  # 计算 h1 的输入
                     x[0]*W1[1][0] + x[1]*W1[1][1] + b1[1]]  # 计算 h2 的输入
hidden_layer_output = [step_activation(hidden_layer_input[0]),  # 激活函数应用于 h1
                      step_activation(hidden_layer_input[1])]  # 激活函数应用于 h2

# 计算输出层
output_layer_input = hidden_layer_output[0]*W2[0][0] + hidden_layer_output[1]*W2[1][0] + b2[0]
output = step_activation(output_layer_input)  # 激活函数应用于输出

# 输出结果
print("隐藏层输入:", hidden_layer_input)
print("隐藏层输出:", hidden_layer_output)
print("最终输出:", output)

'''
隐藏层输入：[0.4, 0.5] 是隐藏层的输入值。
隐藏层输出：[1, 1] 是经过阶跃激活函数后的隐藏层输出值。
最终输出:1 是经过第二个阶跃激活函数后的最终输出值。
'''