class Rectangle:
    "用于计算矩形的面积和周长"
    role = "这是一个矩形"
    method = "计算面积和周长"

    #构造函数
    def __init__(self, width, height): 
        # 构造初始化方法，传入宽度和高度
        self.width = width
        self.height = height

    def get_area(self):
        return self.width * self.height

    def get_perimeter(self):
        return 2 * (self.width + self.height)


print(Rectangle.role)    # 属性查询
print(Rectangle.method)
print(Rectangle.get_area) #显示在内存中的位置 # 方法引用，注意这里不是调用，因为没有实例

rect_1 = Rectangle(3, 4)  # 实例化，rect_1 是一个对象
print("矩形的宽度为", rect_1.width)
print("矩形的周长", rect_1.get_perimeter())