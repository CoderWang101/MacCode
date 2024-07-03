import requests
from bs4 import BeautifulSoup
import pandas as pd

# 定义函数，根据传入的URL获取电影信息
def get_movie_info(url):
    # 设置请求头，模拟浏览器访问
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    response = requests.get(url, headers=headers)  # 发起请求
    soup = BeautifulSoup(response.text, 'html.parser')  # 使用BeautifulSoup解析HTML页面
    movies = []  # 存储电影信息的列表

    # 遍历每个电影条目
    for item in soup.find_all('div', class_='item'):
        rank = item.find('em').text
        detail_url = item.find('a')['href']
        image_url = item.find('img')['src']
        title = item.find('span', class_='title').text
        rating = item.find('span', class_='rating_num').text
        people = item.find('div', class_='star').find_all('span')[-1].text.strip('人评价')
        summary = item.find('span', class_='inq').text if item.find('span', class_='inq') else 'N/A'
        other_info = item.find('div', class_='bd').p.text.strip().replace('\n', ' ')

        # 将电影信息存储到movies列表中
        movies.append({
            '排名': rank,
            '详情链接': detail_url,
            '图片链接': image_url,
            '片名': title,
            '评分': rating,
            '评价人数': people,
            '概况': summary,
            '相关内容': other_info
        })

    return movies

# 主函数，用于获取豆瓣电影Top250的信息并保存到Excel文件中
def main():
    base_url = 'https://movie.douban.com/top250?start='
    all_movies = []  # 存储所有电影信息的列表

    # 循环获取每一页的电影信息
    for i in range(0, 250, 25):
        url = base_url + str(i)
        movies = get_movie_info(url)  # 获取当前页面的电影信息
        all_movies.extend(movies)  # 将当前页面的电影信息添加到总列表中
        print(f'已获取第 {i//25 + 1} 页数据')

    df = pd.DataFrame(all_movies)  # 将电影信息转换为DataFrame
    df.to_excel('豆瓣电影Top250.xlsx', index=False)  # 将DataFrame保存为Excel文件
    print('数据已保存到豆瓣电影Top250.xlsx文件中')

if __name__ == '__main__':
    main()