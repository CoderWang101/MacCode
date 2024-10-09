class Person:  # 定义一个人类
    role = 'person'  # 人物角色属性都是人

    def __init__(self, name, aggressivity, life_value):
        self.name = name  # 每一个角色都有自己的名称
        self.aggressivity = aggressivity  # 每一个角色都有自己的攻击力
        self.life_value = life_value  # 每一个角色都有自己的生命值

    def attack(self, dog):
        # 人可以打狗，这里的狗也是一个对象
        # 被人的攻击后，狗的生命值会根据人的攻击力而下降
        dog.life_value -= self.aggressivity


class Dog:  # 定义一个狗类
    role = 'dog'  # 狗物角色属性是狗

    def __init__(self, name, breed, aggressivity, life_value):
        self.name = name  # 每一只狗都有自己的昵称
        self.breed = breed  # 每一只狗都有自己的品种
        self.aggressivity = aggressivity  # 每一只狗都有自己的攻击力
        self.life_value = life_value  # 每一只狗都有自己的生命值

    def bite(self, someone):
        # 狗可以咬人，这里的某个人也是一个对象
        # 被狗的攻击后，人的生命值会根据狗的攻击力而下降
        someone.life_value -= self.aggressivity


egg = Person('egon', 10, 1000)  # 创建了一个实例化的人egg
ha2 = Dog('二哈', '哈士奇', 10, 1000)  # 创建了一只实例化的狗ha2

print(ha2.life_value)  # 查看ha2的生命值
egg.attack(ha2)  # egg打了ha2一下
print(ha2.life_value)  # ha2掉了10点血
ha2.bite(egg)  # ha2咬了egg
print(egg.life_value)  # egg掉了10点血