class Student:
    def __init__(self, name, age, scores):
        self.name = name  # 学生姓名
        self.age = age    # 学生年龄
        self.scores = scores  # 学生成绩，类型为list

    def get_name(self):
        return self.name

    def get_age(self):
        return self.age

    def get_max_score(self):
        if not self.scores:  # 如果成绩列表为空
            return 0
        highest = max(self.scores)  # 最高分
        return highest


# 示例使用
if __name__ == "__main__":
    student1 = Student("张三", 20, [85, 90, 78])
    student2 = Student("李四", 22, [88, 92, 95])
    
    # 输出学生信息和最高分
    highest1 = student1.get_max_score()  # 获取最高分
    print(f"{student1.get_name()} 的最高分: {highest1}")

    highest2 = student2.get_max_score()  # 获取最高分
    print(f"{student2.get_name()} 的最高分: {highest2}")