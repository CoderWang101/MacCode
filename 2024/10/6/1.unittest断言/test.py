import unittest
from name_function import get_formatted_name

class NamesTestCase(unittest.TestCase):# unittest.TestCase 可以在这个类中编写测试方法，对函数和类的行为进行验证。
    """测试name_function.py"""

    def test_first_last_name(self):
        """能够正确地处理像Isaac Gauss这样的姓名吗?"""
        # 调用 get_formatted_name 函数，测试输入不带中间名的情况
        formatted_name = get_formatted_name('isaac', 'gauss')
        # 断言函数输出是否与预期结果一致
        self.assertEqual(formatted_name, 'Isaac Gauss')
    def test_first_middle_last_name(self):
        """能够正确地处理像Isaac Gauss这样的姓名吗?"""
        # 调用 get_formatted_name 函数，测试输入不带中间名的情况
        formatted_name = get_formatted_name('isaac','gauss', 'fuck')
        # 断言函数输出是否与预期结果一致
        self.assertEqual(formatted_name, 'Isaac Fuck Gauss')
 
# 自动运行测试
unittest.main()


# #%%
# print(5/0)
# # %%
# try:
#     print(5/0)
# except ZeroDivisionError:
#     print("error")    
    
# # %%
# try:
#     print(5/0)
# except ZeroDivisionError:
#     pass#跳过
    