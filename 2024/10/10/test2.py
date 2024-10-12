class Teacher:
    def __init__(self, name, age, gender, major):
        self.name = name  # 教师姓名
        self.age = age    # 教师年龄
        self.gender = gender  # 教师性别
        self.major = major    # 教师专业

    def get_name(self):
        return self.name
    
    def get_gender(self):
        return self.gender
    
    def get_major(self):
        return self.major

    def get_age(self):
        return self.age



class Tutor(Teacher):
    def teaching(self):
        print(f"{self.get_name()}的上课形式为{self.get_major()}")

# 示例使用

teacher = Teacher("张老师", 35, "男", "数学")
print(f"{teacher.get_name()}的上课形式为{teacher.get_major()}")


tutor = Tutor("李老师", 28, "女", "英语")
tutor.teaching()  # 输出: 李老师的上课形式为女