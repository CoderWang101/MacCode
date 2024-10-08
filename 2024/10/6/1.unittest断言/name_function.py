def get_formatted_name(first, last, middle=''):
    """生成整洁的姓名"""
    if middle:
        # 拼接包含中间名的完整姓名
        full_name = first + ' ' + middle + ' ' + last
    else:
        # 拼接不包含中间名的完整姓名
        full_name = first + ' ' + last
    # 将姓名的每个单词首字母大写，返回整洁的格式
    return full_name.title()