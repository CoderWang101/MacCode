def find(arr,max,min):
    for i in arr:
        if max<i:
            max=i
        elif min>i:
            min=i
    return max,min
    


arr = [3, 6, 1, -4, 8, 0, 9, 8, -2, 15]
max=arr[0]
min=arr[0]

max_v , min_v=find(arr,max,min)
print(max_v,min_v)
