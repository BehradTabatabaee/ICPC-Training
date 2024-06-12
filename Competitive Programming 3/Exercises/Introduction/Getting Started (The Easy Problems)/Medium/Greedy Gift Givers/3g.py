given = 'given'
taken = 'taken'
mf = 0
while True:
    try:
        n = int(input())
        if mf != 0:
            print()
        friends = dict()
        names = input().split(' ')
        for i in range(n):
            friends[names[i]] = dict()
            friends[names[i]][given] = 0
            friends[names[i]][taken] = 0
        for _ in range(n):
            query = input().split(' ')
            num = int(query[2])
            mon = (int(query[1]) // num) if num != 0 else 0
            friends[query[0]][given] = (mon * num)
            while num > 0:
                friends[query[num + 2]][taken] += mon
                num -= 1
        for i in names:
            print(f'{i} {friends[i][taken] - friends[i][given]}')
        mf += 1
    except EOFError:
        break