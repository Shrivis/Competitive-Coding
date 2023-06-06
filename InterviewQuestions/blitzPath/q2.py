
data = list(input().split(';'))
arr = list(map(int, data[0].split(',')))
print(arr[int(len(arr) - int(data[1]))])
