from collections import deque

def bfs(graph, start, end):
    visited = [False] * len(graph)
    parent = [-1] * len(graph)
    queue = deque([start])
    
    visited[start] = True

    while queue:
        node = queue.popleft()

        if node == end:
            break

        for i, connected in enumerate(graph[node]):
            if connected != 0 and not visited[i]:
                queue.append(i)
                visited[i] = True
                parent[i] = node

    if not visited[end]:
        print("没找到路")
        return

    path = []
    at = end
    while at != -1:
        path.append(at)
        at = parent[at]

    path.reverse()

    path_str = " -> ".join(f"V{v + 1}" for v in path)
    print(f"V1到V6最短路径为 : {path_str}")

def main():
    maze = [
        [0, 1, 0, 1, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [1, 0, 0, 1, 0, 1],
        [0, 0, 1, 0, 0, 1],
        [0, 0, 0, 1, 0, 0],
        [1, 0, 0, 0, 1, 0]
    ]

    bfs(maze, 0, 5)  # 从 V1 (索引0) 到 V6 (索引5)

if __name__ == "__main__":
    main()