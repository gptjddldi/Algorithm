def find_friend(users:list)->list:
    """
    친구 찾기
    Time : O(N*K), K : 친구들 이름의 길이
    Space : O(N)
    """
    return [name for name in users if len(name)==4]

if __name__ == '__main__':
    users =  ["Ryan", "Kieran", "Mark"]
    print(find_friend(users))