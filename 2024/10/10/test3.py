# 定义车辆类
class Vehicle:
    
    def drive(self):
        print("不,你不想走路\n")


# 轿车类
class Car(Vehicle):
    
    def drive(self):
        print("轿车正在行驶...\n")


# 摩托车类
class Motorcycle(Vehicle):
    
    def drive(self):
        print("摩托车正在行驶...\n")


class Person:
    
    def drive_vehicle(self, vehicle):
        vehicle.drive()


if __name__ == "__main__":
    my_foot=Vehicle()
    my_car = Car()
    my_motorcycle = Motorcycle()

    person = Person()

    print("选择 驾驶轿车:")
    person.drive_vehicle(my_car)  

    print("选择 驾驶摩托车:")
    person.drive_vehicle(my_motorcycle)  
    
    print("选择 走路:")
    person.drive_vehicle(my_foot)