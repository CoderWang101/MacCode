import pandas as pd
import numpy as np
from datetime import datetime, timedelta

# 生成日期范围
start_date = datetime(2024, 1, 1)
end_date = datetime(2024, 12, 31)
date_range = pd.date_range(start_date, end_date)

# 准备数据存储
data = {
    "date": date_range,
    "meantemp": np.random.randint(15, 30, size=len(date_range)),
    "humidity": np.random.randint(50, 100, size=len(date_range)),
    "wind_speed": np.random.randint(1, 15, size=len(date_range)),
    "meanpressure": np.random.randint(1000, 1020, size=len(date_range)),
    "Day of the week": [date.strftime("%A") for date in date_range],
    "CarCount": np.random.randint(800, 1300, size=len(date_range)),
    "BikeCount": np.random.randint(150, 300, size=len(date_range)),
    "BusCount": np.random.randint(30, 100, size=len(date_range)),
    "TruckCount": np.random.randint(100, 250, size=len(date_range))
}

# 计算总数和交通状况
data["Total"] = data["CarCount"] + data["BikeCount"] + data["BusCount"] + data["TruckCount"]
conditions = [
    (data["Total"] < 1200),
    (data["Total"] >= 1200) & (data["Total"] < 1600),
    (data["Total"] >= 1600)
]
traffic_situation = ["Light", "Medium", "Heavy"]
data["Traffic Situation"] = np.select(conditions, traffic_situation)

# 创建数据帧
df = pd.DataFrame(data)

# 查看数据样例
print(df.head())

# 保存为CSV文件
df.to_csv("/Users/white/Desktop/Code/c++/mac-code/2024/11/4/traffic_data_2024.csv", index=False)